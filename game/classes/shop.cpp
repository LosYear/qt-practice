#include "shop.h"
#include "food.h"

Shop::Shop()
{
    items.append(QPair<int, QSharedPointer<Item>>(8, QSharedPointer<Item>::create("Бесполезная дорогая штука", "Удовлетворяет желание бездумно тратить деньги")));
    items.append(QPair<int, QSharedPointer<Item>>(1, QSharedPointer<Food>::create("Хлеб", "+5", 5)));
    items.append(QPair<int, QSharedPointer<Item>>(10, QSharedPointer<Food>::create("Болотный эликсир", "+7", 7)));
    items.append(QPair<int, QSharedPointer<Item>>(10, QSharedPointer<Food>::create("Яд", "Для отважных (-50)", -50)));
}

int Shop::rowCount(const QModelIndex &parent) const
{
    return items.size();
}

int Shop::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant Shop::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
            return QVariant();
    }

    if (index.row() < 0 || index.row() >= items.size() || index.column() < 0 || index.column() >= 3){
           return QVariant();
    }

     if (role == Qt::DisplayRole){
         if(index.column() == 0){
            return items[index.row()].first;
         }
         else if(index.column() == 1){
            return items[index.row()].second->getName();
         }
         else if(index.column() == 2){
            return items[index.row()].second->getDescription();
         }
     }

     return QVariant();
}

QVariant Shop::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Orientation::Horizontal){
        if(section == 0){
            return "Цена";
        }
        else if(section == 1){
            return "Имя";
        }
        else if(section == 2){
            return "Описание";
        }
    }
    return QVariant();
}

