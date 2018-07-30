#ifndef ENROLL_WARNING_H
#define ENROLL_WARNING_H

#include <QDialog>
//注册警告窗口1
namespace Ui {
class enroll_warning;
}

class enroll_warning : public QDialog
{
    Q_OBJECT

public:
    explicit enroll_warning(QWidget *parent = 0);
    ~enroll_warning();

private slots:
    void on_Bcak_clicked();

private:
    Ui::enroll_warning *ui;
};

#endif // ENROLL_WARNING_H
