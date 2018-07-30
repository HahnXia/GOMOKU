#ifndef ENROLL_WARNING3_H
#define ENROLL_WARNING3_H

#include <QDialog>
//注册警告窗口3
namespace Ui {
class enroll_warning3;
}

class enroll_warning3 : public QDialog
{
    Q_OBJECT

public:
    explicit enroll_warning3(QWidget *parent = 0);
    ~enroll_warning3();

private slots:
    void on_Back_clicked();

private:
    Ui::enroll_warning3 *ui;
};

#endif // ENROLL_WARNING3_H
