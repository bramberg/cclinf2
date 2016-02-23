
#include <QStringList>
#include <QIcon>
#include <QTextDocument>
#include <QFont>
#include <QDebug>

#include "navigation/tree/tree_model.h"

TreeModel::TreeModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent) {
  root_item_ = new Record("Title");
  setupModelData(data.split(QString("\n")), root_item_);
}

TreeModel::TreeModel(Record *root_item, QObject *parent)
    : QAbstractItemModel(parent) {
  root_item_ = root_item;
}

TreeModel::~TreeModel() { delete root_item_; }

int TreeModel::columnCount(const QModelIndex &parent) const {
  (void)parent;
  return 1;
}

Record *TreeModel::GetRecord(const QModelIndex &index) {
  return static_cast<Record *>(index.internalPointer());
}

QVariant TreeModel::data(const QModelIndex &index, int role) const {
  QVariant data;

  // qDebug() << "role = " << role;
  if (index.isValid()) {
    Record *item = static_cast<Record *>(index.internalPointer());
    switch (role) {
      case Qt::DisplayRole:

        data = "" + item->GetNotation() + " = " + item->GetName();
        break;
      case Qt::DecorationRole:

        /*data = QIcon(item->childCount() > 0
                         ? "../cclinf-2/material-icons/core/folder.svg"
                         : "../cclinf-2/material-icons/core/https.svg");*/

        break;
      case Qt::BackgroundRole:
        data = QColor(item->HasNoParent() ? QRgb(0xFFBBBB) : QRgb(0xFFFFFF));
        break;

      case Qt::FontRole:
        data = item->GetNumberOfChildren() > 0
                   ? QFont("", 0, QFont::Bold, false)
                   : QFont("", 0, QFont::Normal, false);
        break;

      case Qt::DecorationPropertyRole: {
        QSize size(10, 10);
        data = size;
      } break;
      case Qt::ToolTipRole:
        data = QString() + "ToolTip " + item->GetCreationDate().toString();
        // QDateTime(QDate(2015, 12, 1), QTime(12, 34, 56)).toString();
    }
  }
  return data;
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const {
  Qt::ItemFlags flags = 0;
  if (index.isValid()) {
    flags = QAbstractItemModel::flags(index);
  }
  return flags;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const {
  QVariant header_data;
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
    header_data = root_item_->GetName();
  }
  return header_data;
}

QModelIndex TreeModel::index(int row, int column,
                             const QModelIndex &parent) const {
  if (!hasIndex(row, column, parent)) return QModelIndex();

  Record *parentItem;

  if (!parent.isValid())
    parentItem = root_item_;
  else
    parentItem = static_cast<Record *>(parent.internalPointer());

  Record *childItem = parentItem->GetChildAtRow(row);
  if (childItem)
    return createIndex(row, column, childItem);
  else
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const {
  QModelIndex parent = QModelIndex();
  if (index.isValid()) {
    Record *child_item = static_cast<Record *>(index.internalPointer());
    Record *parent_item = child_item->GetParent();
    if (parent_item != root_item_) {
      parent = createIndex(parent_item->GetRow(), 0, parent_item);
    }
  }
  return parent;
}

int TreeModel::rowCount(const QModelIndex &parent) const {
  Record *parentItem;
  if (parent.column() > 0) return 0;

  if (!parent.isValid())
    parentItem = root_item_;
  else
    parentItem = static_cast<Record *>(parent.internalPointer());

  return parentItem->GetNumberOfChildren();
}

void TreeModel::setupModelData(const QStringList &lines, Record *parent) {
  QList<Record *> parents;
  QList<int> indentations;
  parents << parent;
  indentations << 0;

  for (int current_line = 0; current_line < lines.count(); ++current_line) {
    int position_in_line = 0;
    while (position_in_line < lines[current_line].length()) {
      if (lines[current_line].mid(position_in_line, 1) != " ") break;
      position_in_line++;
    }

    QString lineData = lines[current_line].mid(position_in_line).trimmed();

    if (!lineData.isEmpty()) {
      // Read the column data from the rest of the line.
      QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
      QString columnData;
      for (int column = 0; column < columnStrings.count(); ++column) {
        columnData = columnStrings[column];
      }

      if (position_in_line > indentations.last()) {
        // The last child of the current parent is now the new parent
        // unless the current parent has no children.

        if (parents.last()->GetNumberOfChildren() > 0) {
          parents << parents.last()->GetChildAtRow(
              parents.last()->GetNumberOfChildren() - 1);
          indentations << position_in_line;
        }
      } else {
        while (position_in_line < indentations.last() && parents.count() > 0) {
          parents.pop_back();
          indentations.pop_back();
        }
      }

      // Append a new item to the current parent's list of children.
      parents.last()->AppendChild(new Record(columnData, parents.last()));
    }
  }
}
