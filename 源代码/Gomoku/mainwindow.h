#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "chessboard.h"
#include "global.h"
#include "win1_show.h"
#include "win2_show.h"
#include "ai.h"
#include "mytimer.h"
#include "user.h"

/////////对战主窗口///////////

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*);//用于画背景
//  void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);//鼠标松开事件
private slots:
    void on_Takeback_Player2_clicked(); //P2点悔棋。。。

    void on_Takeback_Player1_clicked();

    void on_Giveup_Player2_clicked();//P2点投降

    void on_Giveup_Player1_clicked();

public slots:
    void quit_Slot();
    void restart_Slot();
    void WhTimer_Slot();
    void BlTimer_Slot();
    void WhRoTimer_Slot();
    void BlRoTimer_Slot();

private:
    Ui::MainWindow *ui;
    int flag;  //黑白
    GLOBALA *g=new GLOBALA;
    Chessboard *cb=new Chessboard; //棋盘
    win1_show *win1=new win1_show; //胜利窗口1
    win2_show *win2=new win2_show; //胜利窗口2
    User *u=new User;    //用户

    QString UserName1,UserName2;

    mytimer *blackTime=new mytimer;//时间
    mytimer *whiteTime=new mytimer;
    mytimer *blackRoundTime=new mytimer;
    mytimer *whiteRoundTime=new mytimer;

    QTimer *WhTimer;   //白棋总时间
    QTimer *BlTimer;   //黑棋总时间
    QTimer *WhRoTimer; //白棋本轮时间
    QTimer *BlRoTimer; //黑棋本轮时间

};

#endif // MAINWINDOW_H
