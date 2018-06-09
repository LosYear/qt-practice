#ifndef SHIELD_H
#define SHIELD_H
#include "item.h"

class Shield : public Item
{
public:
    Shield(QString name, QString description, int sl);

    int getShield() const;

    const int shieldLevel;
};

#endif // SHIELD_H
