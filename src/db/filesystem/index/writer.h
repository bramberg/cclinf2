
#ifndef _MODELS_TREE_FILESYSTEM_XML_WRITER_H_
#define _MODELS_TREE_FILESYSTEM_XML_WRITER_H_

#include <QXmlStreamReader>

#include "db/filesystem/xml.h"
#include "record.h"
#include "utils/exception.h"

class IndexXmlWriter {
 public:
  static const QString kVersion;

  IndexXmlWriter();
  ~IndexXmlWriter();

  void WriteIndexToFile(const Record *records_tree, const QString &file_name);

 private:
  QXmlStreamWriter xml_;
  Record *records_tree_;

  void Write(const Record *&records_tree, QIODevice *device);

  void WriteRecordsTree(const Record *records_tree);

  void WriteVersion();
  void WriteSettings();
  void WriteRecord(const Record &record);
  void WriteNote(const Record::Note &note);
  void WriteAttachment(const Record::Attachment &attachment);
  void WriteTag(const QString &tag);
};

#endif
