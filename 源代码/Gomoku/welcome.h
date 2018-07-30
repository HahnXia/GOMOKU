#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include <QPainter>
#include "global.h"
#include "mainwindow.h"
#include "login.h"
#include "enroll.h"
#include "sky_ladder.h"
//欢迎窗口
namespace Ui {
class welcome;
}

class welcome : public QDialog
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = 0);
    ~welcome();

private slots:
    void on_withAI_clicked();//人机对战

    void on_twoPlayers_clicked();//双人对战

    void on_Enroll_clicked();//注册

    void on_check_RANK_clicked();//排名

private:
    Ui::welcome *ui;
    void paintEvent(QPaintEvent*);
    MainWindow *mw =new MainWindow; //主对战窗口
    GLOBALA *g=new GLOBALA;
    login *log=new login;  //登录窗口
    enroll *er=new enroll;  //注册窗口
    Sky_Ladder *sl=new Sky_Ladder; //排名窗口
};

#endif // WELCOME_H
