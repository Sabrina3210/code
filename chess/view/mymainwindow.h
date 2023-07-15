#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QWidget>
#include "view/mywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MyMainWindow;
}
QT_END_NAMESPACE

class MyMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
        MainWidget  chess_board;
private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
