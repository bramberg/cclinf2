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

class LinksListView : public QWidget {
 public:
  explicit LinksListView(QWidget* parent = 0);

  void SetupUi();
  void UpdateUi();
  void SetupSignals();
  void AddElement(const QString& text);
  //void DeleteElement();

 private:
  QVBoxLayout *layout_;
  QList<LinkView*> elements_;
  QToolButton *add_button_;
};

#endif  // ATTACHESVIEW_H
