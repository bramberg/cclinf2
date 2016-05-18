
#include "main_window.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QApplication>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>

#include <iostream>

#include "settings.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  SetupModel();
  SetupUi();
}

MainWindow::~MainWindow() {}

void MainWindow::SetupModel() {
  QSettings settings("Andrew Boring", "cclinf2", this);
  if (settings.value(settings_names::kDatabasePath).isNull()) {
    SetDefaultSettings();
  }

  this->database_ = new Database();
  this->database_reader_ = new FileSystemDatabaseReader(
      settings.value(settings_names::kDatabasePath).toString());
  Record *records_index = nullptr;
  try {
    this->database_->Read(*this->database_reader_);
    records_index = this->database_->GetRecordsTree();
  } catch (exceptions::CouldNotOpenFileForReading &) {
    QMessageBox(QMessageBox::Critical, tr("Error"),
                tr("Could not open database index file."),
                QMessageBox::Ok).exec();
  } catch (exceptions::FileHasInvalidVersion &) {
    QMessageBox(QMessageBox::Critical, tr("Error"),
                tr("Database index version is incorrect."),
                QMessageBox::Ok).exec();
  }
}

QMenuBar *MainWindow::CreateMainMenuBar() {
  QMenuBar *menu_bar = new QMenuBar(this);
  menu_bar->addAction("Database");
  menu_bar->addAction("Record");
  menu_bar->addAction("Note");
  menu_bar->addAction("Edit");
  menu_bar->addAction("View");
  menu_bar->addAction("Settings");
  menu_bar->addAction("About");

  return menu_bar;
}

void MainWindow::SetupUi() {
  // QMessageBox::aboutQt(this);

  // this->setMenuBar(menu_bar_);

  /*
  QFile *file = new QFile("C:\\Users\\andrey\\Documents\\QtProjects\\test.xml");
  if (!file->open(QIODevice::ReadOnly)) {
    QMessageBox::information(0, "error", file->errorString());
  }

  qDebug() << "FILE:";

  QXmlStreamReader xs(file);
  while (!xs.atEnd()) {
    if (QXmlStreamReader::TokenType t = xs.readNext()) {
      if (xs.isStartElement()) {
        qDebug() << "<" << xs.name().toString() << ">";
      } else if (xs.isEndElement()) {
        qDebug() << "</" << xs.name().toString() << ">";
      } else {
        qDebug() << "t = " << t;
      }
    }
  }

  file->close();
  delete file;

  return;*/

  central_widget_ = new QWidget(this);
  this->setCentralWidget(central_widget_);

  layout_ = new QVBoxLayout(central_widget_);

  // label_ = new QLabel("Label Text");
  // text_ = new Editor(this);
  record_viewer_ = new RecordViewer(new Record, this);

  // layout_->addWidget(label_);
  // layout_->addSpacing(100);
  // layout_->addWidget(text_);
  layout_->addWidget(record_viewer_);

  layout_->setDirection(QVBoxLayout::TopToBottom);
  layout_->setMargin(0);

  window_ = new QWidget();
  window_->setLayout(layout_);
  setCentralWidget(window_);

  menu_bar_ = CreateMainMenuBar();
  QMainWindow::setMenuBar(menu_bar_);

  navigation_tree_dock_ = new QDockWidget(tr("Navigation"));
  navigation_tree_ = new NavigationTree(navigation_tree_dock_);
  navigation_tree_dock_->setWidget(navigation_tree_);
  // navigation_tree_dock_->resize(100, 100);

  // navigation_tree_dock_->setBaseSize(150, 150);

  navigation_tree_dock_->setAllowedAreas(Qt::AllDockWidgetAreas);
  navigation_tree_dock_->setFeatures(QDockWidget::NoDockWidgetFeatures /* |
                                     QDockWidget::DockWidgetClosable |
                                     QDockWidget::DockWidgetMovable/**/);

  //  navigation_tree_dock_->setStyleSheet("QDockWidget::close-button {\
//                                       subcontrol-position: top left;\
//                                       subcontrol-origin: margin;\
//                                       position: absolute;\
//                                       top: 0px; left: 0px; bottom: 0px;\
//                                       width: 14px;\
//                                   }\
//                                   \
//                                   QDockWidget::float-button {\
//                                       subcontrol-position: top left;\
//                                       subcontrol-origin: margin;\
//                                       position: absolute;\
//                                       top: 0px; left: 16px; bottom: 0px;\
//                                       width: 14px;\
//                                   }\
//                                   \
//                                   QDockWidget::title {\
//                                       text-align: right;\
//                                       background: lightgray;\
//                                       padding-left: 35px;\
//                                   }\
//                                   \
//                                   QDockWidget {\
//                                       border: 10px solid red;\
//                                   }");

  // this->setStyleSheet("QWidget {background-color: rgb(0,100,200);}");

  //  this->setDock;

  // navigation_tree_dock_->show();

  addDockWidget(Qt::LeftDockWidgetArea, navigation_tree_dock_);

  status_bar_ = new QStatusBar();
  this->setStatusBar(status_bar_);

  // QSizePolicy policy;
  // policy.setHorizontalPolicy();

  this->setContentsMargins(0, 0, 0, 0);  // setSizePolicy();
                                         // this->setMargin(0);
}

void MainWindow::SetDefaultSettings() {
  QSettings settings("Andrew Boring", "cclinf2", this);
  settings.setValue(settings_names::kDatabasePath,
                    QFileInfo(QFile("./database")).absoluteFilePath());
  settings.setValue(settings_names::kDatabaseIndexName,
                    QFileInfo(QFile("index.xml")).absoluteFilePath());
  settings.sync();
}
