
#ifndef _ADD_ATTACH_H_
#define _ADD_ATTACH_H_

#include <QDialog>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QLayout>
#include <QDialogButtonBox>
#include <QLabel>
#include <QCheckBox>

#include "record.h"

class NewAttachmentDialog : public QDialog {
  Q_OBJECT

 public:
  enum Result { ResultOk, ResultCancel };

  explicit NewAttachmentDialog(QWidget* parent = 0);
  explicit NewAttachmentDialog(Record::Attachment* attachment,
                               QWidget* parent = 0);
  ~NewAttachmentDialog();

  void Show();
  Record::Attachment* GetAttachment() const;
  void SetAttachment(Record::Attachment* attachment);

signals:

 public slots:
  void BrowseButtonIsPressed(bool);
  void OkButtonIsPressed(bool);
  void CancelButtonIsPressed(bool);

 private:
  Record::Attachment* attachment_;

  QGridLayout* layout_;
  QDialogButtonBox* ok_cancel_box_;

  QLabel* title_label_;
  QLabel* name_label_;
  QLabel* file_name_label_;
  QPushButton* ok_button_;
  QPushButton* cancel_button_;
  QToolButton* browse_button_;
  QLineEdit* name_line_edit_;
  QLineEdit* file_name_line_edit_;
  QCheckBox* copy_file_check_box_;

  void SetupUi();
  void SetupSignals();
  void ReleaseUi();
  bool NameAndFileNameAreSetUp();
};

#endif
