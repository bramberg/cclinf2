
#include <QApplication>

#include <QtGlobal>
#include <QDebug>

#include "views/main_window/main_window.h"

#include <QUuid>

int main(int argc, char *argv[]) {
  //qSetMessagePattern("%{file}(%{line}): %{message}");

  QApplication app(argc, argv);

  MainWindow w;
  w.show();

  // QQmlApplicationEngine engine;
  // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  QUuid uid = QUuid(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

  qDebug() << uid.toString();

  return app.exec();
}
