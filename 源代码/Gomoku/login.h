#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QPainter>
#include "mainwindow.h"
#include "user.h"
#include "global.h"
#include "login_warning.h"
#include "login_warning3.h"
#include "login_warning2.h"
#include "login_warning4.h"
//登录界面
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_LoginConfirm_clicked();//按下登录按钮

private:
    Ui::login *ui;
    void paintEvent(QPaintEvent*);//用于画背景
    User *u=new User;
    MainWindow *mw=new MainWindow;//主窗口
    login_warning *lw=new login_warning;//警告窗口
    login_warning2 *lw2=new login_warning2;
    login_warning3 *lw3=new login_warning3;
    login_warning4 *lw4=new login_warning4;
    GLOBALA *g=new GLOBALA;

    QString UserName1,UserName2;//记录输入的用户名密码
    QString Password1,Password2;

};

#endif // LOGIN_H
