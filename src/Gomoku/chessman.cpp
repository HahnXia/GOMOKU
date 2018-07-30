#include "chessman.h"
//棋子类
Chessman::Chessman(int x,int y,int chessflag2,int No_step){
    this->x=x;//棋盘坐标
    this->y=y;
    this->No_step=No_step;//第几个子
    this->chessflag2=chessflag2;//子颜色
}

Chessman::~Chessman(){
    
}

int Chessman::getX(){
    return x;
}

int Chessman::getY(){
    return y;
}
