#ifndef GLOBALA_H
#define GLOBALA_H

#include <QMainWindow>
//全局数据类
class GLOBALA                         // 注意这个名字啊！是GLOBAL"A"
{
public:
//  GLOBALA();
    static QString UserName1;
    static QString UserName2;
/*    static QString NickName1;
    static QString NickName2;
    static int totalGames1;
    static int totalGames2;
    static double winRate1;
    static double winRate2;*/
    static int modeflag;    //表示模式的flag  0代表PVP，1代表AI

    static void setUserName1(QString);
    static QString getUserName1();

    static void setUserName2(QString);
    static QString getUserName2();

//    static void setNickName1(QString);
//    static QString getNickName1();

//    static void setNickName2(QString);
//    static QString getNickName2();

//    static void settotalGames1(int);
//    static int gettotalGames1();

//    static void settotalGames2(int);
//    static int gettotalGames2();

//    static void setwinRate1(double);
//    static double getwinRate1();

//    static void setwinRate2(double);
//    static double getwinRate2();

    static void setModeflag(int);
    static int getModeflag();
};

#endif // GLOBALA_H
