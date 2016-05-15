
#include "db/filesystem/index/writer.h"
#include "db/filesystem/index/common.h"
#include <QFile>
#include <QStack>
#include <QDebug>
#include "db/exceptions.h"

using namespace xml_names;

const QString IndexXmlWriter::kVersion = "1.0.1";

IndexXmlWriter::IndexXmlWriter() {}

IndexXmlWriter::~IndexXmlWriter() {}

void IndexXmlWriter::WriteIndexToFile(const Record *records_tree,
                                      const QString &file_name) {
  QFile xml_file(file_name);
  xml_file.open(QIODevice::WriteOnly);
  if (!xml_file.isOpen()) {
    throw exceptions::CouldNotOpenFileForWriting();
  }
  Write(records_tree, &xml_file);
  xml_file.close();
}

void IndexXmlWriter::WriteRecordsTree(const Record *records_tree) {
  QStack<const Record *> stack;
  stack.push(records_tree);
  xml_.writeStartElement(kRecordsTagName);
  while (!stack.isEmpty()) {
    const Record *current = stack.pop();
    for (int i = 0; i < current->GetNumberOfChildren(); ++i) {
      Record *child = current->GetChildAtRow(i);
      if (child) {
        WriteRecord(*child);
        stack.push(child);
      }
    }
  }
  xml_.writeEndElement();
}

void IndexXmlWriter::Write(const Record *&records_tree, QIODevice *device) {
  xml_.setDevice(device);
  xml_.setAutoFormatting(true);
  xml_.writeStartDocument();
  xml_.writeDTD("<!DOCTYPE cclinf-index>");
  xml_.writeStartElement(kIndexTagName);
  WriteVersion();
  WriteSettings();
  WriteRecordsTree(records_tree);
  xml_.writeEndElement();
  xml_.writeEndDocument();

  if (xml_.hasError()) {
    qDebug() << "ERROR " << __LINE__;
  }
}

void IndexXmlWriter::WriteVersion() {
  xml_.writeTextElement(kVersionTagName, kVersion);
}

void IndexXmlWriter::WriteSettings() {
  xml_.writeTextElement(kSettingsTagName, "");
}

void IndexXmlWriter::WriteTag(const QString &tag) {
  xml_.writeTextElement(kTagTagName, tag);
}

void IndexXmlWriter::WriteNote(const Record::Note &note) {
  xml_.writeStartElement(kNoteTagName);
  xml_.writeTextElement(kNameTagName, note.name);
  xml_.writeTextElement(kCreationTimeTagName,
                        note.creation_time.toString(kDateTimeFormat));
  xml_.writeTextElement(kFolderAttributeName, note.folder_name);
  xml_.writeEndElement();
}

void IndexXmlWriter::WriteAttachment(const Record::Attachment &attachment) {
  xml_.writeStartElement(kAttachmentTagName);
  xml_.writeTextElement(kNameTagName, attachment.name);
  xml_.writeTextElement(kCreationTimeTagName,
                        attachment.time_of_attach.toString(kDateTimeFormat));
  xml_.writeTextElement(kFileNameAttributeName, attachment.file_name);
  xml_.writeEndElement();
}

void IndexXmlWriter::WriteRecord(const Record &record) {
  xml_.writeStartElement(kRecordTagName);
  xml_.writeTextElement(kUuidTagName, record.GetUuid().toString());
  xml_.writeTextElement(kParentUuidTagName,
                        record.GetParent()->GetUuid().toString());
  xml_.writeTextElement(kNameTagName, record.GetName());
  xml_.writeTextElement(kCreationTimeTagName,
                        record.GetCreationDate().toString(kDateTimeFormat));
  if (!record.GetNotation().isEmpty()) {
    xml_.writeTextElement(kNotationTagName, record.GetNotation());
  }
  if (!record.GetNotes().isEmpty()) {
    xml_.writeStartElement(kNotesTagName);
    foreach (Record::Note note, record.GetNotes()) { WriteNote(note); }
    xml_.writeEndElement();
  }
  if (!record.GetTags().isEmpty()) {
    xml_.writeStartElement(kTagsTagName);
    foreach (QString tag, record.GetTags()) { WriteTag(tag); }
    xml_.writeEndElement();
  }
  if (!record.GetAttachments().isEmpty()) {
    xml_.writeStartElement(kAttachmentsTagName);
    foreach (Record::Attachment *attachment, record.GetAttachments()) {
      if (attachment) {
        WriteAttachment(*attachment);
      }
    }
    xml_.writeEndElement();
  }
  xml_.writeEndElement();
}
