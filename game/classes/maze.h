#ifndef MAZE_H
#define MAZE_H
#include <QList>
#include "room.h"

class Game;

class Maze
{
public:
    Maze(Game* game);

    QList<Room> rooms;
    Room& operator[](int index);
private:
    void _init(Game *game);
    Game* game;
};

#endif // MAZE_H
