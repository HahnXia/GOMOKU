#ifndef ENROLL_SUCCESS_H
#define ENROLL_SUCCESS_H

#include <QDialog>
//注册成功窗口
namespace Ui {
class enroll_success;
}

class enroll_success : public QDialog
{
    Q_OBJECT

public:
    explicit enroll_success(QWidget *parent = 0);
    ~enroll_success();

private slots:
    void on_pushButton_clicked();

private:
    Ui::enroll_success *ui;

signals:
    quit_signal();
};

#endif // ENROLL_SUCCESS_H
