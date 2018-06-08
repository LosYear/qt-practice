#include "room.h"

Room::Room(QString roomName, QString roomDescr, int n, int e, int s, int w)
    : name(roomName), description(roomDescr){
    neighbourRooms[Direction::North] = n;
    neighbourRooms[Direction::East] = e;
    neighbourRooms[Direction::South] = s;
    neighbourRooms[Direction::West] = w;
}

int Room::operator[](Direction direction) const{
    return neighbourRooms[direction];
}

void Room::putItem(QSharedPointer<Item> item)
{
    items.append(item);
}

QList<QSharedPointer<Item> > Room::visibleItems(Hero *hero) const
{
    return items;
}

QSharedPointer<Item> Room::peekItem(int index)
{
    QSharedPointer<Item> item = items[index];
    items.removeAt(index);
    return item;
}
