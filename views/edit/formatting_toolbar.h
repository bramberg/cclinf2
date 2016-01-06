#ifndef FORMATTINGTOOLBAR_H
#define FORMATTINGTOOLBAR_H

#include <QLayout>
#include <QAction>
#include <QToolBar>

class FormattingToolbar : public QWidget {
  Q_OBJECT
 public:
  FormattingToolbar(QWidget *parent = 0);
  ~FormattingToolbar();

  void SetupModel();

signals:
  void BoldIsTrigered(const bool bold_is_set);
  void ItalicIsTrigered(const bool bold_is_set);
  void UnderlineIsTrigered(const bool bold_is_set);
  void StrikeThroughIsTrigered(const bool bold_is_set);

 public slots:
  void SetBold(const bool is_bold);
  void SetItalic(const bool is_italic);
  void SetUnderline(const bool is_underline);
  void SetStrikeThrough(const bool is_stroke_through);

 private slots:
  // void BoldIsTrigeredSlot(const bool is_bold);

 private:
  QHBoxLayout *layout_;
  QToolBar *tool_bar_;

  QAction *set_bold_;
  QAction *set_italic_;
  QAction *set_underline_;
  QAction *set_strikethrough_;

  // TODO: with formulae
  // QAction *set_subscript_;
  // QAction *set_superscript_;

  // TODO: custom widget required
  // QAction *set_text_color_;
  // QAction *set_background_color_;

  QAction *align_left_;
  QAction *align_right_;
  QAction *center_horizontally_;
  QAction *justify_;

  QAction *increase_indent_;
  QAction *decrease_indent_;

  QAction *CreateAction(const QString &object_name, const QIcon &icon,
                        const QString &text, const QString &status_tip,
                        QKeySequence shortcut = QKeySequence(),
                        QWidget *parent = 0);
  void SetupUi();
  void FillToolBar(QToolBar *tool_bar);
  QToolBar *CreateToolbar();
  void ConnectToolBarSlots();
};

#endif  // FORMATTINGTOOLBAR_H
