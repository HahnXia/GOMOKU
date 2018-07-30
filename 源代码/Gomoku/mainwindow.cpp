#include "mainwindow.h"
#include "ui_mainwindow.h"

///////对战主窗口/////////

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("五子棋"));
    flag=0;

    centralWidget()->setMouseTracking(true);  //使鼠标正在移动时程序也能追踪鼠标位置
    setMouseTracking(true);
    connect(win1,SIGNAL(quit_Signal()),this,SLOT(quit_Slot()));//关联按钮和窗口
    connect(win2,SIGNAL(quit_Signal()),this,SLOT(quit_Slot()));
    connect(win1,SIGNAL(restart_Signal()),this,SLOT(restart_Slot()));
    connect(win2,SIGNAL(restart_Signal()),this,SLOT(restart_Slot()));

    WhTimer= new QTimer(this);//初始化时间 这是在构造函数里，为了刚进界面时候时间停止在相应时间
    BlTimer= new QTimer(this);
    WhRoTimer= new QTimer(this);
    BlRoTimer= new QTimer(this);
    blackTime->reset(12,0);
    whiteTime->reset(12,0);
    blackRoundTime->reset(0,30);
    whiteRoundTime->reset(0,30);

    QString temp;
    temp=blackRoundTime->getjointTime();
    ui->blackRoTime->setText(temp);
    temp=blackTime->getjointTime();
    ui->blackToTime->setText(temp);
    temp=whiteRoundTime->getjointTime();
    ui->whiteRoTime->setText(temp);
    temp=whiteTime->getjointTime();
    ui->whiteToTime->setText(temp);

    connect(WhTimer,SIGNAL(timeout()),this,SLOT(WhTimer_Slot())); //myTimer的计时slot和QTimer的信号相连
    connect(BlTimer,SIGNAL(timeout()),this,SLOT(BlTimer_Slot()));
    connect(WhRoTimer,SIGNAL(timeout()),this,SLOT(WhRoTimer_Slot()));
    connect(BlRoTimer,SIGNAL(timeout()),this,SLOT(BlRoTimer_Slot()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    /* 从GLOBALA获取用户名 */
    UserName1=g->getUserName1();
    UserName2=g->getUserName2();

/***************************************设置窗口大小*************************/
    if(g->getModeflag()==1){           //如果是人机对战
        this->setFixedSize(640,640);
        if(flag==0)
        cb->putChess(7,7);
        flag=1;
    }

    if(g->getModeflag()==0)            //如果是PVP
    this->setFixedSize(640+230,640);   // 230是旁边边框的宽度
/*************************************************************************/
//    int px=cb->getPX();//获取坐标
//    int py=cb->getPY();


/***************************************画棋盘*****************************/
    const int edge=40, cell_length=40, side_length=14*cell_length;
          //旁边的空隙长度  一格的长度；      棋盘边长
    QPen pen;
    QPainter painter(this);
    //画背景
    painter.drawPixmap(QRect(0,0,2*edge+side_length,2*edge+side_length), QPixmap("./chessboard.jpg"));
    painter.setRenderHint(QPainter::Antialiasing,true);
    //设置笔颜色和粗细
    painter.setPen(QPen(QColor(0,0,0),2));
////////////////画棋盘////////////////////////
    //画细线
    int i,j;
    for(i=0;i<=14;i++){
        painter.drawLine(edge,edge+i*40,edge+side_length,edge+i*40);
        painter.drawLine(edge+i*40,edge,edge+i*40,edge+side_length);
    }
    //画四周粗线
    painter.setPen(QPen(Qt::black,4));
    painter.drawLine(edge,edge,edge+side_length,edge);
    painter.drawLine(edge,edge+side_length,edge+side_length,edge+side_length);
    painter.drawLine(edge,edge,edge,edge+side_length);
    painter.drawLine(edge+side_length,edge,edge+side_length,edge+side_length);
    //画五个黑点
    painter.setPen(QColor(Qt::black));
    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(3*cell_length+edge-5,3*cell_length+edge-5,10,10);
    painter.drawEllipse(11*cell_length+edge-5,3*cell_length+edge-5,10,10);
    painter.drawEllipse(3*cell_length+edge-5,11*cell_length+edge-5,10,10);
    painter.drawEllipse(11*cell_length+edge-5,11*cell_length+edge-5,10,10);
    painter.drawEllipse(7*cell_length+edge-5,7*cell_length+edge-5,10,10);
/****************************************************************************************/


    /*****画红色提示标记************************************************/

//    int cx=edge+px*cell_length;  //center x
//    int cy=edge+py*cell_length;  //center y
//    painter.setPen(QPen(Qt::red,1));
//    if(px>0&&py>0){
//        painter.drawLine(cx-20,cy-5,cx-5,cy-5);
//        painter.drawLine(cx-5,cy-20,cx-5,cy-5);
//    }
//    if(px<14&&py>0){
//        painter.drawLine(cx+20,cy-5,cx+5,cy-5);
//        painter.drawLine(cx+5,cy-20,cx+5,cy-5);
//    }
//    if(px>0&&py<14){
//        painter.drawLine(cx-20,cy+5,cx-5,cy+5);
//        painter.drawLine(cx-5,cy+20,cx-5,cy+5);
//    }
//    if(px<14&&py<14){
//        painter.drawLine(cx+20,cy+5,cx+5,cy+5);
//        painter.drawLine(cx+5,cy+20,cx+5,cy+5);
//    }
    /************************************************************/



/***********************************画棋子**************************/
    for(i=0;i<=14;i++){
        for(j=0;j<=14;j++){
            if(cb->getChessType(i,j)==-1){
              painter.drawPixmap(QRect(edge+i*cell_length-17,edge+j*cell_length-17,34,34), QPixmap("./black.png"));
            }
            else if(cb->getChessType(i,j)==1){
              painter.drawPixmap(QRect(edge+i*cell_length-17,edge+j*cell_length-17,34,34), QPixmap("./white.png"));
            }
        }
    }
/*******************************************************************/

/***********************************用户信息显示**************************/
    this->ui->NickName1->setText(u->Check_nickname(UserName1));
    this->ui->NickName2->setText(u->Check_nickname(UserName2));
    double winrate1,winrate2;
    int total1,total2,win1,win2,score1,score2;
    score1=u->Check_total_score_earned(UserName1);
    score2=u->Check_total_score_earned(UserName2);
    total1=u->Check_total_game_played(UserName1);
    total2=u->Check_total_game_played(UserName2);
    win1=u->Check_total_wins(UserName1);
    win2=u->Check_total_wins(UserName2);
    if(total1==0){
        winrate1=0;
    }else{
        winrate1=(double)win1/total1;
    }
    if(total2==0){
        winrate2=0;
    }else{
        winrate2=(double)win2/total2;
    }
    winrate1*=100;
    winrate2*=100;
    QString score1str=QString::number(score1);
    QString score2str=QString::number(score2);
    QString winrate1str=QString::number(winrate1,'f',2); //保留小数点后两位
    QString winrate2str=QString::number(winrate2,'f',2);
    QString total1str=QString::number(total1);
    QString total2str=QString::number(total2);
    winrate1str+="%";
    winrate2str+="%";
    this->ui->winrate1->setText(winrate1str);
    this->ui->winrate2->setText(winrate2str);
    this->ui->total1->setText(total1str);
    this->ui->total2->setText(total2str);
    this->ui->Score1->setText(score1str);
    this->ui->Score2->setText(score2str);

}

// 这个函数原来是用来在鼠标当前位置棋盘上画红色标记，但是由于每次移动都会导致QTimer信号触发刷新，导致计时不对，后来取消了这个功能

//void MainWindow::mouseMoveEvent(QMouseEvent *event){
//    int edge=40;
//    //获得棋盘上的坐标px,py
//    int px=(event->pos().x()-edge/2)/40;
//    int py=(event->pos().y()-edge/2)/40;
//    cb->setPxPy(px,py);
//    //如果落在棋盘范围内就update
//    if(event->x()>=30&&event->x()<=610&&event->y()>=30&&event->y()<=610){
//        update();
//    }
//}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    int edge=40;
//  int px=cb->getPX(),py=cb->getPY();
    int px=(event->pos().x()-edge/2)/40;
    int py=(event->pos().y()-edge/2)/40;
    if(event->x()>=30&&event->x()<=610&&event->y()>=30&&event->y()<=610){
        if(cb->canbeput(px,py)){
            cb->putChess(px,py); //落子
            if(cb->getChessflag()==-1){
                BlRoTimer->start(1);
                BlTimer->start(1);
                whiteRoundTime->reset(0,30);
                WhRoTimer->stop();
                WhTimer->stop();
            }else{
                WhRoTimer->start(1);
                WhTimer->start(1);
                blackRoundTime->reset(0,30);
                BlRoTimer->stop();
                BlTimer->stop();

            }
            /*********************胜负判定************************/
            cb->Win();
            if(cb->getWinflag()==1){
                blackTime->reset(12,0);
                whiteTime->reset(12,0);
                blackRoundTime->reset(0,30);
                whiteRoundTime->reset(0,30);
                BlRoTimer->stop();
                BlTimer->stop();
                WhRoTimer->stop();
                WhTimer->stop();
                cb->setWinflagBack();
                if(g->getModeflag()!=1){
                    u->addScore(UserName1,5);
                    u->addScore(UserName2,-5);
                    u->addTotalGames(UserName2,1);
                    u->addTotalGames(UserName1,1);
                    u->addWinTimes(UserName1,1);
                }
                win1->exec();

            }else if(cb->getWinflag()==-1){
                blackTime->reset(12,0);
                whiteTime->reset(12,0);
                blackRoundTime->reset(0,30);
                whiteRoundTime->reset(0,30);
                BlRoTimer->stop();
                BlTimer->stop();
                WhRoTimer->stop();
                WhTimer->stop();
                cb->setWinflagBack();

                if(g->getModeflag()!=1){
                    u->addScore(UserName1,-5);
                    u->addScore(UserName2,5);
                    u->addTotalGames(UserName2,1);
                    u->addTotalGames(UserName1,1);
                    u->addWinTimes(UserName2,1);
                }
                win2->exec();

            }

            update();

            if(g->getModeflag()==1){                     //人机模式 电脑下棋
                aiputChess(cb);
                cb->Win();                               //电脑下完后判断胜利
                if(cb->getWinflag()==1){
                    blackTime->reset(12,0);
                    whiteTime->reset(12,0);
                    blackRoundTime->reset(0,30);
                    whiteRoundTime->reset(0,30);
                    BlRoTimer->stop();
                    BlTimer->stop();
                    WhRoTimer->stop();
                    WhTimer->stop();
                    cb->setWinflagBack();
                    win1->exec();
                }else if(cb->getWinflag()==-1){
                    blackTime->reset(12,0);
                    whiteTime->reset(12,0);
                    blackRoundTime->reset(0,30);
                    whiteRoundTime->reset(0,30);
                    BlRoTimer->stop();
                    BlTimer->stop();
                    WhRoTimer->stop();
                    WhTimer->stop();
                    cb->setWinflagBack();
                    win2->exec();
                }
                update();
            }
        }
    }
}


