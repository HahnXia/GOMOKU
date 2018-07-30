#include "enroll_success.h"
#include "ui_enroll_success.h"

enroll_success::enroll_success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll_success)
{
    ui->setupUi(this);
    setWindowTitle(tr("提示"));
}

enroll_success::~enroll_success()
{
    delete ui;
}

void enroll_success::on_pushButton_clicked()
{
    emit quit_signal();
    this->close();
}
