#include "user.h"
#include <QDebug>
#include <iostream>
User::User()
{
    rtime = 10;                //共N个悔棋机会
    Filename = "./UserData.txt";    //文件地址
    checkflag = 0;             //是否找到用户
/* 登录 */
    Usernametemp = "";
    Passwordtemp = "";
    Line = "";
    nickname = "";
    gender = "";
    id_for_user_image = "";
    total_game_played = 0;
    total_score_earned= 0;
    total_wins = 0;
    zero = "0";
    no = "无";
/* 注册 */
    WriteLine = "";

/* 增加修改*/
    Score = 0;
    Wins = 0;
    Games = 0;
    data_added = "";

}


User::~User(){

}


/* 悔棋 */
User::regrettime()
{
    return this->rtime;
}

void User::add()
{
    this->rtime -= 1;
}

/* 注册 修改了保存的字符串的格式，加上了各个数据的标识。*/
void User::regester(QString Username, QString Password, QString nickname, QString gender, QString qqid, QString score_earned, QString game_played, QString wins)
{
  /* 如果直接写zero，结果会出现错误，必须以QString开头。*/
    WriteLine =zero+','+Username+','+"1"+','+Password+','+"2"+','+nickname+','+"3"+','+gender+','+"4"+','+qqid+','+"5"+','+score_earned+','+"6"+','+game_played+','+"7"+','+wins;
    QFile RegFile(Filename);
    /*
     修改：在open后加入QIODevice::Append，就不是覆盖了。
    */
    if(!RegFile.open(QFile::WriteOnly|QFile::Text|QIODevice::Append))
    {
        qDebug() <<"Failed to open file for register.";
        //打不开文件
    }
    QTextStream write(&RegFile);
    write << WriteLine << endl;
    RegFile.close();
}

/* 登录 */
bool User::Login(QString Username, QString Password){
    this->Username = Username;
    this->Password = Password;

    QFile LoginFile(Filename);                                      //读file
        if(!LoginFile.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() <<"Failed to open file for login.";
            //打不开文件
        }
        QTextStream read(&LoginFile);
        while((read.atEnd()==0) && (checkflag == 0))
        {
            Line = read.readLine();//每次读一行
            Usernametemp = Line.section(',',1,1);//切割字符串，第一个是用户名
            Passwordtemp = Line.section(',',3,3);//第二个是密码

        /*增加了标识符导致section的位置变化*/

            if((Usernametemp == this->Username)&&(Passwordtemp ==this->Password))
            {
                checkflag = 1;//找到用户啦
                this->nickname = Line.section(',',5,5);
                this->gender = Line.section(',',7,7);
                this->id_for_user_image = Line.section(',',9,9);
                this->total_score_earned = Line.section(',',11,11).toInt();
                this->total_game_played = Line.section(',',13,13).toInt();
                this->total_wins = Line.section(',',15,15).toInt();
            }
        }
        LoginFile.close();
        if(checkflag == 0)
            {
                return false;
            }
                checkflag = 0;
                return true;

}

/* 检查是否重名  */
int User::isRegisted(QString username,QString nickname)
{
    QString two = "2";
    Readallfile(); //读文件
    RegistList=strAll.split('\n');//分割文本
    for(int i=0;i<RegistList.count();i++)
    {
        if(RegistList.at(i).section(',',1,1) == username)
                return 1;
          else if(RegistList.at(i).section(',',5,5) == nickname)
                return -1;
    }
    return 0;
}


/* 接口函数，返回内部变量 */

QString User::Check_nickname(QString user)
{
    check_change_file(user);
    return this->C_nickname;
}

QString User::Check_gender(QString user)
{
    check_change_file(user);
    return this->C_gender;
}

QString User::Check_id_for_user_image(QString user)
{
    check_change_file(user);
    return this->C_id_for_user_image;
}


/* 在QString后面加入.toInt函数，变成int。*/

int User::Check_total_score_earned(QString user)
{
    check_change_file(user);
    return this->C_total_score_earned;
}

int User::Check_total_game_played(QString user)
{
    check_change_file(user);
    return this->C_total_game_played;
}

int User::Check_total_wins(QString user)
{
    check_change_file(user);
    return this->C_total_wins;
}


/* 增加修改函数 */
void User::addScore(QString username, int score)
{
    int temp;
    check_change_file(username);
    temp = this->C_total_score_earned;
    temp += score;
    if(temp <= 0)
        this->C_total_score_earned = 0;
    else
        this->C_total_score_earned = temp;
    changedata(0,this->C_total_score_earned);
}

void User::addTotalGames(QString username, int games)
{
    check_change_file(username);

    this->C_total_game_played += games;
    changedata(1,this->C_total_game_played);
}

void User::addWinTimes(QString username, int wins)
{
    check_change_file(username);
    qDebug()<<"wins"<<this->C_total_wins;
    this->C_total_wins += wins;
    changedata(2,this->C_total_wins);
}




/********************************************************************* 以下为内部实现函数 *************************************************************/


/* 写入修改量函数，0为Score，1为games，2为wins。*/

