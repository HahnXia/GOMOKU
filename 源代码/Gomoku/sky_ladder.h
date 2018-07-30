#ifndef SKY_LADDER_H
#define SKY_LADDER_H
#include <QStringList>
#include <QPainter>
#include <QWidget>
#include "user.h"
//排名窗口
namespace Ui {
class Sky_Ladder;
}

class Sky_Ladder : public QWidget
{
    Q_OBJECT

public:
    explicit Sky_Ladder(QWidget *parent = 0);
    ~Sky_Ladder();

private:
    void paintEvent(QPaintEvent*);//用于画背景
    Ui::Sky_Ladder *ui;
    User *u=new User;
    QStringList SkyLadder;  //记录排名数据
};

#endif // SKY_LADDER_H
