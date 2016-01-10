#include "links_list.h"

LinksListView::LinksListView(QWidget *parent) : QWidget(parent) {
  SetupUi();
  SetupSignals();
}

void LinksListView::SetupUi() {
  layout_ = new QVBoxLayout(this);
  scroll_area_ = new VerticalScrollArea(this);
  layout_->addWidget(scroll_area_);
  inner_layout_ = new QVBoxLayout(this);

  add_button_ = new QPushButton(this);
  add_button_->setText("+");
  add_button_->setIcon(QIcon(":/images/ic_add_24px.svg"));
  add_button_->setIconSize(QSize(17, 17));

  inner_layout_->addWidget(add_button_);
  scroll_area_->setLayout(inner_layout_);

  inner_layout_->setMargin(0);
  inner_layout_->setDirection(QVBoxLayout::BottomToTop);
  // layout_->setMargin(0);
  // layout_->setContentsMargins(100, 100, 100 ,100);
  // inner_layout_->setContentsMargins(0, 0, 0, 0);
  // inner_layout_->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);

  // scroll_area_->setContentsMargins(0, 0, 0, 0);

  // scroll_area_->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,
  // QSizePolicy::Expanding));

  // scroll_area_->setFixedSize(inner_layout_->sizeHint());
  // scroll_area_->setFrameStyle();
  scroll_area_->setBackgroundRole(QPalette::Dark);

  scroll_area_->setFrameStyle(QFrame::NoFrame);

  inner_layout_->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
  layout_->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

  AddElement(
      tr("<a href=\"http://www.yandex.ru\">A. G. Kurosh Further mathematocs "
         "course<a>"));
  AddElement(tr(
      "<a href=\"http://www.yandex.ru\">A. A. Borovkov Probability theory<a>"));

  this->setLayout(layout_);
  this->show();
}

void LinksListView::UpdateUi() {
  foreach (LinkView *element, elements_) {}
}

void LinksListView::SetupSignals() {}

void LinksListView::AddElement(const QString &text) {
  LinkView *new_element = new LinkView(text, this);
  elements_.append(new_element);
  inner_layout_->addWidget(new_element);
  // scroll_area_->setFixedSize(inner_layout_->sizeHint());
  // UpdateUi();
}
