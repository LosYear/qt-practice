#include "maze.h"
#include "food.h"
#include "gold.h"
#include "game.h"
#include "enemy.h"

Maze::Maze(Game *game)
{
    _init(game);
}

void Maze::_init(Game* game)
{
    rooms.append(Room("Крыльцо", "Вы стоите на крыльце."
                                 " Перед Вами находится совершенно загадочная дверь",
                      1, -1, -1, -1));
    rooms.append(Room("Гостиная", "Вы попали в гостиную."
                                  " В камине сидит страшный жирный паук.",
                      -1, -1, 0, 2));
    rooms.append(Room("Кабинет", "Вы стоите в кабинете."
                                 " Книжный шкаф полон старинных книг",
                      -1, 1, -1, -1));
    rooms[0].items.append(QSharedPointer<Gold>::create("Мешочек с золотом", "", -20));
    rooms[1].items.append(QSharedPointer<Food>::create("Обед", "+15 к здоровью", 15));
    rooms[2].items.append(QSharedPointer<Food>::create("Ужин", "+15 к здоровью", 15));
}

Room& Maze::operator[](int index){
    return rooms[index];
}
