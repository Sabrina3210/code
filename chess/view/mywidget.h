#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include"QMouseEvent"
QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void paintEvent(QPaintEvent *);
    void drawchess(QPainter& p,int id);
    void mouseReleaseEvent(QMouseEvent *ev);
    //click click_t;
private:
    Ui::MyWidget *ui;
    //my_vm vm;
};
#endif // MYWIDGET_H
