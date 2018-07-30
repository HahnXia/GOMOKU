#ifndef CHESSMAN_H
#define CHESSMAN_H

#include<iostream>
#include<vector>
#include<string.h>
#include <QMainWindow>
#include"QMessageBox"
#include <QtGui>
#include <QLabel>
#include "global.h"
#include <ctime>
#include <QTimer>

using namespace std;
class Chessman
{
private:
    int chessflag2; //0代表黑色 1代表白色
    int x;
    int y;      //坐标记录棋子在棋盘上的位置
    int No_step; //记录这是第几步
public:
    Chessman(int x,int y,int chessflag2,int No_step);
    ~Chessman();
    int getX();
    int getY();
};

#endif // CHESSMAN_H
