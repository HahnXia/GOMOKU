#ifndef TIME_H
#define TIME_H

#include "chessman.h"


class mytimer
{
private:
    int min;
    int sec;
    QString minStr;
    QString secStr;
    int cnt;
    void setStrLength(QString *str, int length);

public:
    mytimer();
    void reset(int min,int sec); //重置
    QString getjointTime();      //将分秒拼接
    int getSEC();                //得到秒

public slots:
    void internalCalculateSlot();//和外界触发器信号相连接的slot 每1ms加一来计数
};

#endif // TIME_H
