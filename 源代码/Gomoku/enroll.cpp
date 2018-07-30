#include "enroll.h"
#include "ui_enroll.h"

enroll::enroll(QWidget *parent) :  //初始化界面
    QDialog(parent),
    ui(new Ui::enroll)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
    setWindowTitle(tr("五子棋"));
    setFixedSize(400, 266);
    connect(es,SIGNAL(quit_signal()),this,SLOT(quit_slot()));

    QRegExp regx("[a-zA-Z0-9]+$");      //用于标准化用户名、密码输入
    QValidator *validator = new QRegExpValidator(regx, ui->AccountName );
    ui->AccountName->setValidator( validator );
}

enroll::~enroll()
{
    delete ui;
}

void enroll::paintEvent(QPaintEvent *){   //画界面背景
    QPainter painter(this);
    painter.drawPixmap(QRect(0,0,400,266), QPixmap("./timg.jpg"));
    painter.setRenderHint(QPainter::Antialiasing,true);
}



void enroll::on_Register_clicked()  //点击注册
{
    UserName = this->ui->AccountName->text().trimmed();//读取一系列用户填写的信息，判断合法性
    Password = this->ui->Password->text().trimmed();
    NickName = this->ui->NickName->text().trimmed();
    if(gender=="" || UserName=="" || Password=="" || NickName==""){
        er->exec();
    }else if(u->isRegisted(UserName,NickName)==1){
        er2->exec();
    }else if(u->isRegisted(UserName,NickName)==-1){
        er3->exec();
    }else if(u->includecomma(UserName,Password,NickName)!=0){
        er4->exec();
    }
    else{     //注册成功，初始化用户类。
        id_for_user_image="0";
        total_score_earned="0";
        total_game_played="0";
        total_wins="0";
        u->regester(UserName,Password,NickName,gender,id_for_user_image,total_score_earned,total_game_played,total_wins);
        gender=="";                                      //窗口信息重置
        UserName=="";
        Password=="";
        NickName=="";
        es->exec();
        this->ui->AccountName->text().trimmed()="";//还原窗口
        this->ui->Password->text().trimmed()="";
        this->ui->NickName->text().trimmed()="";
        this->ui->AccountName->setText("");
        this->ui->Password->setText("");
        this->ui->NickName->setText("");
    }
}

void enroll::on_Boy_clicked()
{
    gender="boy";
}

void enroll::on_Girl_clicked()
{
    gender="girl";
}

void enroll::quit_slot(){
    this->close();
}
