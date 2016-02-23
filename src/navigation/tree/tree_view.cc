
#include "navigation/tree/tree_view.h"

#include <QHeaderView>

#include "db/filesystem/index/reader.h"
#include "db/filesystem/index/writer.h"

#include <QApplication>
#include <QTextDocument>
#include <QStyledItemDelegate>
#include <QAbstractTextDocumentLayout>
#include <QPainter>

#include <QMessageBox>
#include <QDebug>

void HtmlDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const {
  QStyleOptionViewItemV4 optionV4 = option;
  initStyleOption(&optionV4, index);

  QStyle *style =
      optionV4.widget ? optionV4.widget->style() : QApplication::style();

  QTextDocument doc;
  doc.setHtml(optionV4.text);

  /// Painting item without text
  optionV4.text = QString();
  style->drawControl(QStyle::CE_ItemViewItem, &optionV4, painter);

  QAbstractTextDocumentLayout::PaintContext ctx;

  // Highlighting text if item is selected
  if (optionV4.state & QStyle::State_Selected)
    ctx.palette.setColor(
        QPalette::Text,
        optionV4.palette.color(QPalette::Active, QPalette::HighlightedText));

  QRect textRect =
      style->subElementRect(QStyle::SE_ItemViewItemText, &optionV4);
  painter->save();
  painter->translate(textRect.topLeft());
  painter->setClipRect(textRect.translated(-textRect.topLeft()));
  doc.documentLayout()->draw(painter, ctx);
  painter->restore();
}

QSize HtmlDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const {
  QStyleOptionViewItemV4 optionV4 = option;
  initStyleOption(&optionV4, index);

  QTextDocument doc;
  doc.setHtml(optionV4.text);
  doc.setTextWidth(optionV4.rect.width());
  return QSize(doc.idealWidth(), doc.size().height());
}

NavigationTree::NavigationTree(QWidget *parent) : QWidget(parent) { SetupUI(); }

NavigationTree::~NavigationTree() {
  delete tree_model_;
  tree_model_ = nullptr;
}

void NavigationTree::TreeElementSelected(const QModelIndex &index) {
  Record *record = tree_model_->GetRecord(index);
  QMessageBox(QMessageBox::Critical, tr("Error"), record->GetName(),
              QMessageBox::Ok).exec();
}

void NavigationTree::SetupModels() {
  Record *records_from_file;

  try {
    records_from_file = IndexXmlReader().ReadRecordsFromFile(
        // "C:\\Users\\andrey\\Documents\\QtProjects\\test2.xml");
        "./../test.xml");
  } catch (IndexXmlReader::CouldNotOpenFile &e) {
    QMessageBox(QMessageBox::Critical, tr("Error"),
                tr("Could not open database index file."),
                QMessageBox::Ok).exec();
  } catch (IndexXmlReader::FileHasInvalidVersion &e) {
    QMessageBox(QMessageBox::Critical, tr("Error"),
                tr("Database index version is incorrect."),
                QMessageBox::Ok).exec();
  }

  IndexXmlWriter().WriteIndexToFile(records_from_file, "../test2.xml");
  // records_from_file, "C:\\Users\\andrey\\Documents\\QtProjects\\test2.xml");

  if (records_from_file) {
    tree_model_ = new TreeModel(records_from_file, nullptr);
    tree_widget_->setModel(tree_model_);

    delegate_ = new HtmlDelegate();
    tree_widget_->setItemDelegate(delegate_);
  }
}

void NavigationTree::SetupSignals() {
  connect(tree_widget_->selectionModel(),
          SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
          this, SLOT(TreeElementSelected(const QModelIndex &)));
}

void NavigationTree::SetupUI() {
  layout_ = new QVBoxLayout();
  tree_widget_ = new QTreeView();
  search_line_ = new SearchLine();

  tree_widget_->header()->hide();

  layout_->addWidget(search_line_);
  layout_->addWidget(tree_widget_);

  layout_->setSpacing(5);
  layout_->setMargin(0);

  this->setLayout(layout_);
  this->show();

  SetupModels();
  SetupSignals();
}
