
#ifndef LISTOFATTACHES_H
#define LISTOFATTACHES_H

#include <QSplitter>
#include <QLayout>
#include <QLabel>
#include <QScrollArea>
#include <QAbstractItemView>
#include <QApplication>
#include <QScrollBar>
#include <QListView>
/*
class ListOfAttachesView : public QAbstractItemView {
  Q_OBJECT

 public:
  ListOfAttachesView(QWidget *parent = 0);

  virtual void setModel(QAbstractItemModel *model);

  void calculateRectsIfNecessary() const;

  void SetupUI();

private:
  mutable int ideal_width;
  mutable int ideal_height;
  mutable QHash<int, QRectF> rect_for_row;
  mutable bool hash_is_dirty;

  QScrollArea *scroll_;
  QGridLayout *grid_;
  QList<QLabel *> labels_;
};
/**/
#endif  // LISTOFATTACHES_H
