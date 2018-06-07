#include "ui/mainwindow.h"
#include <QApplication>
#include "classes/game.h"
#include <QScopedPointer>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Game* game = new Game(QInputDialog::getText(nullptr, "Имя", "Введите имя игрока")); // @TODO: memory leak

    MainWindow w(game);
    w.show();

    return a.exec();
}
