#include "win1_show.h"
#include "ui_win1_show.h"
//胜利窗口1
win1_show::win1_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win1_show)
{
    ui->setupUi(this);
}

win1_show::~win1_show()
{
    delete ui;
}

void win1_show::on_Quitgame_clicked()//退出游戏
{
    this->close();
    emit quit_Signal();
}

void win1_show::on_Restart_clicked()//重新开始
{
    this->close();
    emit restart_Signal();
}
