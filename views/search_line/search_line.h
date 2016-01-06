
#ifndef __CCLINF_2_VIEWS_SEARCH_LINE_SEARCH_LINE_H__
#define __CCLINF_2_VIEWS_SEARCH_LINE_SEARCH_LINE_H__

#include <QSplitter>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>

class SearchLine : public QWidget {
  Q_OBJECT

 public:
  SearchLine(QWidget *parent = 0);
  ~SearchLine();

 private slots:

 private:
  void SetupUI();

  QHBoxLayout *layout_;
  QLineEdit *search_line_;
  QPushButton *button_;

 protected:
};

#endif
