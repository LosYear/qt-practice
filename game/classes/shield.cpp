#include "shield.h"

Shield::Shield(QString name, QString description, int sl)
    : Item(name, description), shieldLevel(sl)
{

}

int Shield::getShield() const
{
    return shieldLevel;
}
