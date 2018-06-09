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
    int hitDamage(int hitLevel, int shieldLevel) const;
    void attack(Actor* from, Actor* to);

signals:
    void battle_hit(Actor* from, Actor* to, int damage);
    void battle_finished(Actor* winner, Actor* looser);

public slots:
    void hero_attack();
private:
    Hero* hero;
    Enemy* enemy;
    int timer;

    void timerEvent(QTimerEvent *event);
};

#endif // BATTLE_H
