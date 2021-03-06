
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

  struct Attachment {
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

  explicit Record(Record *parent = 0);
  explicit Record(const QUuid uuid, Record *parent = 0);
  explicit Record(const QUuid uuid, const QString name, Record *parent = 0);
  ~Record();

  void AppendChild(Record *child);
  int GetNumberOfChildren() const;

  int GetRow() const;
  Record *GetChildAtRow(int row) const;

  Record *GetParent() const;
  void SetParent(Record *parent);

  QList<Record::Note> GetNotes() const;
  void SetNotes(const QList<Record::Note> &text_files);

  int GetNumberOfNotes() const;

  QList<Attachment *> GetAttachments() const;
  void SetAttachments(QList<Record::Attachment *> attachments);

  QStringList GetTags() const;
  void SetTagList(const QStringList &tags);

  QString GetName() const;
  void SetName(const QString &GetName);

  QString GetNotation() const;
  void SetNotation(const QString &GetNotation);

  QDateTime GetCreationDate() const;
  void SetCreationTime(const QDateTime &date);

  void AddAttachment(Attachment *attachment);
  void AddNote(const Note &note);
  void AddTag(const QString &tag);

  QUuid GetUuid() const;
  void SetUuid(const QUuid &uuid);

  bool HasNoParent();
  void SetNoParent(bool has_no_parent);

  void SortChildren();

 private:
  QList<Record *> children_;
  Record *parent_;

  QUuid uuid_;

  QString name_;
  QDateTime creation_time_;
  QString notation_;

  QList<Note> notes_;
  QList<Attachment *> attachments_;
  QStringList tags_;

  bool has_no_parent_;
};

#endif
