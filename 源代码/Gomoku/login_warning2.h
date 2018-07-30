#ifndef LOGIN_WARNING2_H
#define LOGIN_WARNING2_H

#include <QDialog>
//登录警告窗口2
namespace Ui {
class login_warning2;
}

class login_warning2 : public QDialog
{
    Q_OBJECT

public:
    explicit login_warning2(QWidget *parent = 0);
    ~login_warning2();

private slots:
    void on_Back_clicked();

private:
    Ui::login_warning2 *ui;
};

#endif // LOGIN_WARNING2_H
