
#include "db/filesystem/index/reader.h"
#include "db/filesystem/index/common.h"
#include <QFile>
#include <QStack>
#include <QDebug>

using namespace xml_names;

const QString IndexXmlReader::kVersion = "1.0.1";

IndexXmlReader::IndexXmlReader() {}

IndexXmlReader::~IndexXmlReader() {
  foreach (Record *record, records_hash_) { delete record; }
  records_hash_.clear();
}

Record *IndexXmlReader::ReadRecordsFromFile(const QString &file_name) {
  QFile xml_file(file_name);
  xml_file.open(QIODevice::ReadOnly);
  if (!xml_file.isOpen()) {
    throw CouldNotOpenFile();
  }
  Read(&xml_file);
  xml_file.close();
  Record *record_tree = CreateTreeFromHash();
  qDebug() << "checkpoint " << records_hash_.size();
  return record_tree;
}

void LinkParentAndChild(Record *parent, Record *child) {
  child->SetParent(parent);
  parent->AppendChild(child);
}

Record *IndexXmlReader::FindInHashByUuid(const QUuid &uuid) {
  Record *item = nullptr;
  QHash<QUuid, Record *>::iterator it = records_hash_.find(uuid);
  if (it != records_hash_.end()) {
    item = it.value();
  }
  return item;
}

