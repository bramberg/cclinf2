
#ifndef _MODELS_DB_DB_H_
#define _MODELS_DB_DB_H_

#include <QString>
#include "record.h"
#include "db/database_reader.h"
#include "db/database_writer.h"
#include "db/exceptions.h"

class Database {
public:

  Database();
  ~Database();

  void Read(DatabaseReader& reader);
  void Write(DatabaseWriter& writer);

  Record *GetRecordsTree() const;
  void SetRecordsTree(Record *records_tree);

private:
  Record *records_tree_;

};

#endif
