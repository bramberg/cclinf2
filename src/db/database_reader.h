
#ifndef DATABASEREADER_H
#define DATABASEREADER_H

#include <record.h>

class DatabaseReader {
 public:
  DatabaseReader() {}
  virtual Record* ReadIndex() = 0;
};

#endif  // DATABASEREADER_H
