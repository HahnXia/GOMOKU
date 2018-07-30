#include "sky_ladder.h"
#include "ui_sky_ladder.h"
#include <QDebug>
//排名窗口
Sky_Ladder::Sky_Ladder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sky_Ladder)
{
    ui->setupUi(this);
    setWindowTitle(tr("天梯排行"));//显示排名
    setFixedSize(400, 266);
    ui->N1->setText(u->sky_ladder().at(0));
    ui->T1->setText(u->sky_ladder().at(1));
    ui->N2->setText(u->sky_ladder().at(2));
    ui->T2->setText(u->sky_ladder().at(3));
    ui->N3->setText(u->sky_ladder().at(4));
    ui->T3->setText(u->sky_ladder().at(5));
    ui->N4->setText(u->sky_ladder().at(6));
    ui->T4->setText(u->sky_ladder().at(7));
    ui->N5->setText(u->sky_ladder().at(8));
    ui->T5->setText(u->sky_ladder().at(9));
}

void Sky_Ladder::paintEvent(QPaintEvent *){//画背景
    QPainter painter(this);
    painter.drawPixmap(QRect(0,0,400,266), QPixmap("./timg.jpg"));
    painter.setRenderHint(QPainter::Antialiasing,true);
}

Sky_Ladder::~Sky_Ladder()
{
    delete ui;
}
