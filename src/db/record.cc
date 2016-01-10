
#include "db/record.h"

// Record::Record(Record *parent) {
//  // name_ = "<NOT SET>";
//  parent_ = parent;
//}

// Record::Record(const QString name, Record *parent) {
//  name_ = name;
//  parent_ = parent;
//}

Record::~Record() { qDeleteAll(children_); }

void Record::AppendChild(Record *child) { children_.append(child); }

Record *Record::GetChildAtRow(int row) const {
  return (row < children_.size() && row >= 0) ? children_.value(row) : nullptr;
}

int Record::GetNumberOfChildren() const { return children_.count(); }

int Record::GetRow() const {
  int row = 0;
  if (parent_) {
    row = 1 + parent_->GetRow() +
          parent_->children_.indexOf(const_cast<Record *>(this));
  }
  return row;
}

Record *Record::GetParent() const { return parent_; }

void Record::SetParent(Record *parent) { parent_ = parent; }

QList<Record::Attach> Record::GetAttaches() const { return attaches_; }

void Record::SetAttaches(const QList<Record::Attach> &attached_files) {
  attaches_ = attached_files;
}

QList<Record::Note> Record::GetNotes() const { return notes_; }

void Record::SetNotes(const QList<Record::Note> &text_files) {
  notes_ = text_files;
}
QStringList Record::GetTags() const { return tags_; }

void Record::SetTagList(const QStringList &tags) { tags_ = tags; }
QString Record::GetName() const { return name_; }

void Record::SetName(const QString &name) { name_ = name; }

QString Record::GetNotation() const { return notation_; }
void Record::SetNotation(const QString &notation) { notation_ = notation; }

QDateTime Record::GetCreationDate() const { return creation_time_; }

void Record::SetCreationTime(const QDateTime &date) { creation_time_ = date; }

void Record::AddAttach(const Record::Attach &attach) {
  attaches_.append(attach);
}

void Record::AddNote(const Record::Note &note) { notes_.append(note); }

void Record::AddTag(const QString &tag) { tags_.append(tag); }

void Record::AddChildUuid(const QUuid &uuid) { children_uuids_.append(uuid); }

QUuid Record::GetUuid() const { return uuid_; }

void Record::SetUuid(const QUuid &uuid) { uuid_ = uuid; }

QUuid Record::GetParentUuid() const { return parent_uuid_; }

void Record::SetParentUuid(const QUuid &parent_uuid) {
  parent_uuid_ = parent_uuid;
}

bool Record::IsUnattached() { return is_unattached_; }

void Record::SetUnattached(bool is_unattached) {
  is_unattached_ = is_unattached;
}

void Record::SortChildren() {
  std::sort(children_.begin(), children_.end(), Record::Comparator());
  foreach (Record *child, children_) { child->SortChildren(); }
}

int Record::GetNumberOfNotes() const { return notes_.size(); }
