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
