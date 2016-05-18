#ifndef FILESYSTEMDATABASEREADER_H
#define FILESYSTEMDATABASEREADER_H

#include "db/database_reader.h"

class FileSystemDatabaseReader : public DatabaseReader {
 public:
  FileSystemDatabaseReader(const QString& path_to_database,
                           bool check_records_files = false);
  ~FileSystemDatabaseReader();
  virtual Record* ReadIndex();

 private:
  QString path_to_database_;
  bool check_records_files_;
};

#endif  // FILESYSTEMDATABASEREADER_H
