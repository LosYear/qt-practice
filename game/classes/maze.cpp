#include "maze.h"

Maze::Maze()
{
    _init();
}

void Maze::_init()
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
}

const Room& Maze::operator[](int index) const{
    return rooms[index];
}
