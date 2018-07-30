#include "enroll_warning.h"
#include "ui_enroll_warning.h"
//注册警告窗口1
enroll_warning::enroll_warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll_warning)
{
    ui->setupUi(this);//显示警告
    setWindowTitle(tr("警告"));
}

enroll_warning::~enroll_warning()
{
    delete ui;
}

void enroll_warning::on_Bcak_clicked()
{
    this->close();//关闭窗口
}
