
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
  //notes_editor_ = new Editor(this);
  links_list_ = new LinksListView(this);

  layout_->addWidget(tab_widget_);
  layout_->addWidget(links_list_);

  this->setLayout(layout_);
  this->show();
}

void RecordViewer::SetupSignals() {}

void RecordViewer::UpdateUi() {}

void RecordViewer::SetRecord(Record *record) {
  record_ = record;
  UpdateUi();
}
