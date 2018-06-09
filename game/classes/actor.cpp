#include "actor.h"

Actor::Actor(QString _name, int h, QObject *parent) : QObject(parent),
    name(_name), health(h)
{

}


int Actor::getHealth() const
{
    return health;
}

void Actor::changeHealth(int health_delta)
{
    if(health + health_delta > 100){
        health = 100;
    }
    else{
        health += health_delta;
    }

    if(health < 0){
        health = 0;
    }

    emit health_changed(health);
}

bool Actor::isAlive() const
{
    return health > 0;
}
