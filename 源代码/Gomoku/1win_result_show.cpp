#include "1win_result_show.h"
#include "ui_win_result_show.h"

win_result_show::win_result_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win_result_show)
{
    ui->setupUi(this);
}

win_result_show::~win_result_show()
{
    delete ui;
}
