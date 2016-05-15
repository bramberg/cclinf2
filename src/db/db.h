
#ifndef _MODELS_DB_DB_H_
#define _MODELS_DB_DB_H_

#include <QString>
#include "record.h"

class Database {
public:


  void Read(DatabaseReader& reader);


private:
  QString path_to_database_;
  Record *records_tree_;

};

#endif
