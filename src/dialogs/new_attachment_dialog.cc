
#include "add_attach/add_attach.h"

#include <QFileDialog>
#include <QMessageBox>

NewAttachmentDialog::NewAttachmentDialog(QWidget *parent)
    : QDialog(parent), attachment_(nullptr) {
  SetupUi();
}

NewAttachmentDialog::NewAttachmentDialog(Record::Attachment *attachment,
                                         QWidget *parent)
    : QDialog(parent) {
  SetupUi();
  SetAttachment(attachment);
}

NewAttachmentDialog::~NewAttachmentDialog() { ReleaseUi(); }

Record::Attachment *NewAttachmentDialog::GetAttachment() const {
  return attachment_;
}

void NewAttachmentDialog::SetAttachment(Record::Attachment *attachment) {
  attachment_ = attachment;
  if (attachment_) {
    name_line_edit_->setText(attachment_->name);
    file_name_line_edit_->setText(attachment_->file_name);
    name_line_edit_->setCursorPosition(0);
    file_name_line_edit_->setCursorPosition(0);
  }
}

void NewAttachmentDialog::BrowseButtonIsPressed(bool is_pressed) {
  (void)is_pressed;
  QString file_name = QFileDialog::getOpenFileName(
      this, tr("Select File"), attachment_ ? attachment_->file_name : "",
      tr("All Files (*.*)"));
  if (!file_name.isEmpty()) {
    file_name_line_edit_->setText(file_name);
  }
}
bool NewAttachmentDialog::NameAndFileNameAreSetUp() {
  return file_name_line_edit_->text() != "" && name_line_edit_->text() != "";
}

void NewAttachmentDialog::OkButtonIsPressed(bool is_pressed) {
  (void)is_pressed;
  if (NameAndFileNameAreSetUp()) {
    if (attachment_) {
      if (attachment_->file_name != file_name_line_edit_->text()) {
        attachment_->time_of_attach = QDateTime::currentDateTimeUtc();
      }
      attachment_->file_name = file_name_line_edit_->text();
      attachment_->name = name_line_edit_->text();
    }
    this->accept();
  } else {
    QMessageBox(QMessageBox::Critical, tr("Error"),
                tr("Attachment name and file name must not be empty."),
                QMessageBox::Ok, this).exec();
  }
}

void NewAttachmentDialog::CancelButtonIsPressed(bool is_pressed) {
  (void)is_pressed;
  this->reject();
}

void NewAttachmentDialog::SetupSignals() {
  connect(browse_button_, SIGNAL(clicked(bool)), this,
          SLOT(BrowseButtonIsPressed(bool)));
  connect(ok_button_, SIGNAL(clicked(bool)), this,
          SLOT(OkButtonIsPressed(bool)));
  connect(cancel_button_, SIGNAL(clicked(bool)), this,
          SLOT(CancelButtonIsPressed(bool)));
}

void NewAttachmentDialog::SetupUi() {
  title_label_ = new QLabel(tr("Attachment properties:"), this);
  title_label_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  name_line_edit_ = new QLineEdit(this);
  file_name_line_edit_ = new QLineEdit(this);
  browse_button_ = new QToolButton(this);
  browse_button_->setText(tr("..."));
  name_label_ = new QLabel(tr("Name:"), this);
  file_name_label_ = new QLabel(tr("File location:"), this);
  copy_file_check_box_ =
      new QCheckBox(tr("Copy this file to local base"), this);
  ok_cancel_box_ = new QDialogButtonBox(this);
  ok_button_ = new QPushButton(tr("Ok"), this);
  cancel_button_ = new QPushButton(tr("Cancel"), this);
  ok_cancel_box_->addButton(ok_button_, QDialogButtonBox::ActionRole);
  ok_cancel_box_->addButton(cancel_button_, QDialogButtonBox::ActionRole);
  layout_ = new QGridLayout(this);
  layout_->addWidget(title_label_, 0, 1);
  layout_->addWidget(name_label_, 1, 0);
  layout_->addWidget(name_line_edit_, 1, 1);
  layout_->addWidget(file_name_label_, 2, 0);
  layout_->addWidget(file_name_line_edit_, 2, 1);
  layout_->addWidget(browse_button_, 2, 2);
  layout_->addWidget(copy_file_check_box_, 3, 1);
  layout_->addWidget(ok_cancel_box_, 4, 1);
  layout_->setSizeConstraint(QLayout::SetMinimumSize);
  // TODO: fix streching
  this->setLayout(layout_);
  this->setWindowTitle(tr("Attach file to record"));
  this->resize(600, 150);
  SetupSignals();
}

void NewAttachmentDialog::ReleaseUi() {}
