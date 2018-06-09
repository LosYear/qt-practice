#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon : public Item
{
public:
    Weapon(QString name, QString description, int d);
    int getDamage() const;

    const int damage;
};

#endif // WEAPON_H
