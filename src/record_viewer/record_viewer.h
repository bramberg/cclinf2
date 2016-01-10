
#ifndef RECORDVIEWER_H
#define RECORDVIEWER_H

#include <QWidget>
#include <QTabWidget>
#include <QList>
#include <QLayout>

#include "editor/editor.h"
#include "db/record.h"
#include "links_list/links_list.h"

class RecordViewer : public QWidget {
  Q_OBJECT
 public:
  explicit RecordViewer(QWidget *parent = 0);
  explicit RecordViewer(Record *record, QWidget *parent = 0);
  ~RecordViewer();

  void SetupUi();
  void SetupSignals();

  void UpdateUi();

  void SetRecord(Record *record);

signals:

 public slots:

 private:
  QVBoxLayout *layout_;

  Record *record_;

  QTabWidget *tab_widget_;  // TODO: custom tab widget
  QList<Editor *> notes_editors_;

  Editor *notes_editor_;
  LinksListView *links_list_;
};

#endif  // RECORDVIEWER_H
