#ifndef ENROLL_H
#define ENROLL_H

#include<iostream>
#include <QDialog>
#include <QPainter>
#include <QRadioButton>
#include <QButtonGroup>
#include "global.h"
#include "user.h"
#include "enroll_success.h"
#include "enroll_warning.h"
#include "enroll_warning2.h"
#include "enroll_warning3.h"
#include "enroll_warning4.h"

using namespace std;
/////////////////注册窗口//////////////////
namespace Ui {
class enroll;
}

class enroll : public QDialog
{
    Q_OBJECT

public:
    explicit enroll(QWidget *parent = 0);
    ~enroll();

private slots:
    void on_Register_clicked();//注册按钮

    void on_Boy_clicked();//“男”选项

    void on_Girl_clicked();//“女”选项

    void quit_slot();//退出

private:
    Ui::enroll *ui;
    void paintEvent(QPaintEvent*);
    GLOBALA *g=new GLOBALA;
    User *u=new User;
    enroll_success *es=new enroll_success;//注册成功弹出窗口
    enroll_warning *er=new enroll_warning;//登录失败弹出窗口1
    enroll_warning2 *er2=new enroll_warning2;//登录失败弹出窗口2
    enroll_warning3 *er3=new enroll_warning3;//登录失败弹出窗口3
    enroll_warning4 *er4=new enroll_warning4;//登录失败弹出窗口4

    /*  用户变量  */
    QString UserName;//登录名
    QString Password;//密码
    QString NickName;//昵称
    QString gender;//性别
    QString id_for_user_image;
    QString total_score_earned;
    QString total_game_played;
    QString total_wins;
};

#endif // ENROLL_H
