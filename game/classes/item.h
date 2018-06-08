#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Hero;

class Item
{
public:
    Item(QString name, QString description);

    const QString getName();
    const QString getDescription();

    virtual void consume(Hero* hero){};
    virtual bool useOnce() const;
protected:
    QString _name;
    QString _description;
};

#endif // ITEM_H
