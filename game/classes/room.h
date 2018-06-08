#ifndef ROOM_H
#define ROOM_H
#include <QString>
#include <QMap>
#include <QList>
#include <QSharedPointer>

#include "direction.h"
#include "item.h"

class Room
{
public:
    QString name;
    QString description;

    QMap<Direction, int> neighbourRooms;
    QList<QSharedPointer<Item>> items;

    Room(QString roomName, QString roomDescr, int n,
         int e, int s, int w);

    int operator[](Direction direction) const;
    void putItem(QSharedPointer<Item> item);
    QList<QSharedPointer<Item>> visibleItems(Hero* hero) const;
    QSharedPointer<Item> peekItem(int index);
};

#endif // ROOM_H
