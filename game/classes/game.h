#ifndef GAME_H
#define GAME_H
#include <QString>
#include <QSharedPointer>
#include <QMap>
#include <QObject>
#include "hero.h"
#include "maze.h"
#include "room.h"
#include "battle.h"
#include "enemy.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QString name);

    Maze maze;
    Hero hero;

    void peekItem(int itemIndex);
    void addEnemy(Room* room, Enemy* enemy);

    QMap<Room*, Enemy*> enemies;

    void battle(Hero* hero, Enemy* enemy);

signals:
    void battle_started(Battle* battle);
    void game_over(bool result);

public slots:
    void heroMoved(int room);

};

#endif // GAME_H
