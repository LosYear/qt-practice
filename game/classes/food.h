#ifndef FOOD_H
#define FOOD_H
#include "item.h"

class Food : public Item
{
public:
    Food(QString name, QString description, int d);

    const int delta;

    bool useOnce() const;
};

#endif // FOOD_H