// 黑棋悔棋按钮
void MainWindow::on_Takeback_Player2_clicked()
{
    if(cb->getstepnum()>=1){
        if(cb->getChessflag()==1){
            cb->takeback();
            BlRoTimer->start(1);
            BlTimer->start(1);
            whiteRoundTime->reset(0,30);
            WhRoTimer->stop();
            WhTimer->stop();

            update();
        }
        else if(cb->getChessflag()==-1){
            cb->takeback();
            cb->takeback();
            update();
        }
    }

}

//白棋悔棋按钮
void MainWindow::on_Takeback_Player1_clicked()
{
    if(cb->getstepnum()>=1){
        if(cb->getChessflag()==-1){
            cb->takeback();
            WhRoTimer->start(1);
            WhTimer->start(1);
            blackRoundTime->reset(0,30);
            BlRoTimer->stop();
            BlTimer->stop();
            update();
        }
        else if(cb->getChessflag()==1){
            cb->takeback();
            cb->takeback();
            update();
        }
    }

}

//黑棋认输按钮
void MainWindow::on_Giveup_Player2_clicked()
{
    blackTime->reset(12,0);
    whiteTime->reset(12,0);
    blackRoundTime->reset(0,30);
    whiteRoundTime->reset(0,30);
    BlRoTimer->stop();
    BlTimer->stop();
    WhRoTimer->stop();
    WhTimer->stop();

    u->addScore(UserName1,5);
    u->addScore(UserName2,-5);
    u->addTotalGames(UserName2,1);
    u->addTotalGames(UserName1,1);
    u->addWinTimes(UserName1,1);
    win1->exec();
}

