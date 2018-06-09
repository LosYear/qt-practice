#include "weapon.h"

Weapon::Weapon(QString name, QString description, int d)
    : Item(name, description), damage(d)
{

}

int Weapon::getDamage() const
{
    return damage;
}
