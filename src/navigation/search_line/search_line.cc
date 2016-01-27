
#include "navigation/search_line/search_line.h"

SearchLine::SearchLine(QWidget *parent) : QWidget(parent) { SetupUI(); }

SearchLine::~SearchLine() {}

void SearchLine::SetupUI() {
  layout_ = new QHBoxLayout();
  search_line_ = new QLineEdit();
  search_line_->setPlaceholderText(tr("Search for..."));
  button_ = new QPushButton();
  button_->setIcon(QIcon("://images/ic_search_24px.svg"));
  layout_->addWidget(search_line_);
  layout_->addWidget(button_);

  // layout_->setSpacing(0);
  layout_->setMargin(0);

  this->setLayout(layout_);
  this->show();
}
