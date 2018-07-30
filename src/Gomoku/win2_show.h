#ifndef WIN2_SHOW_H
#define WIN2_SHOW_H

#include <QDialog>
//胜利窗口2
namespace Ui {
class win2_show;
}

class win2_show : public QDialog
{
    Q_OBJECT

public:
    explicit win2_show(QWidget *parent = 0);
    ~win2_show();

private slots:
    void on_Quitgame_clicked();//退出游戏

    void on_Restart_clicked();//重新开始

private:
    Ui::win2_show *ui;

signals:
    quit_Signal();
    restart_Signal();
};

#endif // WIN2_SHOW_H
