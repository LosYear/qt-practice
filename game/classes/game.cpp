#include "game.h"
#include "food.h"

Game::Game(QString name) :
    hero(&maze, name)
{
    hero.addItem(QSharedPointer<Food>::create("Бутерброд",
                                              "Увеличивает жизнь на 5",
                                              5));
    hero.addItem(QSharedPointer<Food>::create("Хлем",
                                              "Увеличивает жизнь на 1",
                                              1));
}

void Game::peekItem(int itemIndex)
{
    int room = hero.currentRoom;

    QSharedPointer<Item> item = maze[room].peekItem(itemIndex);
    item->peek(&hero);
}
