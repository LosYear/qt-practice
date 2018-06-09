#include "hero.h"
#include "shield.h"
#include "weapon.h"

Hero::Hero(Maze* _maze, QString _name, QObject *parent) : Actor(_name, 70, parent)
{
    maze = _maze;
    currentRoom = 0;
    money = 50;

    model = new HeroModel(this);
}

void Hero::move(Direction direction)
{
    currentRoom = (*maze)[currentRoom][direction];

    emit hero_moved(currentRoom);
}

void Hero::addItem(QSharedPointer<Item> item)
{
    model->beginResetModel();

    inventory.append(item);

    model->endResetModel();
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

void Hero::useItem(int index)
{
    inventory[index]->consume(this);

    if(inventory[index]->useOnce()){
        model->beginResetModel();
        inventory.removeAt(index);
        model->endResetModel();
    }
}

HeroModel *Hero::getModel() const
{
    return model;
}

int Hero::getShield() const
{
    int max = 0;
    for(int i = 0; i < inventory.size(); ++i){
        Shield* s = dynamic_cast<Shield*>(inventory[i].get());

        if (s != nullptr && max < s->getShield()){
            max = s->getShield();
        }
    }

    return max;
}

int Hero::getDamage() const
{
    int max = 3;
    for(int i = 0; i < inventory.size(); ++i){
        Weapon* s = dynamic_cast<Weapon*>(inventory[i].get());

        if (s != nullptr && max < s->getDamage()){
            max = s->getDamage();
        }
    }

    return max;
}

int HeroModel::rowCount(const QModelIndex &parent) const
{
    return hero->inventory.count();
}

QVariant HeroModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
            return QVariant();
    }

    if (index.row() < 0 || index.row() >= hero->inventory.size()){
           return QVariant();
    }

     if (role == Qt::DisplayRole){
        return hero->inventory[index.row()]->getName();
     }
     else if(role == Qt::ToolTipRole){
        return hero->inventory[index.row()]->getDescription();
     }

    return QVariant();
}

HeroModel::HeroModel(Hero *h) : hero(h)
{

}
