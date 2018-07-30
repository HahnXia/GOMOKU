#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chessman.h"


class Chessboard
{
private:
//   int length,width;
    int px,py;
    int stepnum;//记录当前总步数 可以用来判断是否棋盘下满了 和棋
    int chessflag; //1-white -1-black 
    int winflag;//默认0 1白字胜，-1黑子胜
    int isEmpty[100][100]; //判断棋盘某个位置是否能落子 0-none 1-white -1-black 
    vector <Chessman> chessman; //用于记录落子顺序 原本准备用vector存的，后来还是用了上面的数组
    GLOBALA *g=new GLOBALA;

public:
    Chessboard();
    ~Chessboard();
    void putChess(int px,int py);//落子  
    void takeback();//悔棋
    bool canbeput(int px,int py); //判断能否落子
    int getPX();
    int getPY();
    int getChessflag(); //获取当前棋子类型
    int getChessType(int x,int y);//返回isEmpty中数值
    int getWinflag();
    void Win();//判别胜负，更改winflag -1黑子胜，0和棋，1白子胜；
    void setPxPy(int px,int py);
    void setChessflag(int chessflag);
    void changeChessflag();
//    void setWinflag(int flag); // 通过认输操作直接更改winflag
    void setWinflagBack(); //winflag归零
    void restartFunction();
    int getstepnum();
};



#endif // CHESSBOARD_H
