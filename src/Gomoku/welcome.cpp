#include "welcome.h"
#include "ui_welcome.h"
//欢迎窗口
welcome::welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);        //初始化
    setWindowTitle(tr("五子棋"));
    setFixedSize(400, 266);
}

welcome::~welcome()
{
    delete ui;
}

void welcome::paintEvent(QPaintEvent *){  //画背景
    QPainter painter(this);
    painter.drawPixmap(QRect(0,0,400,266), QPixmap("./timg.jpg"));
    painter.setRenderHint(QPainter::Antialiasing,true);
}

void welcome::on_withAI_clicked()  //人机对战
{
    g->setModeflag(1);
    //this->hide();
    mw->show();
}

void welcome::on_twoPlayers_clicked() //双人对战
{
    g->setModeflag(0);
    //this->hide();
    log->show();
}

void welcome::on_Enroll_clicked()  //注册
{
    er->show();
}

void welcome::on_check_RANK_clicked()  //排名
{
    sl->show();
}
