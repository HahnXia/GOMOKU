#include "mytimer.h"

mytimer::mytimer(){
    min=0;
    sec=0;
    cnt=0;
    minStr="";
    secStr="";
}


void mytimer::setStrLength(QString *str, int length){
    if(str->length()<length){
        str->insert(0,"0");
    }
}

void mytimer::reset(int min,int sec){
    this->min=min;
    this->sec=sec;
}

//连接时间字符串
QString mytimer::getjointTime(){
    QString minStr=QString::number(min);
    QString secStr=QString::number(sec);
    setStrLength(&minStr,2);
    setStrLength(&secStr,2);
    minStr.insert(2,QString(" : "));
    minStr.insert(5,secStr);
    return minStr;
}

//与QTimer1ms一次的信号连接
void mytimer::internalCalculateSlot(){
    cnt++;
    if(sec==0){
        sec=60;
        min--;
    }else if(cnt%1000==0){
        sec--;
    }
}

int mytimer::getSEC(){
    return sec;
}
