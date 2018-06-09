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

    Hero hero;
    Maze maze;

    void peekItem(int itemIndex);
    void addEnemy(Room* room, Enemy* enemy);

    QMap<Room*, Enemy*> enemies;

    void battle(Hero* hero, Enemy* enemy);

signals:
    void battle_started(Battle* battle);

public slots:
    void heroMoved(int room);

};

#endif // GAME_H