//白棋认输按钮
void MainWindow::on_Giveup_Player1_clicked()
{
    blackTime->reset(12,0);
    whiteTime->reset(12,0);
    blackRoundTime->reset(0,30);
    whiteRoundTime->reset(0,30);
    BlRoTimer->stop();
    BlTimer->stop();
    WhRoTimer->stop();
    WhTimer->stop();
    u->addScore(UserName1,-5);
    u->addScore(UserName2,5);
    u->addTotalGames(UserName2,1);
    u->addTotalGames(UserName1,1);
    u->addWinTimes(UserName2,1);
    win2->exec();
}

//退出
void MainWindow::quit_Slot(){
    cb->restartFunction();

    QString temp;
    temp=blackRoundTime->getjointTime();
    ui->blackRoTime->setText(temp);
    temp=blackTime->getjointTime();
    ui->blackToTime->setText(temp);
    temp=whiteRoundTime->getjointTime();
    ui->whiteRoTime->setText(temp);
    temp=whiteTime->getjointTime();
    ui->whiteToTime->setText(temp);
    this->close();
}


//重新开始
void MainWindow::restart_Slot(){
    cb->restartFunction();

    QString temp;
    temp=blackRoundTime->getjointTime();
    ui->blackRoTime->setText(temp);
    temp=blackTime->getjointTime();
    ui->blackToTime->setText(temp);
    temp=whiteRoundTime->getjointTime();
    ui->whiteRoTime->setText(temp);
    temp=whiteTime->getjointTime();
    ui->whiteToTime->setText(temp);

    // 用户那边计时，悔棋等信息也要更新
}



