
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

class AddAttach : public QDialog {
  Q_OBJECT

 public:
  explicit AddAttach(QWidget* parent = 0);
  explicit AddAttach(Record::Attach* attach, QWidget* parent = 0);
  ~AddAttach();

  void Show();
  Record::Attach* GetAttach() const;
  void SetAttach(Record::Attach* attach);

  void show();

signals:

 public slots:
  void BrowseButtonIsPressed(bool is_pressed);

 private:
  Record::Attach* attach_;

  QGridLayout* layout_;
  QDialogButtonBox* ok_cancel_box_;

  QLabel* title_label_;
  QLabel* name_label_;
  QLabel* file_name_label_;
  QPushButton* ok_button_;
  QPushButton* cancel_button_;
  QToolButton* browse_button_;
  QLineEdit* name_line_;
  QLineEdit* file_name_line_;
  QCheckBox* copy_file_check_box_;

  void SetupUi();
  void ReleaseUi();
};

#endif
