#include "link_view.h"

LinkView::LinkView(QWidget *parent) : QWidget(parent) {
  SetupUi();
  SetupSignals();
}

LinkView::LinkView(const QString &text, QWidget *parent) : QWidget(parent) {
  SetupUi();
  SetupSignals();
  label_->setText(text);
}

void LinkView::SetupUi() {
  layout_ = new QHBoxLayout(this);

  delete_button_ = new QToolButton(this);
  delete_button_->setIcon(QIcon(":/images/ic_delete_24px.svg"));
  delete_button_->setIconSize(QSize(17, 17));

  configure_button_ = new QToolButton(this);
  configure_button_->setIcon(QIcon(":/images/ic_build_24px.svg"));
  configure_button_->setIconSize(QSize(17, 17));

  label_ = new QLabel(this);
  label_->setTextFormat(Qt::RichText);
  label_->setTextInteractionFlags(Qt::TextBrowserInteraction);
  label_->setOpenExternalLinks(true);

  layout_->addWidget(delete_button_);
  layout_->addWidget(configure_button_);
  layout_->addWidget(label_);
  layout_->setMargin(0);
  layout_->setSpacing(3);
  layout_->setSizeConstraint(QLayout::SetFixedSize);

  this->setLayout(layout_);
  this->show();
}

void LinkView::SetupSignals() {}
