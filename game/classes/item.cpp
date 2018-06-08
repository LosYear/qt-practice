#include "item.h"

Item::Item(QString name, QString description):
    _name(name), _description(description)
{

}

const QString Item::getName() const
{
    return _name;
}

const QString Item::getDescription() const
{
    return _description;
}

bool Item::useOnce() const
{
    return false;
}
