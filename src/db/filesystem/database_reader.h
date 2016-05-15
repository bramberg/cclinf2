#ifndef FILESYSTEMDATABASEREADER_H
#define FILESYSTEMDATABASEREADER_H

#include "db/database_reader.h"

class FileSystemDatabaseReader : public DatabaseReader {
 public:
  FileSystemDatabaseReader(const QString& path_to_database,
                           bool touch_records = false);
  virtual Record* ReadIndex();

 private:
  QString path_to_database_;
  bool touch_records_;
};

#endif  // FILESYSTEMDATABASEREADER_H
