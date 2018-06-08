#ifndef SHOP_H
#define SHOP_H
#include <QAbstractTableModel>
#include <QList>
#include <QPair>
#include <QSharedPointer>

#include "item.h"

class Shop : public QAbstractTableModel
{
public:
    Shop();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QList<QPair<int, QSharedPointer<Item>>> items;
};

#endif // SHOP_H
