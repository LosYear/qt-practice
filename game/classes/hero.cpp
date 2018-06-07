#include "hero.h"

Hero::Hero(Maze* _maze, QString _name, QObject *parent) : QObject(parent)
{
    maze = _maze;
    currentRoom = 0;
    healt = 100;
    money = 50;
    name = _name;
}

void Hero::move(Direction direction)
{
    currentRoom = (*maze)[currentRoom][direction];

    emit hero_moved(currentRoom);
}
