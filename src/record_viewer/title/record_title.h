
#ifndef _CCLINF_RECORD_INFO_H_
#define _CCLINF_RECORD_INFO_H_

#include <QLabel>
#include <QLayout>

class RecordTitle : public QWidget {
 public:
  RecordTitle(QWidget *parent);
  ~RecordTitle();

  void SetName(const QString &name);
  void SetNotaion(const QString &notation);

 private:
  QLabel *name_;
  QLabel *notation_;
  QVBoxLayout *layout_;

  void SetupUi();
  void ReleaseUi();
  void SetupSignals();
};

#endif
