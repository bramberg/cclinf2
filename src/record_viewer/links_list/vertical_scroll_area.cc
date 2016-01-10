
#include "vertical_scroll_area.h"

#include <QMessageBox>

VerticalScrollArea::VerticalScrollArea(QWidget *parent) : QScrollArea(parent) {
  setWidgetResizable(true);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  installEventFilter(this);

  //  m_scrollAreaWidgetContents = new QWidget(this);
  //  m_scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Preferred,
  //  QSizePolicy::Preferred);
  //  QVBoxLayout *baseLayout = new QVBoxLayout(m_scrollAreaWidgetContents);
  //  setWidget(m_scrollAreaWidgetContents);
  //  m_scrollAreaWidgetContents->installEventFilter(this);
}

bool VerticalScrollArea::eventFilter(QObject *object, QEvent *event) {
  // This works because QScrollArea::setWidget installs an eventFilter on the
  // widget

  if (object && object == widget() && event->type() == QEvent::Resize) {
    QMessageBox(QMessageBox::Information, "", "eventFilter").exec();
    setMinimumWidth(widget()->minimumSizeHint().width() +
                    verticalScrollBar()->width());
  }

  return QScrollArea::eventFilter(object, event);
}
