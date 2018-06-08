#include "hero.h"

Hero::Hero(Maze* _maze, QString _name, QObject *parent) : QAbstractListModel(parent)
{
    maze = _maze;
    currentRoom = 0;
    health = 50;
    money = 50;
    name = _name;
}

void Hero::move(Direction direction)
{
    currentRoom = (*maze)[currentRoom][direction];

    emit hero_moved(currentRoom);
}

void Hero::addItem(QSharedPointer<Item> item)
{
    beginResetModel();

    inventory.append(item);

    endResetModel();
}

const QList<QSharedPointer<Item> > &Hero::getItems() const
{
    return inventory;
}

bool Hero::changeMoney(int delta)
{
    if(money - delta < 0){
        return false;
    }


    money -= delta;
    emit money_changed(money);
    return true;
}

int Hero::getMoney() const
{
    return money;;
}

int Hero::getHealth() const
{
    return health;
}

void Hero::changeHealth(int health_delta)
{
    if(health + health_delta > 100){
        health = 100;
    }
    else{
        health += health_delta;
    }

    emit health_changed(health);
}

void Hero::useItem(int index)
{
    inventory[index]->consume(this);

    if(inventory[index]->useOnce()){
        beginResetModel();
        inventory.removeAt(index);
        endResetModel();
    }
}

int Hero::rowCount(const QModelIndex &parent) const
{
    return inventory.count();
}

QVariant Hero::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
            return QVariant();
    }

    if (index.row() < 0 || index.row() >= inventory.size()){
           return QVariant();
    }

     if (role == Qt::DisplayRole){
        return inventory[index.row()]->getName();
     }
     else if(role == Qt::ToolTipRole){
        return inventory[index.row()]->getDescription();
     }

    return QVariant();
}
