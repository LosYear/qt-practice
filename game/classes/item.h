#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QEnableSharedFromThis>

class Hero;

class Item : public QEnableSharedFromThis<Item>
{
public:
    Item(QString name, QString description);

    const QString getName() const;
    const QString getDescription() const;

    virtual void consume(Hero* hero){};
    virtual bool useOnce() const;
    virtual void peek(Hero* hero);
protected:
    QString _name;
    QString _description;
};

#endif // ITEM_H
