#include "enemy.h"

Enemy::Enemy(QString name, int health, int d, int shield,
             int prob, QObject* parent) :
    Actor(name, health, parent), damage(d), shieldLevel(shield), strikeProbability(prob)
{

}

int Enemy::getDamage() const
{
    return damage;
}

int Enemy::getShield() const
{
    return shieldLevel;
}

int Enemy::getStrikeProbability() const
{
    return strikeProbability;
}
