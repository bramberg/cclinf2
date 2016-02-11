
#ifndef __CCLINF_2_VIEWS_EDIT_EDIT_H__
#define __CCLINF_2_VIEWS_EDIT_EDIT_H__

#include <QMainWindow>
#include <QSplitter>
#include <QLayout>
#include <QToolBar>
#include <QToolButton>
#include <QAction>
#include <QTextEdit>
#include <QToolButton>
#include <QColorDialog>
#include <QPushButton>
#include <QTextEdit>

#include "custom_text_edit.h"
#include "formatting_toolbar.h"

class Editor : public QWidget {
  Q_OBJECT

 public:
  Editor(QWidget *parent = 0);
  ~Editor();

  void SetHtml(const QString &html);
  void SetPlainText(const QString &plain_text);

  QString GetHtml() const;

 public slots:
  void SetTextBold(const bool is_bold);
  void SetTextItalic(const bool is_italic);
  void SetTextUnderline(const bool is_underline);
  void SetTextStrikeThrough(const bool is_strike_through);

  void CursorPositionChanged();

 private:
  QVBoxLayout *layout_;
  FormattingToolbar *formatting_tool_bar_;
  QTextEdit *text_edit_;

  void SetupUI();
  void SetupSignals();
};

#endif
