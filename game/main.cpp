#include "ui/mainwindow.h"
#include <QApplication>
#include "classes/game.h"
#include <QScopedPointer>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString name = QInputDialog::getText(nullptr, "Имя", "Введите имя игрока");
    Game* game = new Game(name); // @TODO: memory leak

    MainWindow w(game);
    w.show();

    return a.exec();
}
