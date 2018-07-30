#ifndef LOGIN_WARNING4_H
#define LOGIN_WARNING4_H

#include <QDialog>
//登录警告窗口4
namespace Ui {
class login_warning4;
}

class login_warning4 : public QDialog
{
    Q_OBJECT

public:
    explicit login_warning4(QWidget *parent = 0);
    ~login_warning4();

private slots:
    void on_Back_clicked();

private:
    Ui::login_warning4 *ui;
};

#endif // LOGIN_WARNING4_H
