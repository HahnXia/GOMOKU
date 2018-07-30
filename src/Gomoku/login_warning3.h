#ifndef LOGIN_WARNING3_H
#define LOGIN_WARNING3_H

#include <QDialog>
//登录警告窗口3
namespace Ui {
class login_warning3;
}

class login_warning3 : public QDialog
{
    Q_OBJECT

public:
    explicit login_warning3(QWidget *parent = 0);
    ~login_warning3();

private slots:
    void on_Back_clicked();

private:
    Ui::login_warning3 *ui;
};

#endif // LOGIN_WARNING3_H