///////////////////////////////////////////////////////////
void MainWindow::BlTimer_Slot(){
    blackTime->internalCalculateSlot();
    if(blackTime->getSEC()!=60){              //此if语句防止秒=60时被显示
        QString temp;
        temp=blackTime->getjointTime();
        ui->blackToTime->setText(temp);
    }
    if(blackTime->getjointTime()=="00 : 00"){ //超时判负
        blackTime->reset(12,0);
        whiteTime->reset(12,0);
        blackRoundTime->reset(0,30);
        whiteRoundTime->reset(0,30);
        BlRoTimer->stop();
        BlTimer->stop();
        WhRoTimer->stop();
        WhTimer->stop();
        u->addScore(UserName1,5);
        u->addScore(UserName2,-5);
        u->addTotalGames(UserName2,1);
        u->addTotalGames(UserName1,1);
        u->addWinTimes(UserName1,1);
        win1->exec();
    }
}

void MainWindow::WhTimer_Slot(){
    whiteTime->internalCalculateSlot();
    if(whiteTime->getSEC()!=60){
        QString temp;
        temp=whiteTime->getjointTime();
        ui->whiteToTime->setText(temp);
    }
    if(whiteTime->getjointTime()=="00 : 00"  && g->getModeflag()!=1){ //人机模式下不会超时判负
        blackTime->reset(12,0);
        whiteTime->reset(12,0);
        blackRoundTime->reset(0,30);
        whiteRoundTime->reset(0,30);
        BlRoTimer->stop();
        BlTimer->stop();
        WhRoTimer->stop();
        WhTimer->stop();
        u->addScore(UserName1,-5);
        u->addScore(UserName2,5);
        u->addTotalGames(UserName2,1);
        u->addTotalGames(UserName1,1);
        u->addWinTimes(UserName2,1);
        win2->exec();
    }
}

void MainWindow::BlRoTimer_Slot(){
    QString temp;
    blackRoundTime->internalCalculateSlot();
    temp=blackRoundTime->getjointTime();
    ui->blackRoTime->setText(temp);
    if(blackRoundTime->getjointTime()=="00 : 00" ){
        blackTime->reset(12,0);
        whiteTime->reset(12,0);
        blackRoundTime->reset(0,30);
        whiteRoundTime->reset(0,30);
        BlRoTimer->stop();
        BlTimer->stop();
        WhRoTimer->stop();
        WhTimer->stop();
        u->addScore(UserName1,5);
        u->addScore(UserName2,-5);
        u->addTotalGames(UserName2,1);
        u->addTotalGames(UserName1,1);
        u->addWinTimes(UserName1,1);
        win1->exec();
    }
}

void MainWindow::WhRoTimer_Slot(){
    QString temp;
    temp=whiteRoundTime->getjointTime();
    whiteRoundTime->internalCalculateSlot();
    ui->whiteRoTime->setText(temp);
    if(whiteRoundTime->getjointTime()=="00 : 00"  && g->getModeflag()!=1){
        blackTime->reset(12,0);
        whiteTime->reset(12,0);
        blackRoundTime->reset(0,30);
        whiteRoundTime->reset(0,30);
        BlRoTimer->stop();
        BlTimer->stop();
        WhRoTimer->stop();
        WhTimer->stop();
        u->addScore(UserName1,-5);
        u->addScore(UserName2,5);
        u->addTotalGames(UserName2,1);
        u->addTotalGames(UserName1,1);
        u->addWinTimes(UserName2,1);
        win2->exec();
    }
}


