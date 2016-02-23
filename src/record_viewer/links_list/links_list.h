#ifndef ATTACHESVIEW1_H
#define ATTACHESVIEW1_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QList>
#include <QLayout>
#include <QPushButton>

#include "link_view.h"
#include "vertical_scroll_area.h"
#include "record.h"

class LinksListView : public QWidget {
  Q_OBJECT
 public:
  explicit LinksListView(QWidget* parent = 0);

  void SetupUi();
  void SetupSignals();
  void AddElement(const QString& text);
  void Update();
// void DeleteElement();

signals:
  void AddButtonWasPressed(bool is_pressed);

 private:
  QList<Record::Attachment*> *attachments_;
  QList<LinkView*> elements_;
  QVBoxLayout* layout_;
  QToolButton* add_button_;
};

#endif  // ATTACHESVIEW_H
