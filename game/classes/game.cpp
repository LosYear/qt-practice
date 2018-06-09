#include "game.h"
#include "food.h"

Game::Game(QString name) :
    maze(this),
    hero(&maze, name)
{
    QObject::connect(&hero, SIGNAL(hero_moved(int)), this, SLOT(heroMoved(int)));

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

void Game::addEnemy(Room *room, Enemy *enemy)
{
    enemies[room] = enemy;
}

void Game::battle(Hero *hero, Enemy *enemy)
{
    Battle* b = new Battle(hero, enemy, this);

    emit battle_started(b);
}

void Game::heroMoved(int room)
{
    Room* r = &maze[room];

    if(enemies.contains(r)){
        battle(&hero, enemies[r]);
    }
}
