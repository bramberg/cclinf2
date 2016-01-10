#ifndef VERTICALSCROLLAREA_H
#define VERTICALSCROLLAREA_H

#include <QWidget>
#include <QEvent>
#include <QScrollBar>
#include <QScrollArea>

class VerticalScrollArea : public QScrollArea {
  Q_OBJECT
 public:
  explicit VerticalScrollArea(QWidget *parent = 0);

  virtual bool eventFilter(QObject *object, QEvent *event);
};

#endif  // VERTICALSCROLLAREA_H
