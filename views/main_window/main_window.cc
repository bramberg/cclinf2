
#include "main_window.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

#include <iostream>

#include "models/db/filesystem/xml.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { SetupUi(); }

MainWindow::~MainWindow() { ReleaseUi(); }

void MainWindow::SetupUi() {
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

  layout_ = new QVBoxLayout();

  label_ = new QLabel("Label Text");
  text_ = new Editor(this);

  layout_->addWidget(label_);
  layout_->addSpacing(100);
  layout_->addWidget(text_);

  layout_->setDirection(QVBoxLayout::TopToBottom);

  window_ = new QWidget();
  window_->setLayout(layout_);

  layout_->setMargin(0);

  setCentralWidget(window_);

  navigation_tree_dock_ = new QDockWidget(tr("Navigation"));
  navigation_tree_ = new NavigationTree(navigation_tree_dock_);
  navigation_tree_dock_->setWidget(navigation_tree_);
  //navigation_tree_dock_->resize(100, 100);

  //navigation_tree_dock_->setBaseSize(150, 150);

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

void MainWindow::ReleaseUi() {
  delete navigation_tree_;
  delete navigation_tree_dock_;
  navigation_tree_ = nullptr;
  navigation_tree_dock_ = nullptr;
}