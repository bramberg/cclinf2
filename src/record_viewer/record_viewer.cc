
#include "record_viewer.h"

RecordViewer::RecordViewer(QWidget *parent) : QWidget(parent) {
  SetupUi();
  SetupSignals();
}

RecordViewer::RecordViewer(Record *record, QWidget *parent) : QWidget(parent) {
  SetupUi();
  SetupSignals();
  SetRecord(record);
}

RecordViewer::~RecordViewer() {}

void RecordViewer::SetupUi() {
  // if (record_->GetNumberOfNotes() > 1)

  layout_ = new QVBoxLayout(this);
  layout_->setMargin(0);
  layout_->setSpacing(0);

  tab_widget_ = new QTabWidget(this);
  tab_widget_->addTab(new Editor(this), tr("Note #1"));
  tab_widget_->addTab(new Editor(this), tr("Note #1"));

  tab_widget_->setStyleSheet(
      "QTabWidget::pane\
  {\
      border: 1px solid;\
      border-color: rgb(161, 157, 154);\
      margin-left: 0px;\
      padding: -1px;\
      padding-right: -2px;\
      border-radius: 0px;\
  }");

        palette().highlight();

  // tab_widget_->setStyleSheet("QTabWidget::pane { border-color: red; }");

  // tab_widget_->setStyleSheet("QTabWidget::pane { border: 0; }");
  // tab_widget_->tab
  // tab_widget_->setBackgroundRole(QPalette::Dark);
  /*
    tab_widget_->setPalette(
        *(new QPalette(Qt::green, Qt::green, Qt::green, Qt::green, Qt::green,
                       Qt::green, Qt::green)));
  */
  // notes_editor_ = new Editor(this);
  links_list_ = new LinksListView(this);
  scroll_area_ = new QScrollArea(this);
  scroll_area_->setWidget(links_list_);
  scroll_area_->setFrameStyle(0);
  scroll_area_->setContentsMargins(0, 0, 0, 0);
  scroll_area_->setMaximumHeight(links_list_->height());
  // scroll_area_->setBackgroundRole(QPalette::ColorRole::LinkVisited);
  splitter_ = new QSplitter(this);
  splitter_->addWidget(tab_widget_);
  splitter_->addWidget(scroll_area_);
  splitter_->setOrientation(Qt::Orientation::Vertical);

  layout_->addWidget(splitter_);
  // layout_->addWidget(tab_widget_);
  // layout_->addWidget(scroll_area_);

  QWidget::setLayout(layout_);
  QWidget::show();
}

void RecordViewer::SetupSignals() {}

void RecordViewer::UpdateUi() {}

void RecordViewer::SetRecord(Record *record) {
  record_ = record;
  this->UpdateUi();
}
