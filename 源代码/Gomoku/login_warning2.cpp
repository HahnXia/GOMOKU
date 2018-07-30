#include "login_warning2.h"
#include "ui_login_warning2.h"
//登录警告窗口2
login_warning2::login_warning2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_warning2)
{
    ui->setupUi(this);//显示警告
    setWindowTitle(tr("警告"));
}

login_warning2::~login_warning2()
{
    delete ui;
}

void login_warning2::on_Back_clicked()
{
    this->close();
}
