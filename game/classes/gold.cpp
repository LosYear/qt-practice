#include "gold.h"
#include "hero.h"

Gold::Gold(QString name, QString description, int _amount)
    : Item(name, description), amount(_amount)
{

}

void Gold::peek(Hero *hero)
{
    hero->changeMoney(amount);
}
