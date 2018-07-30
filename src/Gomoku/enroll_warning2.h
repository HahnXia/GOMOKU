#ifndef ENROLL_WARNING2_H
#define ENROLL_WARNING2_H

#include <QDialog>
//注册警告窗口2
namespace Ui {
class enroll_warning2;
}

class enroll_warning2 : public QDialog
{
    Q_OBJECT

public:
    explicit enroll_warning2(QWidget *parent = 0);
    ~enroll_warning2();

private slots:
    void on_Back_clicked();

private:
    Ui::enroll_warning2 *ui;
};

#endif // ENROLL_WARNING2_H
