#ifndef ROOM_H
#define ROOM_H
#include <QString>
#include <QMap>

#include "direction.h"

class Room
{
public:
    QString name;
    QString description;

    QMap<Direction, int> neighbourRooms;

    Room(QString roomName, QString roomDescr, int n,
         int e, int s, int w);

    int operator[](Direction direction) const;
};

#endif // ROOM_H
