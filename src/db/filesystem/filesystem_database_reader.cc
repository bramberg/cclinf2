
#include "db/filesystem/database_reader.h"
#include "db/filesystem/index/reader.h"

FileSystemDatabaseReader::FileSystemDatabaseReader(
    const QString& path_to_database, bool check_records_files) {
  this->path_to_database_ = path_to_database;
  this->check_records_files_ = check_records_files;
}

FileSystemDatabaseReader::~FileSystemDatabaseReader() {}

Record* FileSystemDatabaseReader::ReadIndex() {
  Record* records_index;
  records_index = IndexXmlReader().ReadRecordsFromFile(this->path_to_database_ +
                                                       "/index.xml");
  return records_index;
}
