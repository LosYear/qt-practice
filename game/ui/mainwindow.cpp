#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shopwindow.h"

MainWindow::MainWindow(Game* _game, QWidget *parent) :
    QMainWindow(parent),
    game(_game),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->itemsList->setModel(&game->hero);

    // No resize on hide
    QSizePolicy sp_retain = ui->goEastButton->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->goEastButton->setSizePolicy(sp_retain);
    ui->goWestButton->setSizePolicy(sp_retain);
    ui->goSouthButton->setSizePolicy(sp_retain);
    ui->goNorthButton->setSizePolicy(sp_retain);

    enterRoom(0);

    // Connect slots and signals
    QObject::connect(&game->hero, SIGNAL(money_changed(int)), this->ui->moneyCounter, SLOT(display(int)));
    QObject::connect(&game->hero, SIGNAL(hero_moved(int)), this, SLOT(enterRoom(int)));
    QObject::connect(&game->hero, SIGNAL(health_changed(int)), ui->healthBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterRoom(int roomNumber)
{
    // Set info
    ui->heroNameLabel->setText(game->hero.name);
    ui->healthBar->setValue(game->hero.health);
    ui->moneyCounter->display(game->hero.money);

    // Set room info
    ui->roomDescriptionLabel->setText(game->maze[roomNumber].description);

    // Set directions
    const Room& room = game->maze[roomNumber];

    if(room[Direction::West] != -1){
        ui->goWestButton->show();
        ui->goWestButton->setText(game->maze[room[Direction::West]].name);
    }
    else{
        ui->goWestButton->hide();
    }

    if(room[Direction::East] != -1){
        ui->goEastButton->show();
        ui->goEastButton->setText(game->maze[room[Direction::East]].name);
    }
    else{
        ui->goEastButton->hide();
    }

    if(room[Direction::North] != -1){
        ui->goNorthButton->show();
        ui->goNorthButton->setText(game->maze[room[Direction::North]].name);
    }
    else{
        ui->goNorthButton->hide();
    }

    if(room[Direction::South] != -1){
        ui->goSouthButton->show();
        ui->goSouthButton->setText(game->maze[room[Direction::South]].name);
    }
    else{
        ui->goSouthButton->hide();
    }

    // Show items
    ui->roomItems->clear();

    for(auto it = game->maze[roomNumber].items.begin(); it != game->maze[roomNumber].items.end(); ++it){
        ui->roomItems->addItem((*it)->getName());
    }
}


void MainWindow::on_goWestButton_clicked()
{
    game->hero.move(Direction::West);
}

void MainWindow::on_goNorthButton_clicked()
{
    game->hero.move(Direction::North);
}

void MainWindow::on_goSouthButton_clicked()
{
    game->hero.move(Direction::South);
}

void MainWindow::on_goEastButton_clicked()
{
    game->hero.move(Direction::East);
}

void MainWindow::on_openShopButton_clicked()
{
    ShopWindow shop(&game->hero);
    shop.exec();
}

void MainWindow::on_itemsList_doubleClicked(const QModelIndex &index)
{
    if(index.isValid()){
       game->hero.useItem(index.row());
    }
}

void MainWindow::on_roomItems_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->roomItems->currentRow();
    ui->roomItems->takeItem(index);
    game->peekItem(index);
}
