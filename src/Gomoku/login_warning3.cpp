#include "login_warning3.h"
#include "ui_login_warning3.h"
//登录警告窗口3
login_warning3::login_warning3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_warning3)
{
    ui->setupUi(this);//显示警告
    setWindowTitle(tr("警告"));
}

login_warning3::~login_warning3()
{
    delete ui;
}

void login_warning3::on_Back_clicked()
{
    this->close();
}
