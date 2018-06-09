#ifndef ACTOR_H
#define ACTOR_H
#include <QString>
#include <QObject>

class Actor : public QObject
{
    Q_OBJECT
public:
    Actor(QString _name, int h, QObject *parent);

    QString name;
    int health;

    int getHealth() const;
    void changeHealth(int health_delta);
    bool isAlive() const;

    virtual int getShield() const = 0;
    virtual int getDamage() const = 0;

signals:
    void health_changed(int health);
};

#endif // ACTOR_H
