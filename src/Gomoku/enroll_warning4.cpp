#include "enroll_warning4.h"
#include "ui_enroll_warning4.h"
//注册警告窗口4
enroll_warning4::enroll_warning4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll_warning4)
{
    ui->setupUi(this);//显示警告
    setWindowTitle(tr("警告"));
}

enroll_warning4::~enroll_warning4()
{
    delete ui;
}

void enroll_warning4::on_Back_clicked()
{
    this->close();
}
