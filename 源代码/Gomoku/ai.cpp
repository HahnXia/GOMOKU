#include "chessboard.h"
#include "ai.h"
////////////////////////////宋斯亮.6.23
/// 在已下的子附近穷举可以落子的点；
/// 每个点都用算法打分
/// 算法：例如下的是白棋，任何包含该格的5元组中（即包含该格子的横竖斜连续5个格子）
///      含有1,2,3,4个白棋分别得35,800,15000,800000；
///      含有1,2,3,4个黑子分别得15,400,1800,100000；
///      有黑子又有白子的得0；
///      没有子的得7分；
/// 把所有五元组的分数相加，得到某个位置的得分。
/// 最后取得分最高的位置落子。
/// /////////////////////////
void aiputChess(Chessboard *cb){
    int i=0,j=0,max=-1,temp=0,px,py,valid=0;
    int si,sj; //AI要落子的点
    //int score[15][15];
    for(i=0;i<=14;i++){
        for(j=0;j<=14;j++){
///////////////////在当前搜索的位置附近寻找是否有已经落的子/////////////////////
            valid=0;
            if(cb->getChessType(i,j)==0){
               for(si=i-2;si<=i+2;si++){
                    if(valid==1)
                        break;
                    if(si>=0&&si<=14){
                     for(sj=j-2;sj<=j+2;sj++){
                            if(valid==1)
                                break;
                            if(sj>=0&&sj<=14){
                                if(cb->getChessType(si,sj)!=0)
                                    valid=1;
                            }
                        }
                    }
                }
            }
///////////////////////如果找到了，计算分数,记录最大值//////////////////////
            if(valid==1){
                temp=calScore(cb,i,j);
                if(temp>max){
                    max=temp;
                    px=i;
                    py=j;
                }
            }
        }
    }
///////////////////在得分最高的位置落子/////////////////////
    cb->putChess(px,py);
}

int calScore(Chessboard *cb,int i, int j){
    int tupleScoreTable[11]={7,35,800,15000,800000,15,400,1800,100000,0,0}; //分数表
    int score=0,tupleType=0,chessType,num=0;  //tupleType用于判断当时五元组是属于黑子的还是白子的。
    int ti=0,tj=0,tii=0;
    //0blank,1b,2bb,3bbb,4bbbb,5w,6ww,7www,8wwww,9virtual,10polluted
    ////////////下面计算四个方向的五元组得分/////////
    //横向
    for(ti=i-4;ti<=i;ti++){
        tupleType=0;
        if(ti>=0&&ti+4<=14){
            num=0;
            for(tii=0;tii<=4;tii++){
                chessType=cb->getChessType(ti+tii,j);
                if(chessType==0){

                }
                else if(chessType!=-tupleType){
                    tupleType=chessType;
                    num++;
                }
                else{
                    num=10;
                    tupleType=0;
                    break;
                }
            }
            if(tupleType==-cb->getChessflag())
                num=num+4;
            score=score+tupleScoreTable[num];
        }
    }
    //纵向
    for(tj=j-4;tj<=j;tj++){
        tupleType=0;
        if(tj>=0&&tj+4<=14){
            num=0;
            for(tii=0;tii<=4;tii++){
                chessType=cb->getChessType(i,tj+tii);
                if(chessType==0){

                }
                else if(chessType!=-tupleType){
                    tupleType=chessType;
                    num++;
                }
                else{
                    num=10;
                    tupleType=0;//polluted
                    break;
                }
            }
            if(tupleType==-cb->getChessflag())
                num=num+4;
            score=score+tupleScoreTable[num];
        }
    }
    //斜向1
    for(ti=i-4,tj=j-4;ti<=i;ti++,tj++){
        tupleType=0;
        if(ti>=0&&ti+4<=14&&tj>=0&&tj+4<=14){
            num=0;
            for(tii=0;tii<=4;tii++){
                chessType=cb->getChessType(ti+tii,tj+tii);
                if(chessType==0){

                }
                else if(chessType!=-tupleType){
                    tupleType=chessType;
                    num++;
                }
                else{
                    num=10;
                    tupleType=0;//polluted
                    break;
                }
            }
            if(tupleType==-cb->getChessflag())
                num=num+4;
            score=score+tupleScoreTable[num];
        }
    }
    //斜向2
    for(ti=i+4,tj=j-4;ti>=i;ti--,tj++){
        tupleType=0;
        if(ti-4>=0&&ti<=14&&tj>=0&&tj+4<=14){
            num=0;
            for(tii=0;tii<=4;tii++){
                chessType=cb->getChessType(ti-tii,tj+tii);
                if(chessType==0){

                }
                else if(chessType!=-tupleType){
                    tupleType=chessType;
                    num++;
                }
                else{
                    num=10;
                    tupleType=0;//polluted
                    break;
                }
            }
            if(tupleType==-cb->getChessflag())
                num=num+4;
            score=score+tupleScoreTable[num];
        }
    }
    return score;
}
