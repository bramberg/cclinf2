
#include "record_viewer/title/record_title.h"

RecordTitle::RecordTitle(QWidget* parent) : QWidget(parent) { SetupUi(); }

RecordTitle::~RecordTitle() { ReleaseUi(); }

void RecordTitle::SetName(const QString& name) { name_->setText(name); }

void RecordTitle::SetNotaion(const QString& notation) {
  notation_->setText(notation);
}

void RecordTitle::SetupUi() {
  name_ = new QLabel(this);
  notation_ = new QLabel(this);
  layout_ = new QVBoxLayout(this);
  layout_->addWidget(name_);
  layout_->addWidget(notation_);
  layout_->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
  this->setLayout(layout_);
  this->show();
}

void RecordTitle::SetupSignals() {}

void RecordTitle::ReleaseUi() {
  this->hide();
  this->setLayout(nullptr);
  delete layout_;
  delete name_;
  delete notation_;
}
