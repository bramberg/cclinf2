
#include "editor.h"

#include <QMessageBox>
#include <QTextDocumentFragment>
#include <QTextBlock>

#include <QDebug>

Editor::Editor(QWidget *parent) : QWidget(parent) {
  SetupUI();
  SetupSignals();
}

Editor::~Editor() {
  delete horizontal_layout_;
  delete vertical_layout_;
  delete formatting_tool_bar_;
}

void Editor::SetHtml(const QString &html) { text_edit_->setHtml(html); }

void Editor::SetPlainText(const QString &plain_text) {
  text_edit_->setPlainText(plain_text);
}

QString Editor::GetHtml() const { return text_edit_->toHtml(); }

void Editor::SetupSignals() {
  connect(formatting_tool_bar_, SIGNAL(BoldIsTrigered(bool)), this,
          SLOT(SetTextBold(bool)));
  connect(formatting_tool_bar_, SIGNAL(ItalicIsTrigered(bool)), this,
          SLOT(SetTextItalic(bool)));
  connect(formatting_tool_bar_, SIGNAL(UnderlineIsTrigered(bool)), this,
          SLOT(SetTextUnderline(bool)));
  connect(formatting_tool_bar_, SIGNAL(StrikeThroughIsTrigered(bool)), this,
          SLOT(SetTextStrikeThrough(bool)));

  connect(text_edit_, SIGNAL(cursorPositionChanged()), this,
          SLOT(CursorPositionChanged()));

  connect(text_edit_, SIGNAL(selectionChanged()), this,
          SLOT(CursorPositionChanged()));
}

void Editor::SetupUI() {
  vertical_layout_ = new QVBoxLayout(this);
  //horizontal_layout_ = new QHBoxLayout(this);
  //vertical_layout_->addLayout(horizontal_layout_);
   //vertical_layout_->setMargin(0);
  // vertical_layout_->setSpacing(0);

  formatting_tool_bar_ = new FormattingToolbar(this);

  //
  // text_edit_->font();

  // text_edit_->zoomIn();

  vertical_layout_->addWidget(formatting_tool_bar_);

  text_edit_ = new QTextEdit(this);
  text_edit_->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
  vertical_layout_->addWidget(text_edit_);

  this->setLayout(vertical_layout_);
  this->show();
}

void Editor::SetTextBold(const bool is_bold) {
  if (text_edit_->textCursor().hasSelection()) {
    text_edit_->setFontWeight(is_bold ? QFont::Bold : QFont::Normal);
  }
}

void Editor::SetTextItalic(const bool is_italic) {
  if (text_edit_->textCursor().hasSelection()) {
    text_edit_->setFontItalic(is_italic);
  }
}

void Editor::SetTextUnderline(const bool is_underline) {
  if (text_edit_->textCursor().hasSelection()) {
    text_edit_->setFontUnderline(is_underline);
  }
}

void Editor::SetTextStrikeThrough(const bool is_strike_through) {
  if (text_edit_->textCursor().hasSelection()) {
    QFont font = text_edit_->currentFont();
    font.setStrikeOut(is_strike_through);
    text_edit_->setCurrentFont(font);
  }
}

void Editor::CursorPositionChanged() {
  if (text_edit_->textCursor().hasSelection()) {
    // QFont font = text_edit_->currentFont();

    emit(formatting_tool_bar_->SetBold(text_edit_->currentFont().bold()));
    // text_edit_->textCursor().selection().toHtml();
  } else {
    // emit(formatting_tool_bar_->SetUnderline(text_edit_->fontUnderline()));
  }

  emit(formatting_tool_bar_->SetBold(text_edit_->fontWeight() == QFont::Bold));
  emit(formatting_tool_bar_->SetItalic(text_edit_->fontItalic()));
  emit(formatting_tool_bar_->SetUnderline(text_edit_->fontUnderline()));
}
