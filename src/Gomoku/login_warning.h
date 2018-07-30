#ifndef LOGIN_WARNING_H
#define LOGIN_WARNING_H

#include <QDialog>
//登录警告窗口1
namespace Ui {
class login_warning;
}

class login_warning : public QDialog
{
    Q_OBJECT

public:
    explicit login_warning(QWidget *parent = 0);
    ~login_warning();

private slots:
    void on_Back_clicked();

private:
    Ui::login_warning *ui;
};

#endif // LOGIN_WARNING_H
