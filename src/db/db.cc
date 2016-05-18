
#include "db/db.h"

Database::Database() { this->records_tree_ = nullptr; }

void Database::Read(DatabaseReader &reader) {
  this->records_tree_ = reader.ReadIndex();
}

Record *Database::GetRecordsTree() const { return this->records_tree_; }

void Database::SetRecordsTree(Record *records_tree) {
  this->records_tree_ = records_tree;
}
