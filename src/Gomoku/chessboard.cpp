#include "chessboard.h"

Chessboard::Chessboard(){
//    length=640;
//   width=640;
    memset(isEmpty,0,100*100*sizeof(int)); //窗口大小
    chessflag=-1;
    stepnum=0;
}

Chessboard::~Chessboard(){
    
}

int Chessboard::getPX(){
    return px;
}

int Chessboard::getPY(){
    return py;
}

int Chessboard::getChessflag(){
    return chessflag;
}

int Chessboard::getChessType(int x,int y){
    return isEmpty[x][y];
}

int Chessboard::getWinflag(){
    return winflag;
}

void Chessboard::Win(){   //检查是否胜利
    Chessman c = chessman.back();
    int _px=c.getX();
    int _py=c.getY();
    int i=1,num=0;//num:记录连成一行的棋子数量
    int temp_chessflag=-chessflag;  // 因为win函数是在落子之后检查胜负的，落子后的chessflag改变了所以要反一下
    while(isEmpty[_px-i][_py]==temp_chessflag){
        num++;
        i++;
    }
    i=1;
    while(isEmpty[_px+i][_py]==temp_chessflag){
        num++;
        i++;
    }
    if(num>=4){
        winflag= temp_chessflag;
    }
    i=1;
    num=0;
    while(isEmpty[_px][_py-i]==temp_chessflag){
        num++;
        i++;
    }
    i=1;
    while(isEmpty[_px][_py+i]==temp_chessflag){
        num++;
        i++;
    }
    if(num>=4){
         winflag=  temp_chessflag;
    }
    i=1;
    num=0;
    while(isEmpty[_px-i][_py-i]==temp_chessflag){
        num++;
        i++;
    }
    i=1;
    while(isEmpty[_px+i][_py+i]==temp_chessflag){
        num++;
        i++;
    }
    if(num>=4){
         winflag=  temp_chessflag;
    }
    i=1;
    num=0;
    while(isEmpty[_px-i][_py+i]==temp_chessflag){
        num++;
        i++;
    }
    i=1;
    while(isEmpty[_px+i][_py-i]==temp_chessflag){
        num++;
        i++;
    }
    if(num>=4){
         winflag=  temp_chessflag;
    }
}

void Chessboard::setPxPy(int px, int py){
    this->px=px;
    this->py=py;
}

void Chessboard::setChessflag(int chessflag){
    this->chessflag=chessflag;
}

//void Chessboard::setWinflag(int flag){
//   winflag=flag;
//}

void Chessboard::setWinflagBack(){
    winflag=0;
}

void Chessboard::changeChessflag(){
    chessflag=-chessflag;
}

bool Chessboard::canbeput(int px,int py){  //是否已经有棋子存在了
    if(isEmpty[px][py]!=0){
        return false;
    }else{
        return true;
    }
}

void Chessboard::putChess(int px, int py){  //落子
    stepnum++;
    isEmpty[px][py]=chessflag;
    Chessman c(px,py,chessflag,stepnum); //创建一个个棋子类
    chessman.push_back(c);               //加入链表
    chessflag=-chessflag;
}

void Chessboard::takeback(){      //悔棋
    Chessman c = chessman.back();  //当前的棋设置为之前一步的棋。
    chessman.pop_back();           //链表后退一步
    int x=c.getX(),y=c.getY();
    isEmpty[x][y]=0;
    stepnum--;
    chessflag=-chessflag;
}

void Chessboard::restartFunction(){//重新开始
//    length=640;
//    width=640;
    memset(isEmpty,0,100*100*sizeof(int));//把棋盘清空，参数复位。
    chessflag=-1;
    stepnum=0;
    if(g->getModeflag()==1){//如果是人机的话，让电脑先下一步。
        putChess(7,7);
    }
}

int Chessboard::getstepnum(){
    return stepnum;
}
