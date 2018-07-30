#ifndef WIN1_SHOW_H
#define WIN1_SHOW_H

#include <QDialog>
//胜利窗口1
namespace Ui {
class win1_show;
}

class win1_show : public QDialog
{
    Q_OBJECT

public:
    explicit win1_show(QWidget *parent = 0);
    ~win1_show();

private slots:
    void on_Quitgame_clicked();//退出

    void on_Restart_clicked();//重新开始

private:
    Ui::win1_show *ui;

signals:
    quit_Signal();
    restart_Signal();
};

#endif // WIN1_SHOW_H
