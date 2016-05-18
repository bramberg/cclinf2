
#ifndef DATABASEWRITER_H
#define DATABASEWRITER_H

#include <record.h>

class DatabaseWriter {
 public:
  DatabaseWriter() {}
  virtual Record* WriteIndex() = 0;
};

#endif  // DATABASEWRITER_H
