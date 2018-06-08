#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QDialog>
#include "../classes/hero.h"
#include "../classes/shop.h"

namespace Ui {
class ShopWindow;
}

class ShopWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShopWindow(Hero* h, QWidget *parent = 0);
    ~ShopWindow();

private slots:
    void on_closeButton_clicked();

    void on_buyButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::ShopWindow *ui;
    Hero* hero;
    Shop shop;
};

#endif // SHOPWINDOW_H
