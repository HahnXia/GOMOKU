#include "win2_show.h"
#include "ui_win2_show.h"
//胜利窗口2
win2_show::win2_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win2_show)
{
    ui->setupUi(this);
}

win2_show::~win2_show()
{
    delete ui;
}


void win2_show::on_Quitgame_clicked()//退出游戏
{
    this->close();
    emit quit_Signal();
}

void win2_show::on_Restart_clicked()//重新开始
{
    this->close();
    emit restart_Signal();
}
