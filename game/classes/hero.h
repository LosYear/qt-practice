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

class Hero : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Hero(Maze* _maze, QString _name, QObject *parent = nullptr);

    void move(Direction direction);
    void addItem(QSharedPointer<Item> item);
    const QList<QSharedPointer<Item> > &getItems() const;
    bool changeMoney(int delta);
    int getMoney() const;
    int getHealth() const;
    void changeHealth(int health_delta);
    void useItem(int index);

    Maze* maze;
    int currentRoom;
    int health;
    int money;
    QString name;
    QList<QSharedPointer<Item>> inventory;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:
    void hero_moved(int room);
    void money_changed(int money);
    void health_changed(int health);

public slots:
};

#endif // HERO_H
