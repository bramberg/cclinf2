
#include "formatting_toolbar.h"

#include <QMessageBox>

FormattingToolbar::FormattingToolbar(QWidget *parent) : QWidget(parent) {
  SetupUi();
}

FormattingToolbar::~FormattingToolbar() {}

void FormattingToolbar::SetBold(const bool is_bold) {
  set_bold_->setChecked(is_bold);

  QMessageBox message(QMessageBox::Information, "WARNING",
                      QString("SetBold %1").arg(QString().number(is_bold)),
                      QMessageBox::Yes | QMessageBox::No);
  message.setIconPixmap(QIcon(":/images/ic_warning_36px.svg").pixmap(50, 50));
  // message.exec();
}

void FormattingToolbar::SetItalic(const bool is_italic) {
  set_italic_->setChecked(is_italic);
}

void FormattingToolbar::SetUnderline(const bool is_underline) {
  set_underline_->setChecked(is_underline);
}

void FormattingToolbar::SetStrikeThrough(const bool is_stroke_through) {
  set_strikethrough_->setChecked(is_stroke_through);
}

QAction *FormattingToolbar::CreateAction(const QString &object_name,
                                         const QIcon &icon, const QString &text,
                                         const QString &tool_tip,
                                         QKeySequence shortcut,
                                         QWidget *parent) {
  QAction *action = new QAction(icon, text, parent);
  action->setShortcut(shortcut);
  action->setToolTip(tool_tip + (shortcut.isEmpty()
                                     ? ""
                                     : (" (" + shortcut.toString() + ")")));
  action->setObjectName(object_name);
  return action;
}

void FormattingToolbar::FillToolBar(QToolBar *tool_bar) {
  tool_bar->addAction(
      set_bold_ = CreateAction(
          QString("action_set_bold"), QIcon(":/images/ic_format_bold_24px.svg"),
          tr("&Bold"), tr("Bold"), QKeySequence(QKeySequence::Bold), this));
  set_bold_->setCheckable(true);
  tool_bar->addAction(
      set_italic_ = CreateAction(QString("action_set_italic"),
                                 QIcon(":/images/ic_format_italic_24px.svg"),
                                 tr("&Italic"), tr("Italic"),
                                 QKeySequence(tr("Ctrl+I")), this));
  set_italic_->setCheckable(true);
  tool_bar->addAction(set_underline_ = CreateAction(
                          QString("action_set_underlined"),
                          QIcon(":/images/ic_format_underlined_24px.svg"),
                          tr("&Underline"), tr("Underline"),
                          QKeySequence(tr("Ctrl+U")), this));
  set_underline_->setCheckable(true);
  tool_bar->addAction(set_strikethrough_ = CreateAction(
                          QString("action_set_strokethrough"),
                          QIcon(":/images/ic_format_strikethrough_24px.svg"),
                          tr("Strokethrough"), tr("Strikethrough"),
                          QKeySequence(tr("")), this));
  set_strikethrough_->setCheckable(true);
  // TODO: implement in Editor
  set_strikethrough_->setEnabled(false);
  tool_bar->addSeparator();
  tool_bar->addAction(align_left_ = CreateAction(
                          QString("action_align_left"),
                          QIcon(":/images/ic_format_align_left_24px.svg"),
                          tr("Align left"), tr("Align left"),
                          QKeySequence(tr("Ctrl+L")), this));
  align_left_->setCheckable(true);
  tool_bar->addAction(center_horizontally_ = CreateAction(
                          QString("action_center_horizontally"),
                          QIcon(":/images/ic_format_align_center_24px.svg"),
                          tr("Center horizontally"), tr("Center horizontally"),
                          QKeySequence(tr("Ctrl+E")), this));
  center_horizontally_->setCheckable(true);
  tool_bar->addAction(align_right_ = CreateAction(
                          QString("action_align_right"),
                          QIcon(":/images/ic_format_align_right_24px.svg"),
                          tr("Align right"), tr("Align right"),
                          QKeySequence(tr("Ctrl+R")), this));
  align_right_->setCheckable(true);
  tool_bar->addAction(justify_ = CreateAction(
                          QString("action_justify"),
                          QIcon(":/images/ic_format_align_justify_24px.svg"),
                          tr("Justify"), tr("Justify"),
                          QKeySequence(tr("Ctrl+J")), this));
  justify_->setCheckable(true);
  tool_bar->addSeparator();
  tool_bar->addAction(increase_indent_ = CreateAction(
                          QString("action_increase_indent"),
                          QIcon(":/images/ic_format_indent_increase_24px.svg"),
                          tr("Increase indent"), tr("Increase indent"),
                          QKeySequence(tr("")), this));
  tool_bar->addAction(decrease_indent_ = CreateAction(
                          QString("action_decrease_indent"),
                          QIcon(":/images/ic_format_indent_decrease_24px.svg"),
                          tr("Decrease indent"), tr("Decrease indent"),
                          QKeySequence(tr("")), this));
}

void FormattingToolbar::ConnectToolBarSlots() {
  connect(set_bold_, SIGNAL(triggered(bool)), this,
          SIGNAL(BoldIsTrigered(bool)));
  connect(set_italic_, SIGNAL(triggered(bool)), this,
          SIGNAL(ItalicIsTrigered(bool)));
  connect(set_underline_, SIGNAL(triggered(bool)), this,
          SIGNAL(UnderlineIsTrigered(bool)));
  connect(set_strikethrough_, SIGNAL(triggered(bool)), this,
          SIGNAL(StrikeThroughIsTrigered(bool)));
}

QToolBar *FormattingToolbar::CreateToolbar() {
  QToolBar *tool_bar = new QToolBar(tr("Formatting"), this);
  FillToolBar(tool_bar);
  ConnectToolBarSlots();

  return tool_bar;
}

void FormattingToolbar::SetupUi() {
  layout_ = new QHBoxLayout(this);
  this->setLayout(layout_);
  tool_bar_ = CreateToolbar();
  layout_->addWidget(tool_bar_);
}
