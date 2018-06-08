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

    Maze* maze;
    int currentRoom;
    int healt;
    int money;
    QString name;
    QList<QSharedPointer<Item>> inventory;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:
    void hero_moved(int room);

public slots:
};

#endif // HERO_H
