#include <QMessageBox>

#include "shopwindow.h"
#include "ui_shopwindow.h"

ShopWindow::ShopWindow(Hero *h, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShopWindow),
    hero(h)
{
    ui->setupUi(this);
    ui->moneyDisplay->display(h->getMoney());
    ui->tableView->setModel(&shop);

    QObject::connect(hero, SIGNAL(money_changed(int)), ui->moneyDisplay, SLOT(display(int)));


}

ShopWindow::~ShopWindow()
{
    delete ui;
}

void ShopWindow::on_closeButton_clicked()
{
    this->close();
}

void ShopWindow::on_buyButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()){
        return;
    }

    int row = index.row();

    if(hero->changeMoney(shop.items[row].first)){
        hero->addItem(shop.items[row].second);
    }
    else{
        QMessageBox box;
        box.setText("Недостаточно средств");
        box.exec();
    }
}

void ShopWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    on_buyButton_clicked();
}
