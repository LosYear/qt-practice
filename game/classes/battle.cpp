#include "battle.h"

Battle::Battle(Hero *h, Enemy *e, QObject *parent) : QObject(parent),
    hero(h), enemy(e)
{

}

Hero *Battle::getHero()
{
    return hero;
}

Enemy *Battle::getEnemy()
{
    return enemy;
}
