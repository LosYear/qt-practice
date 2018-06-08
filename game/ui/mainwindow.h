#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../classes/game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Game* _game, QWidget *parent = 0);
    ~MainWindow();

    Game* game;

private:
    Ui::MainWindow *ui;

private slots:
    void on_goWestButton_clicked();
    void on_goNorthButton_clicked();
    void on_goSouthButton_clicked();
    void on_goEastButton_clicked();
    void enterRoom(int roomNumber);
    void on_openShopButton_clicked();
    void on_itemsList_doubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
