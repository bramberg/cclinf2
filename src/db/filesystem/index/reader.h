
#ifndef _MODELS_TREE_FILESYSTEM_XML_READER_H_
#define _MODELS_TREE_FILESYSTEM_XML_READER_H_

#include <QHash>
#include <QXmlStreamReader>
#include "db/filesystem/xml.h"
#include "record.h"
#include "utils/exception.h"

class IndexXmlReader /*: public XmlParser*/ {
 public:
  IndexXmlReader();
  ~IndexXmlReader();

  static const QString kVersion;

  Record *ReadRecordsFromFile(const QString &file_name);

 private:
  typedef void(*ReadFunction());
  typedef QPair<QUuid, Record *> RecordsPair;

  QXmlStreamReader xml_;
  Record *current_record_;
  QHash<QUuid, QPair<QUuid, Record *> > records_hash_;

  void Read(QIODevice *device);
  void ReadArray(const QString &array_name, const QString &element_name,
                 void (IndexXmlReader::*ReadFunction)());
  void ReadIndex();

  QString ReadVersion();

  void ReadSettings();
  void ReadSettingsAttributes();
  void ReadSettingsContent();

  void ReadRecord();
  void ReadRecordAttributes();
  void ReadRecordContent();

  void ReadTagAttributes(QString &tag);
  void ReadTagContent(QString &tag);
  void ReadTag();

  void ReadChild();

  Record *CreateTreeFromHash();
  void SortRecordsTree(Record *tree);
  Record *FindInHashByUuid(const QUuid &uuid);

  void ReadNoteAttributes(Record::Note &note);
  void ReadNoteContent(Record::Note &note);
  void ReadNote();
  void ReadAttachment();
};

#endif
