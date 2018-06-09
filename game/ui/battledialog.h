#ifndef BATTLEDIALOG_H
#define BATTLEDIALOG_H

#include <QDialog>
#include "../classes/battle.h"

namespace Ui {
class BattleDialog;
}

class BattleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BattleDialog(Battle* b, QWidget *parent = 0);
    ~BattleDialog();

private:
    Ui::BattleDialog *ui;
    Battle* battle;
private slots:
    void battleHit(Actor* from, Actor *to, int damage);
    void battleFinished(Actor* winner, Actor* looser);
    void on_runButton_clicked();
    void on_BattleDialog_rejected();
};

#endif // BATTLEDIALOG_H
