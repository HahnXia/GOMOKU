#include "login_warning.h"
#include "ui_login_warning.h"
//登录警告窗口1
login_warning::login_warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_warning)
{
    ui->setupUi(this);//显示警告
    setWindowTitle(tr("警告"));
}

login_warning::~login_warning()
{
    delete ui;
}

void login_warning::on_Back_clicked()
{
    this->close();
}
