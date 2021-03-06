
#ifndef RECORDVIEWER_H
#define RECORDVIEWER_H

#include <QWidget>
#include <QTabWidget>
#include <QList>
#include <QLayout>
#include <QScrollArea>
#include <QSplitter>

#include "editor/editor.h"
#include "record.h"
#include "links_list/links_list.h"
#include "title/record_title.h"
#include "dialogs/new_attachment_dialog.h"

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
  void AddNewAttach();

 private:
  Record *record_;

  QVBoxLayout *layout_;
  RecordTitle *title_;
  Editor *notes_editor_;

  QTabWidget *tab_widget_;  // TODO: custom tab widget
  QList<Editor *> notes_editors_;

  LinksListView *attachments_list_;
  QScrollArea *scroll_area_;
  QSplitter *splitter_;
};

#endif  // RECORDVIEWER_H
