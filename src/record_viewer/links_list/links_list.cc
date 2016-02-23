#include "links_list.h"

LinksListView::LinksListView(QWidget *parent) : QWidget(parent) {
  this->SetupUi();
  this->SetupSignals();
}

void LinksListView::SetupUi() {
  layout_ = new QVBoxLayout(this);

  add_button_ = new QToolButton(this);
  add_button_->setText(tr("+"));
  add_button_->setIcon(QIcon(":/images/ic_add_24px.svg"));
  add_button_->setIconSize(QSize(17, 17));

  layout_->addWidget(add_button_);

  layout_->setMargin(0);
  layout_->setSpacing(2);
  layout_->setDirection(QVBoxLayout::BottomToTop);

  layout_->setSizeConstraint(QLayout::SizeConstraint::SetMinAndMaxSize);

  layout_->setContentsMargins(0, 0, 0, 2 + 4);
  /*
    this->AddElement(
        tr("<a href=\"http://www.yandex.ru\">A. G. Kurosh Further mathematics "
           "course<a>"));

    this->AddElement(tr(
        "<a href=\"http://www.yandex.ru\">A. A. Borovkov Probability
    theory<a>"));

    this->AddElement(tr(
        "<a href=\"http://www.yandex.ru\">A. A. Borovkov Probability
    theory<a>"));

    //*/
  QWidget::setLayout(layout_);
  QWidget::show();
}

void LinksListView::Update() {
  //record_.
  foreach (LinkView *element, elements_) {}
}

void LinksListView::SetupSignals() {
  connect(add_button_, SIGNAL(clicked(bool)), this,
          SIGNAL(AddButtonWasPressed(bool)));
}

void LinksListView::AddElement(const QString &text) {
  LinkView *new_element = new LinkView(text, this);
  elements_.append(new_element);
  layout_->addWidget(new_element);
  this->Update();
}
