#include "food.h"

Food::Food(QString name, QString description, int d)
    : Item(name, description), delta(d)
{

}

bool Food::useOnce() const
{
    return true;
}

void Food::consume(Hero *hero)
{
    hero->changeHealth(delta);
}
