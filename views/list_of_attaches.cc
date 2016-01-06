
#include "list_of_attaches.h"
/*
ListOfAttachesView::ListOfAttachesView(QWidget *parent)
    : QAbstractItemView(parent),
      ideal_width(0),
      ideal_height(0),
      hash_is_dirty(false) {
  setFocusPolicy(Qt::WheelFocus);
  setFont(QApplication::font("QListView"));
  horizontalScrollBar()->setRange(0, 0);
  verticalScrollBar()->setRange(0, 0);
}

void ListOfAttachesView::setModel(QAbstractItemModel *model) {
  QAbstractItemView::setModel(model);
  hash_is_dirty = true;
}


void ListOfAttachesView::calculateRectsIfNecessary() const {
  if (!hash_is_dirty) return;
  const int kExtraHeight = 3;
  const int kExtraWidth = 10;
  QFontMetrics font_metrics(font());
  const int kRowHeight = font_metrics.height() + kExtraHeight;
  const int kMaxWidth = viewport()->width();
  int minimum_width = 0;
  int x = 0;
  int y = 0;
  for (int row = 0; row < model()->rowCount(rootIndex()); ++row) {
    QModelIndex index = model()->index(row, 0, rootIndex());
    QString text = model()->data(index).toString();
    int text_width = font_metrics.width(text);
    if (!(x == 0 || x + text_width + kExtraWidth < kMaxWidth)) {
      y += kRowHeight;
      x = 0;
    } else if (x != 0)
      x += kExtraWidth;
    rect_for_row[row] = QRectF(x, y, text_width + kExtraWidth, kRowHeight);
    if (text_width > minimum_width) minimum_width = text_width;
    x += text_width;
  }
  ideal_width = minimum_width + kExtraWidth;
  ideal_height = y + kRowHeight;
  hash_is_dirty = false;
  viewport()->update();
}/**/
