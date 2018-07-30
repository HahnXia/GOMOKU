#include "login_warning4.h"
#include "ui_login_warning4.h"

login_warning4::login_warning4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_warning4)
{
    ui->setupUi(this);
    setWindowTitle(tr("警告"));
}

login_warning4::~login_warning4()
{
    delete ui;
}

void login_warning4::on_Back_clicked()
{
    this->close();
}