void User::changedata(int number, int data)
{
    QString Strdata = QString::number(data);
    QString QC_total_score_earned= QString::number(C_total_score_earned);
    QString QC_total_game_played =QString::number(C_total_game_played);
    QString QC_total_wins =QString::number(C_total_wins);
/*确认修改对象*/

    switch(number)
    {
    case 0:
    {
    data_added = zero+','+this->C_Username+','+"1"+','+this->C_Password+','+"2"+','+this->C_nickname+','+"3"+','+this->C_gender+','+"4"+','+this->C_id_for_user_image+','+"5"+','+Strdata+','+"6"+','+QC_total_game_played+','+"7"+','+QC_total_wins;
    break;
    }
    case 1:
    {
    data_added = zero+','+this->C_Username+','+"1"+','+this->C_Password+','+"2"+','+this->C_nickname+','+"3"+','+this->C_gender+','+"4"+','+this->C_id_for_user_image+','+"5"+','+QC_total_score_earned+','+"6"+','+Strdata+','+"7"+','+QC_total_wins;
    break;
    }
    case 2:
    {
    data_added = zero+','+this->C_Username+','+"1"+','+this->C_Password+','+"2"+','+this->C_nickname+','+"3"+','+this->C_gender+','+"4"+','+this->C_id_for_user_image+','+"5"+','+QC_total_score_earned+','+"6"+','+QC_total_game_played+','+"7"+','+Strdata;
    break;
    }
    }

/*读文件*/

    Readallfile();

/*写文件*/

    QFile WriteChangeFile(Filename);
    if(!(WriteChangeFile.open(QIODevice::WriteOnly|QIODevice::Text)))
    {
        qDebug()<<"Fail"<<endl;
    }
            QTextStream stream(&WriteChangeFile);
            strList=strAll.split('\n');
            for(int i=0;i<strList.count();i++)

            {
                if(strList.at(i).contains(zero+','+this->C_Username+','+"1"+','+this->C_Password))
                {
                    stream<<data_added<<endl;
                    }
                else  /*if(i==strList.count()-1)
                    {
                        //最后一行不需要换行
                        stream<<strList.at(i);
                    }
                    else
                    {*/
                        stream<<strList.at(i)<<endl;
                    /* } */
                }
        WriteChangeFile.close();
}



void User::Readallfile(){
    QFile ReadChangeFile(Filename);

    if(ReadChangeFile.open((QIODevice::ReadOnly|QIODevice::Text)))
    {
        QTextStream stream(&ReadChangeFile);
        strAll=stream.readAll();
    }
    ReadChangeFile.close();
}



/*找到修改对象*/
void User::check_change_file(QString user)
{
    QFile ChangeFile(Filename);
        if(!ChangeFile.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() <<"Failed to open file for login.";
            //打不开文件
        }
        QTextStream read(&ChangeFile);
        while((read.atEnd()==0) && (checkflag == 0))
        {
            Line = read.readLine();//每次读一行
            Usernametemp = Line.section(',',1,1);//切割字符串，第一个是用户名

        /*增加了标识符导致section的位置变化*/

            if(Usernametemp == user)
            {
                checkflag = 1;
                this->C_Username = Line.section(',',1,1);
                this->C_Password = Line.section(',',3,3);
                this->C_nickname = Line.section(',',5,5);
                this->C_gender = Line.section(',',7,7);
                this->C_id_for_user_image = Line.section(',',9,9);
                this->C_total_score_earned = Line.section(',',11,11).toInt();

                this->C_total_game_played = Line.section(',',13,13).toInt();

                this->C_total_wins = Line.section(',',15,15).toInt();
            }
        }
        checkflag = 0;
        ChangeFile.close();
}


QStringList User::sky_ladder()
{
    int i = 0;
    int num = 0;
    QStringList temp;
    temp = sortfile();

    for(i=0;i<temp.count();i++)
    {
    num = temp.at(i).section("a",1,1).toInt();
    if(temp.at(i).section("a",1,1) == no)//用户不够，送出“无”
    {
        sky_ladder_list<<no;
        sky_ladder_list<<no;
    }
    else
    {
    sky_ladder_list<<unsortfile.at(num).section(',',5,5);//送出数据
    sky_ladder_list<<unsortfile.at(num).section(',',11,11);
    }
    }

    return this->sky_ladder_list;
}
// 读取文件
QStringList User::sortfile()
{
    QStringList sortedfile;
    QStringList reallysortedfile;
        Readallfile();

        unsortfile=strAll.split('\n');
        for(int i=0;i<unsortfile.count();i++)
        {
            if(unsortfile.at(i).contains(zero+','))
            {
                sortedfile<<unsortfile.at(i).section(',',11,11)+"a"+QString::number(i);
            }
        }

//按由大到小排位
        //最大积分 999999
        QString maxscore = "999999";
        QString temp = maxscore+"a"+"";
        QStringList registered;
        for (int i=0; i<sortedfile.count();i++)
        {
            QString max = zero + "a"+"";

            for (int j = 0; j<sortedfile.count();j++)
            {
                if ((sortedfile.at(j).section("a",0,0).toInt()>=max.section("a",0,0).toInt())
                    &&(sortedfile.at(j).section("a",0,0).toInt()<=temp.section("a",0,0).toInt()))
                {
                    bool registedflag = false;
                    for (int k=0;k<registered.count();k++)
                    {
                        if(sortedfile.at(j).section("a",1,1).toInt()==registered.at(k).section("a",1,1).toInt())
                        registedflag = true;
                    }
                    if(!registedflag)
                    max = sortedfile.at(j);
                 }
            }
            temp = max;
            registered << max;
            reallysortedfile<<max;
        }
        //保证积分数量大于5
               if(reallysortedfile.count()<5)
               {
                   QString nonexist = no+"a"+no;
                   while(reallysortedfile.count()<5)
                   {
                       reallysortedfile<<nonexist;
                   }
                }
             return reallysortedfile;
        }


/* 检查注册信息是否包含逗号。
 * 返回0:没逗号；
 * 返回1：username有逗号
 * 返回2：password有逗号
 * 返回3：nickname有逗号*/
int User::includecomma(QString username, QString password, QString nickname)
{
    if(username.contains(',')||username.contains(' '))
        return 1;
    if(password.contains(',')||username.contains(' '))
        return 2;
    if(nickname.contains(',')||username.contains(' '))
        return 3;
    return 0;
}
