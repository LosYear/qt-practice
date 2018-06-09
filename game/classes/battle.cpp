#include "battle.h"
#include <QRandomGenerator>

Battle::Battle(Hero *h, Enemy *e, QObject *parent) : QObject(parent),
    hero(h), enemy(e)
{
    timer = startTimer(500);
}

Hero *Battle::getHero()
{
    return hero;
}

Enemy *Battle::getEnemy()
{
    return enemy;
}

int Battle::hitDamage(int hitLevel, int shieldLevel) const
{
    int level = qMax(hitLevel - shieldLevel, 1);
    level = qMin(10, level);

    return QRandomGenerator::global()->bounded(1, level + 1);
}

void Battle::attack(Actor *from, Actor *to)
{
    int d = hitDamage(from->getDamage(), to->getShield());
    emit battle_hit(from, to, d);
    to->changeHealth(-d);

    if(!to->isAlive()){
       killTimer(timer);
       emit battle_finished(from, to);
    }
}

void Battle::hero_attack()
{
    attack(hero, enemy);
}

void Battle::timerEvent(QTimerEvent *event)
{
    if(QRandomGenerator::global()->bounded(0, 100) < enemy->getStrikeProbability()){
        attack(enemy, hero);
    }
}
