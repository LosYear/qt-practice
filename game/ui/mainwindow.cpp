#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Game* _game, QWidget *parent) :
    QMainWindow(parent),
    game(_game),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    enterRoom(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterRoom(int room)
{

}
