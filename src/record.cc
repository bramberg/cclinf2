
#include "record.h"

Record::Record(Record *parent)
    : parent_(parent), name_("<NOT_SET>"), has_no_parent_(false) {}

Record::Record(const QUuid uuid, Record *parent)
    : uuid_(uuid), parent_(parent) {}

Record::Record(const QUuid uuid, const QString name, Record *parent)
    : uuid_(uuid), parent_(parent), name_(name), has_no_parent_(false) {}

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

QList<Record::Attachment *> Record::GetAttachments() const {
  return attachments_;
}

void Record::SetAttachments(QList<Record::Attachment *> attachments) {
  attachments_ = attachments;
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

void Record::AddAttachment(Record::Attachment *attachment) {
  attachments_.append(attachment);
}

void Record::AddNote(const Record::Note &note) { notes_.append(note); }

void Record::AddTag(const QString &tag) { tags_.append(tag); }

QUuid Record::GetUuid() const { return uuid_; }

void Record::SetUuid(const QUuid &uuid) { uuid_ = uuid; }

bool Record::HasNoParent() { return has_no_parent_; }

void Record::SetNoParent(bool has_no_parent) { has_no_parent_ = has_no_parent; }

void Record::SortChildren() {
  std::sort(children_.begin(), children_.end(), Record::Comparator());
  foreach (Record *child, children_) { child->SortChildren(); }
}

int Record::GetNumberOfNotes() const { return notes_.size(); }
