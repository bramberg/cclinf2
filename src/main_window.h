
#ifndef __CCLINF_2_VIEWS_MAIN_WINDOW_MAIN_WINDOW_H__
#define __CCLINF_2_VIEWS_MAIN_WINDOW_MAIN_WINDOW_H__

#include <QMainWindow>
#include <QSplitter>

#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QStatusBar>
#include <QMenuBar>
#include <QSettings>
#include <QCloseEvent>

#include "db/db.h"
#include "db/filesystem/filesystem_database_reader.h"
#include "navigation/tree/tree_view.h"
#include "record_viewer/editor/editor.h"
#include "record_viewer/record_viewer.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();


private slots:

 private:
  void SetupUi();

  QMenuBar *CreateMainMenuBar();

  QMenuBar *menu_bar_;

  QSplitter *horizontal_splitter_;

  NavigationTree *navigation_tree_;

  QDockWidget *navigation_tree_dock_;
  QStatusBar *status_bar_;

  QWidget *central_widget_;
  QVBoxLayout *layout_;
  QLabel *label_;
  Editor *text_;
  QWidget *window_;

  RecordViewer *record_viewer_;

  // model
  void SetupModel();
  void SetDefaultSettings();
  Database *database_;
  FileSystemDatabaseReader *database_reader_;

  //QSettings *settings_;

 protected:
};

#endif
