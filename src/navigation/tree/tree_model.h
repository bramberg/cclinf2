
#ifndef _MODELS_TREE_TREE_MODEL_H_
#define _MODELS_TREE_TREE_MODEL_H_

#include <QtGlobal>
#include <QString>
#include <QAbstractItemModel>
#include "record.h"

class TreeModel : public QAbstractItemModel {
  Q_OBJECT

 public:
  explicit TreeModel(const QString &data, QObject *parent = 0);
  explicit TreeModel(Record *root_item, QObject *parent = 0);
  ~TreeModel();

  QVariant data(const QModelIndex &index, int role) const;
  Qt::ItemFlags flags(const QModelIndex &index) const;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const;
  QModelIndex index(int row, int column,
                    const QModelIndex &parent = QModelIndex()) const;
  QModelIndex parent(const QModelIndex &index) const;
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;

  Record *GetRecord(const QModelIndex &index);

 private:
  void setupModelData(const QStringList &lines, Record *parent);

  Record *root_item_;
};

#endif
