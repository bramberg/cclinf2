
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

#include "views/search_line/search_line.h"
#include "models/tree/tree_model.h"

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

 private slots:

 private:
  void SetupModels();
  void SetupUI();

  TreeModel *tree_model_;
  HtmlDelegate *delegate_;

  QVBoxLayout *layout_;
  QTreeView *tree_widget_;

  SearchLine *search_line_;

  QLabel *label_;

  QToolBar *tool_bar_;

 protected:
};



#endif
