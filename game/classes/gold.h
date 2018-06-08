#ifndef GOLD_H
#define GOLD_H
#include "item.h"

class Gold : public Item
{
public:
    Gold(QString name, QString description, int _amount);

    const int amount;

    void peek(Hero* hero);
};

#endif // GOLD_H
