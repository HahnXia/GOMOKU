#ifndef USER_H
#define USER_H
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QStringList>
using namespace std;

class User{
public:
    User();//构造函数
    ~User();

    int regrettime(); //悔棋次数
    void add(); //悔棋

/*  用户变量函数接口  */
    QString Check_nickname(QString);
    QString Check_gender(QString);
    QString Check_id_for_user_image(QString);
    int Check_total_score_earned(QString);
    int Check_total_game_played(QString);
    int Check_total_wins(QString);
/*  天梯 */
    QStringList sky_ladder();
    bool Login(QString,QString);//检查登录
    void regester(QString Username, QString Password, QString nickname, QString gender, QString qqid, QString score_earned, QString game_played, QString wins);//注册

/* 修改内部变量函数 */
    void addWinTimes(QString,int);
    void addTotalGames(QString,int);
    void addScore(QString,int);
    void Readallfile();
    void check_change_file(QString);

/* 检查是否重名 */
   /* 返回值：0为不重复，1为用户名重复，2为昵称重复。*/
    int isRegisted(QString Username, QString nickname);
/* 检查是否有逗号 */
    int includecomma(QString username, QString password, QString nickname);

private:
    int rtime;//悔棋次数
    int checkflag; //登录正确标志
    QString Filename;//文件地址
    QString WriteLine;//注册
    QString Line;
    QString Usernametemp;
    QString Passwordtemp;


/*  用户变量  */
    QString Username;//登录名
    QString Password;//密码
    QString nickname;
    QString gender;
    QString id_for_user_image;
    int total_score_earned;
    int total_game_played;
    int total_wins;

 /* 修改内部值使用到的变量 */
    QString C_Username;//登录名
    QString C_Password;//密码
    QString C_nickname;
    QString C_gender;
    QString C_id_for_user_image;
    int C_total_score_earned;
    int C_total_game_played;
    int C_total_wins;
    int Score;
    int Games;
    int Wins;
    QString data_added;
    QString zero;
    QString no;

/* number:0:改socre；1:改games；2：改wins */
    void changedata(int number, int data);
    QString strAll;
    QStringList strList;
    QStringList RegistList;

    QStringList sortfile();
    QStringList sortedfile;
    QStringList unsortfile;
    QStringList sky_ladder_list;

};

#endif // USER_H
