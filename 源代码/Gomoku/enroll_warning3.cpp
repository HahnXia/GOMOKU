#include "enroll_warning3.h"
#include "ui_enroll_warning3.h"
//注册警告窗口2
enroll_warning3::enroll_warning3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll_warning3)
{
    ui->setupUi(this);//显示警告
    setWindowTitle(tr("警告"));
}

enroll_warning3::~enroll_warning3()
{
    delete ui;
}

void enroll_warning3::on_Back_clicked()
{
    this->close();
}
