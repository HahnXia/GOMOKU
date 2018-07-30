#ifndef ENROLL_WARNING4_H
#define ENROLL_WARNING4_H

#include <QDialog>
//注册警告窗口4
namespace Ui {
class enroll_warning4;
}

class enroll_warning4 : public QDialog
{
    Q_OBJECT

public:
    explicit enroll_warning4(QWidget *parent = 0);
    ~enroll_warning4();

private slots:
    void on_Back_clicked();

private:
    Ui::enroll_warning4 *ui;
};

#endif // ENROLL_WARNING4_H
