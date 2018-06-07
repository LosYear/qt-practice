#ifndef HERO_H
#define HERO_H

#include <QObject>
#include <QString>
#include <QSharedPointer>
#include "maze.h"

class Hero : public QObject
{
    Q_OBJECT
public:
    explicit Hero(Maze* _maze, QString _name, QObject *parent = nullptr);

    void move(Direction direction);

    Maze* maze;
    int currentRoom;
    int healt;
    int money;
    QString name;

signals:
    void hero_moved(int room);

public slots:
};

#endif // HERO_H
