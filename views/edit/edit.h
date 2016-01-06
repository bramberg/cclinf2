
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

#include "views/edit/text_edit.h"
#include "views/edit/formatting_toolbar.h"
#include "views/edit/editmodel.h"

class Editor : public QWidget {
  Q_OBJECT

 public:
  Editor(QWidget *parent = 0);
  ~Editor();

  void SetupUI();

 public slots:
  void SetTextBold(const bool is_bold);
  void SetTextItalic(const bool is_italic);
  void SetTextUnderline(const bool is_underline);
  void SetTextStrikeThrough(const bool is_strike_through);

  void CursorPositionChanged();

 private:
  QVBoxLayout *vertical_layout_;
  QHBoxLayout *horizontal_layout_;
  FormattingToolbar *formatting_tool_bar_;
  QTextEdit *text_edit_;
};

#endif
