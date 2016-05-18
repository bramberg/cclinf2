
#ifndef __CCLINF_2_VIEWS_TREE_TREE_H__
#define __CCLINF_2_VIEWS_TREE_TREE_H__

#include <QMainWindow>
#include <QLayout>
#include <QTreeView>
#include <QLabel>
#include <QToolBar>
#include <QAction>
#include <QLineEdit>

#include <QStyledItemDelegate>

#include "record.h"
#include "navigation/search_line/search_line.h"
#include "navigation/tree/tree_model.h"

class HtmlDelegate : public QStyledItemDelegate {
 protected:
  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const;
  QSize sizeHint(const QStyleOptionViewItem &option,
                 const QModelIndex &index) const;
};

class NavigationTree : public QWidget {
  Q_OBJECT

 public:
  NavigationTree(QWidget *parent = 0);
  ~NavigationTree();

  Record *GetRecordsTree() const;
  void SetRecordsTree(Record *GetRecordsTree);

private slots:
  void TreeElementSelected(const QModelIndex &index);

private:
  void SetupModels();
  void SetupSignals();
  void SetupUI();

  TreeModel *tree_model_;
  HtmlDelegate *delegate_;

  QVBoxLayout *layout_;
  QTreeView *tree_widget_;

  SearchLine *search_line_;

  QLabel *label_;

  Record *records_tree_;
};

#endif
