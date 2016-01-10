#ifndef LINKVIEW_H
#define LINKVIEW_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>
#include <QLayout>

class LinkView : public QWidget {
  Q_OBJECT
 public:
  explicit LinkView(QWidget *parent = 0);
  explicit LinkView(const QString &text, QWidget *parent = 0);

  void SetText(const QString &text);

signals:

 public slots:

 private:
  QHBoxLayout *layout_;
  QLabel *label_;
  QToolButton *delete_button_;
  QToolButton *configure_button_;

  void SetupUi();
  void SetupSignals();
};

#endif  // LINKVIEW_H