Record *IndexXmlReader::CreateTreeFromHash() {
  Record *root = new Record("Root");
  const QUuid root_uuid = QUuid(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  foreach (Record *record, records_hash_) {
    if (record->GetParentUuid() == root_uuid) {
      LinkParentAndChild(root, record);
    } else if (record->GetParentUuid() == record->GetUuid()) {
      LinkParentAndChild(root, record);
      record->SetUnattached(true);
    } else {
      Record *parent = FindInHashByUuid(record->GetParentUuid());
      if (!parent) {
        LinkParentAndChild(root, record);
        record->SetUnattached(true);
      } else {
        LinkParentAndChild(parent, record);
      }
    }
  }
  records_hash_.clear();
  root->SortChildren();
  return root;
}

void IndexXmlReader::ReadArray(const QString &array_name,
                               const QString &element_name,
                               void (IndexXmlReader::*ReadFunction)()) {
  if (xml_.isStartElement() && xml_.name() == array_name) {
    while (QXmlStreamReader::TokenType token = xml_.readNext()) {
      // qDebug() << "loop";
      if (token == QXmlStreamReader::StartElement) {
        if (xml_.name() == element_name) {
          (this->*ReadFunction)();
        } else {
          qDebug() << "WARNING: unexpected tag \"" << xml_.name()
                   << "\" on line " << xml_.lineNumber();
        }
      } else if (token == QXmlStreamReader::EndElement) {
        if (xml_.name() == element_name) {
          continue;
        } else if (xml_.name() == array_name) {
          break;
        }
      } else if (token == QXmlStreamReader::EndDocument) {
        throw ParsingError(
            QString("Exception on line %1. Unexpected end of file.")
                .arg(__LINE__));
      }
    }
  }
}

void IndexXmlReader::Read(QIODevice *device) {
  records_hash_.clear();
  xml_.setDevice(device);
  xml_.readNextStartElement();

  if (xml_.name() == kIndexTagName) {
    ReadIndex();
  } else {
    qDebug() << "ERROR " << __LINE__;
    qDebug() << "checkpoint " << xml_.name();
    xml_.raiseError();
  }

  qDebug() << "checkpoint " << __LINE__;

  // readNextStartElement() leaves the stream in
  // an invalid state at the end. A single readNext()
  // will advance us to EndDocument.
  if (xml_.tokenType() == QXmlStreamReader::Invalid) {
    xml_.readNext();
  }

  qDebug() << "checkpoint " << __LINE__;

  if (xml_.hasError()) {
    qDebug() << "ERROR " << __LINE__;
  }
}

void IndexXmlReader::ReadIndex() {
  if (xml_.isStartElement() && xml_.name() == xml_names::kIndexTagName) {
    while (QXmlStreamReader::TokenType token = xml_.readNext()) {
      if (token == QXmlStreamReader::StartElement) {
        if (xml_.name() == kVersionTagName) {
          ReadVersion();
        } else if (xml_.name() == kSettingsTagName) {
          ReadSettings();
        } else if (xml_.name() == kRecordsTagName) {
          ReadArray(kRecordsTagName, kRecordTagName,
                    &IndexXmlReader::ReadRecord);
        } else {
          qDebug() << "WARNING: unexpected tag " << xml_.name() << " on line "
                   << xml_.lineNumber();
        }
      } else if (token == QXmlStreamReader::EndElement) {
        if (xml_.name() == kIndexTagName) {
          break;
        } else {
          throw ParsingError(
              QString(
                  "Exception on line %1. Unexpected end-token in xml file: ")
                  .arg(xml_.lineNumber()) +
              xml_.name().toString());
        }
      } else if (token == QXmlStreamReader::EndDocument) {
        throw ParsingError(
            QString("Exception on line %1. Unexpected end of file.")
                .arg(xml_.lineNumber()));
      }
    }
  }
}

QString IndexXmlReader::ReadVersion() {
  QString version;
  if (xml_.isStartElement() && xml_.name() == kVersionTagName) {
    version = xml_.readElementText();
  }
  return version;
}

void IndexXmlReader::ReadSettingsContent() { xml_.readElementText(); }

void IndexXmlReader::ReadSettingsAttributes() {}

void IndexXmlReader::ReadSettings() {
  if (xml_.isStartElement() && xml_.name() == kSettingsTagName) {
    ReadSettingsAttributes();
    ReadSettingsContent();
  }
}

void IndexXmlReader::ReadTag() {
  if (xml_.isStartElement() && xml_.name() == kTagTagName) {
    current_record_->AddTag(xml_.readElementText());
  }
}

void IndexXmlReader::ReadNote() {
  if (xml_.isStartElement() && xml_.name() == kNoteTagName) {
    Record::Note note;
    while (xml_.readNextStartElement()) {
      if (xml_.name() == kNameTagName) {
        note.name = xml_.readElementText();
      } else if (xml_.name() == kFolderAttributeName) {
        note.folder_name = xml_.readElementText();
      } else if (xml_.name() == kCreationTimeTagName) {
        note.creation_time =
            QDateTime::fromString(xml_.readElementText(), kDateTimeFormat);
      }
    }
    if (!note.folder_name.isEmpty() && !note.name.isEmpty()) {
      current_record_->AddNote(note);
    }
  }
}

void IndexXmlReader::ReadAttach() {
  if (xml_.isStartElement() && xml_.name() == kAttachTagName) {
    Record::Attach attach;
    while (xml_.readNextStartElement()) {
      if (xml_.name() == kNameTagName) {
        attach.name = xml_.readElementText();
      } else if (xml_.name() == kFileNameAttributeName) {
        attach.file_name = xml_.readElementText();
      } else if (xml_.name() == kCreationTimeTagName) {
        attach.time_of_attach =
            QDateTime::fromString(xml_.readElementText(), kDateTimeFormat);
      }
    }
    if (!attach.file_name.isEmpty() && !attach.name.isEmpty()) {
      current_record_->AddAttach(attach);
    }
  }
}

void IndexXmlReader::ReadRecord() {
  if (xml_.isStartElement() && xml_.name() == kRecordTagName) {
    qDebug() << "checkpoint " << __LINE__;
    current_record_ = new Record();
    while (xml_.readNextStartElement()) {
      if (xml_.name() == kUuidTagName) {
        current_record_->SetUuid(xml_.readElementText());
      } else if (xml_.name() == kParentUuidTagName) {
        current_record_->SetParentUuid(xml_.readElementText());
      } else if (xml_.name() == kNameTagName) {
        current_record_->SetName(xml_.readElementText());
      } else if (xml_.name() == kCreationTimeTagName) {
        current_record_->SetCreationTime(
            QDateTime::fromString(xml_.readElementText(), kDateTimeFormat));
      } else if (xml_.name() == kNotationTagName) {
        current_record_->SetNotation(xml_.readElementText());
      } else if (xml_.name() == kTagsTagName) {
        ReadArray(kTagsTagName, kTagTagName, &IndexXmlReader::ReadTag);
      } else if (xml_.name() == kAttachesTagName) {
        ReadArray(kAttachesTagName, kAttachTagName,
                  &IndexXmlReader::ReadAttach);
      } else if (xml_.name() == kNotesTagName) {
        ReadArray(kNotesTagName, kNoteTagName, &IndexXmlReader::ReadNote);
      }
    }
    if (!records_hash_.contains(current_record_->GetUuid())) {
      records_hash_.insert(current_record_->GetUuid(), current_record_);
    } else {
      delete current_record_;
    }
    current_record_ = nullptr;
  }
}
