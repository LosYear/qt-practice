#ifndef GAME_H
#define GAME_H
#include <QString>
#include <QSharedPointer>
#include "hero.h"
#include "maze.h"

class Game
{
public:
    Game(QString name);

    Hero hero;
    Maze maze;

    void peekItem(int itemIndex);

};

#endif // GAME_H
