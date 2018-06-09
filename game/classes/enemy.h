#ifndef ENEMY_H
#define ENEMY_H
#include "actor.h"

class Enemy : public Actor
{
    Q_OBJECT
public:
    Enemy(QString name, int health, int d, int shield,
          int prob, QObject* parent = nullptr);

    const int damage;
    const int shieldLevel;
    const int strikeProbability;

    int getDamage() const;
    int getShield() const;
    int getStrikeProbability() const;
};

#endif // ENEMY_H
