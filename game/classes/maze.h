#ifndef MAZE_H
#define MAZE_H
#include <QList>
#include "room.h"

class Maze
{
public:
    Maze();

    QList<Room> rooms;
    const Room& operator[](int index) const;
private:
    void _init();
};

#endif // MAZE_H
