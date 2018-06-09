#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>
#include "hero.h"
#include "enemy.h"

class Battle : public QObject
{
    Q_OBJECT
public:
    explicit Battle(Hero* h, Enemy* e, QObject *parent = nullptr);

    Hero* getHero();
    Enemy* getEnemy();

signals:

public slots:
private:
    Hero* hero;
    Enemy* enemy;
};

#endif // BATTLE_H
