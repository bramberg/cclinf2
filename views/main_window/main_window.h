
#ifndef __CCLINF_2_VIEWS_MAIN_WINDOW_MAIN_WINDOW_H__
#define __CCLINF_2_VIEWS_MAIN_WINDOW_MAIN_WINDOW_H__

#include <QMainWindow>
#include <QSplitter>

#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QStatusBar>

#include "views/tree/tree.h"
#include "views/edit/edit.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

 private slots:

 private:
  void SetupUi();
  void ReleaseUi();

  QSplitter *horizontal_splitter_;

  NavigationTree *navigation_tree_;

  QDockWidget *navigation_tree_dock_;
  QStatusBar *status_bar_;

  QVBoxLayout *layout_;
  QLabel *label_;
  Editor *text_;
  QWidget *window_;

 protected:
};

#endif
