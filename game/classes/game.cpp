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
    hero.addItem(QSharedPointer<Food>::create("Хлеб",
                                              "Увеличивает жизнь на 1",
                                              1));

    addEnemy(&maze[1], new Enemy("Бизон Хиггса", 10, 1, 0, 40, this));
    addEnemy(&maze[2], new Enemy("Крякен", 10, 3, 0, 20, this));
    addEnemy(&maze[7], new Enemy("Бронегрызный Хомяк", 20, 30, 2, 20, this));
}

void Game::peekItem(int itemIndex)
{
    int room = hero.currentRoom;

    QSharedPointer<Item> item = maze[room].peekItem(itemIndex);
    item->peek(&hero);
}

void Game::addEnemy(Room *room, Enemy *enemy)
{
    enemies.insert(room, enemy);
}

void Game::battle(Hero *hero, Enemy *enemy)
{
    Battle* b = new Battle(hero, enemy, this);

    emit battle_started(b);

    if(enemy->isAlive() || !hero->isAlive()){
        emit game_over(false);
    }
    else{
        enemies.remove(&maze[hero->currentRoom]);
    }
}

void Game::heroMoved(int room)
{
    Room* r = &maze[room];

    if(enemies.contains(r)){
        battle(&hero, enemies[r]);
    }
}
