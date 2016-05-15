
#include "database_reader.h"
#include "db/filesystem/index/reader.h"

FileSystemDatabaseReader::FileSystemDatabaseReader(
    const QString& path_to_database, bool touch_records) {
  this->path_to_database_ = path_to_database;
  this->touch_records_ = touch_records;
}

Record* FileSystemDatabaseReader::ReadIndex() {
  Record* records_index;
  records_index = IndexXmlReader().ReadRecordsFromFile(this->path_to_database_ +
                                                       "/index.xml");
  return records_index;
}
