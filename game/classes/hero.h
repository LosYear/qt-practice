#ifndef HERO_H
#define HERO_H

#include <QObject>
#include <QString>
#include <QSharedPointer>
#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include "maze.h"
#include "item.h"
#include "actor.h"

class HeroModel;

class Hero : public Actor
{
    Q_OBJECT
public:
    explicit Hero(Maze* _maze, QString _name, QObject *parent = nullptr);

    void move(Direction direction);
    void addItem(QSharedPointer<Item> item);
    const QList<QSharedPointer<Item> > &getItems() const;
    bool changeMoney(int delta);
    int getMoney() const;
    void useItem(int index);

    Maze* maze;
    int currentRoom;
    int money;
    QList<QSharedPointer<Item>> inventory;

    HeroModel* getModel() const;
    int getShield() const;
    int getDamage() const;

signals:
    void hero_moved(int room);
    void money_changed(int money);

public slots:
private:
    HeroModel* model;
};

class HeroModel : public QAbstractListModel{
    friend class Hero;
public:
    HeroModel(Hero* h);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    Hero* hero;
};

#endif // HERO_H
