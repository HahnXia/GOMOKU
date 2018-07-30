#include "global.h"
//全局数据类
QString GLOBALA::UserName1="";
QString GLOBALA::UserName2="";
//QString GLOBALA::NickName1="";
//QString GLOBALA::NickName2="";
//int GLOBALA::totalGames1=0;
//int GLOBALA::totalGames2=0;
//double GLOBALA::winRate1=0.0;
//double GLOBALA::winRate2=0.0;
int GLOBALA::modeflag=0;

void GLOBALA::setUserName1(QString data){
    UserName1=data;
}

QString GLOBALA::getUserName1(){
    return UserName1;
}

void GLOBALA::setUserName2(QString data){
    UserName2=data;
}

QString GLOBALA::getUserName2(){
    return UserName2;
}


//void GLOBALA::setNickName1(QString data){
//    NickName1=data;
//}

//QString GLOBALA::getNickName1(){
//    return NickName1;
//}

//void GLOBALA::setNickName2(QString data){
//    NickName2=data;
//}

//QString GLOBALA::getNickName2(){
//    return NickName2;
//}

//void GLOBALA::settotalGames1(int data){
//    totalGames1=data;
//}

//int GLOBALA::gettotalGames1(){
//    return totalGames1;
//}

//void GLOBALA::settotalGames2(int data){
//    totalGames2=data;
//}

//int GLOBALA::gettotalGames2(){
//    return totalGames2;
//}

//void GLOBALA::setwinRate1(double data){
//    winRate1=data;
//}

//double GLOBALA::getwinRate1(){
//    return winRate1;
//}

//void GLOBALA::setwinRate2(double data){
//    winRate2=data;
//}

//double GLOBALA::getwinRate2(){
//    return winRate2;
//}

void GLOBALA::setModeflag(int data){
    modeflag=data;
}

int GLOBALA::getModeflag(){
    return modeflag;
}
