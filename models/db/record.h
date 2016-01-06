
#ifndef _MODELS_TREE_TREE_ITEM_H_
#define _MODELS_TREE_TREE_ITEM_H_

#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QUuid>

class Record {
 public:
  struct Note {
    QString name;
    QString folder_name;
    QDateTime creation_time;
  };

  struct Attach {
    QString name;
    QString file_name;
    QDateTime time_of_attach;
  };

  struct Comparator {
    bool operator()(const Record *r1, const Record *r2) const {
      bool less_than = false;
      if (r1->notation_ != r2->notation_) {
        less_than = r1->notation_ < r2->notation_;
      } else {
        less_than = r1->name_ < r2->name_;
      }
      return less_than;
    }
  };

  explicit Record(Record *parent = 0)
      : parent_(parent), name_("<NOT_SET>"), is_unattached_(false) {}
  explicit Record(const QString name, Record *parent = 0)
      : name_(name), parent_(parent), is_unattached_(false) {}
  ~Record();

  void AppendChild(Record *child);
  int GetNumberOfChildren() const;

  int GetRow() const;
  Record *GetChildAtRow(int row) const;

  Record *GetParent() const;
  void SetParent(Record *parent);

  QList<Record::Note> GetNotes() const;
  void SetNotes(const QList<Record::Note> &text_files);

  QList<Record::Attach> GetAttaches() const;
  void SetAttaches(const QList<Record::Attach> &attached_files);

  QStringList GetTags() const;
  void SetTagList(const QStringList &tags);

  QString GetName() const;
  void SetName(const QString &GetName);

  QString GetNotation() const;
  void SetNotation(const QString &GetNotation);

  QDateTime GetCreationDate() const;
  void SetCreationTime(const QDateTime &date);

  void AddAttach(const Attach &attach);
  void AddNote(const Note &note);
  void AddTag(const QString &tag);
  void AddChildUuid(const QUuid &uuid);

  QUuid GetUuid() const;
  void SetUuid(const QUuid &uuid);

  QUuid GetParentUuid() const;
  void SetParentUuid(const QUuid &parent_uuid);

  bool IsUnattached();
  void SetUnattached(bool is_unattached);

  void SortChildren();

 private:
  QList<Record *> children_;
  Record *parent_;

  QUuid uuid_;
  QUuid parent_uuid_;
  QList<QUuid> children_uuids_;

  QString name_;
  QDateTime creation_time_;
  QString notation_;

  QList<Note> notes_;
  QList<Attach> attaches_;
  QStringList tags_;

  bool is_unattached_;
};

#endif
