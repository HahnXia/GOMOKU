#include "login.h"
#include "ui_login.h"


login::login(QWidget *parent) :  //初始化窗口
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->Player1_Password->setEchoMode(QLineEdit::Password); //使密码显示圆圈
    ui->Player2_Password->setEchoMode(QLineEdit::Password);
    setWindowTitle(tr("五子棋"));
    setFixedSize(400, 266);
}

login::~login()
{
    delete ui;
}

void login::paintEvent(QPaintEvent *){   //画背景
    QPainter painter(this);
    painter.drawPixmap(QRect(0,0,400,266), QPixmap("./timg.jpg"));
    painter.setRenderHint(QPainter::Antialiasing,true);
}

void login::on_LoginConfirm_clicked()//按下登录按钮，读取输入的用户名密码，与文件中登记的相比较，确定是否登录成功
{
    UserName1=this->ui->Player1_UserName->text().trimmed();//从界面读取
    UserName2=this->ui->Player2_UserName->text().trimmed();
    Password1=this->ui->Player1_Password->text().trimmed();
    Password2=this->ui->Player2_Password->text().trimmed();
    if(UserName1==""||UserName2==""||Password1==""||Password2==""){//判断是否信息填写完整
        lw->exec();
    }else if(!u->Login(UserName1,Password1)){ //判断用户名密码是否存在/匹配
        lw2->exec();
    }else if(!u->Login(UserName2,Password2)){
        lw3->exec();
    }else if(UserName1==UserName2){//判断两个用户名是否相同
        lw4->exec();
    }
    else{//成功
        g->setUserName1(UserName1);
        g->setUserName2(UserName2);
        g->setModeflag(0);
        mw->show();
        UserName1="";                                //窗口信息重置
        UserName2="";
        Password1="";
        Password2="";
        this->ui->Player1_UserName->setText("");
        this->ui->Player2_UserName->setText("");
        this->ui->Player1_Password->setText("");
        this->ui->Player2_Password->setText("");
        this->close();
    }
}
