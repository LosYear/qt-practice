#include <QMessageBox>
#include "battledialog.h"
#include "ui_battledialog.h"

BattleDialog::BattleDialog(Battle *b, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleDialog),
    battle(b)
{
    ui->setupUi(this);

    ui->heroNameLabel->setText(battle->getHero()->name);
    ui->enemyNameLabel->setText(battle->getEnemy()->name);

    ui->heroHealth->setValue(battle->getHero()->getHealth());
    ui->enemyHealth->setMaximum(battle->getEnemy()->getHealth());
    ui->enemyHealth->setValue(battle->getEnemy()->getHealth());

    QObject::connect(battle->getHero(), SIGNAL(health_changed(int)), ui->heroHealth, SLOT(setValue(int)));
    QObject::connect(battle->getEnemy(), SIGNAL(health_changed(int)), ui->enemyHealth, SLOT(setValue(int)));

    QObject::connect(battle,  SIGNAL(battle_hit(Actor*,Actor*,int)), this, SLOT(battleHit(Actor*,Actor*,int)));
    QObject::connect(ui->attackButton, SIGNAL(clicked(bool)), battle, SLOT(hero_attack()));;
    QObject::connect(battle,  SIGNAL(battle_finished(Actor*,Actor*)), this, SLOT(battleFinished(Actor*,Actor*)));
}

BattleDialog::~BattleDialog()
{
    delete ui;
}

void BattleDialog::battleHit(Actor *from, Actor *to, int damage)
{
    ui->history->addItem("Игрок " + from->name + " нанес урон игроку " + to->name + " в размере " + QString::number(damage));
}

void BattleDialog::battleFinished(Actor *winner, Actor *looser)
{
    QMessageBox msg;
    msg.setText("Сражение завершено, победил: " + winner->name);
    msg.exec();

    this->accept();
}

void BattleDialog::on_runButton_clicked()
{
    battleFinished(battle->getEnemy(), battle->getHero());
}

void BattleDialog::on_BattleDialog_rejected()
{
    battleFinished(battle->getEnemy(), battle->getHero());
}
