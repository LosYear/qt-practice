#include "ui/mainwindow.h"
#include <QApplication>
#include "classes/game.h"
#include <QScopedPointer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game* game = new Game("test"); // @TODO: memory leak

    MainWindow w(game);
    w.show();

    return a.exec();
}
