#include "enroll_warning2.h"
#include "ui_enroll_warning2.h"
//注册警告窗口2
enroll_warning2::enroll_warning2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll_warning2)
{
    ui->setupUi(this);//显示警告
    setWindowTitle(tr("警告"));
}

enroll_warning2::~enroll_warning2()
{
    delete ui;
}

void enroll_warning2::on_Back_clicked()
{
    this->close();
}
