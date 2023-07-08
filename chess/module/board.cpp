#include "board.h"
#include <QPainter>
board::board(QWidget *parent)
    : QWidget{parent}
{

}
void board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //画横线10
    int d=40;
    for(int i=1;i<11;i++)
    {
        painter.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }
    for(int i=1;i<10;i++)
    {
        if(i==1||i==9)
        {
            painter.drawLine(QPoint(i*d,d),QPoint(i*d,10*d));
        }
        else
        {
            painter.drawLine(QPoint(i*d,d),QPoint(i*d,5*d));
            painter.drawLine(QPoint(i*d,6*d),QPoint(i*d,10*d));
        }
    }
    int dif=3;
    painter.drawLine(QPoint(d*4,d),QPoint(6*d,3*d));
    painter.drawLine(QPoint(d*6,d),QPoint(4*d,3*d));
    painter.drawLine(QPoint(d*4,8*d),QPoint(6*d,10*d));
    painter.drawLine(QPoint(d*6,8*d),QPoint(4*d,10*d));
    painter.drawLine(QPoint(d-dif,d-dif),QPoint(9*d+dif,d-dif));
    painter.drawLine(QPoint(d-dif,10*d+dif),QPoint(9*d+dif,10*d+dif));
    painter.drawLine(QPoint(d-dif,d-dif),QPoint(d-dif,10*d+dif));
    painter.drawLine(QPoint(9*d+dif,d-dif),QPoint(9*d+dif,10*d+dif));

    double length=7*d/46;
    double dis=2*d/23;
    //兵 卒 炮 棋盘
    painter.drawLine(QPoint(d+dis,4*d-dis-length),QPoint(d+dis,4*d-dis));
    painter.drawLine(QPoint(d+dis,4*d-dis),QPoint(d+dis+length,4*d-dis));
    painter.drawLine(QPoint(d+dis,4*d+dis),QPoint(d+dis,4*d+dis+length));
    painter.drawLine(QPoint(d+dis,4*d+dis),QPoint(d+dis+length,4*d+dis));

    painter.drawLine(QPoint(d+dis,7*d-dis-length),QPoint(d+dis,7*d-dis));
    painter.drawLine(QPoint(d+dis,7*d-dis),QPoint(d+dis+length,7*d-dis));
    painter.drawLine(QPoint(d+dis,7*d+dis),QPoint(d+dis,7*d+dis+length));
    painter.drawLine(QPoint(d+dis,7*d+dis),QPoint(d+dis+length,7*d+dis));

    painter.drawLine(QPoint(9*d-dis,4*d-dis-length),QPoint(9*d-dis,4*d-dis));
    painter.drawLine(QPoint(9*d-dis,4*d-dis),QPoint(9*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(9*d-dis,4*d+dis),QPoint(9*d-dis,4*d+dis+length));
    painter.drawLine(QPoint(9*d-dis,4*d+dis),QPoint(9*d-dis-length,4*d+dis));

    painter.drawLine(QPoint(9*d-dis,7*d-dis-length),QPoint(9*d-dis,7*d-dis));
    painter.drawLine(QPoint(9*d-dis,7*d-dis),QPoint(9*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(9*d-dis,7*d+dis),QPoint(9*d-dis,7*d+dis+length));
    painter.drawLine(QPoint(9*d-dis,7*d+dis),QPoint(9*d-dis-length,7*d+dis));


    painter.drawLine(QPoint(2*d-dif,3*d-dis),QPoint(2*d-dif,3*d-dis-length));
    painter.drawLine(QPoint(2*d-dif,3*d-dis),QPoint(2*d-dis-length,3*d-dis));
    painter.drawLine(QPoint(2*d-dif,3*d+dis),QPoint(2*d-dif,3*d+dis+length));
    painter.drawLine(QPoint(2*d-dif,3*d+dis),QPoint(2*d-dis-length,3*d+dis));
    painter.drawLine(QPoint(2*d+dif,3*d-dis),QPoint(2*d+dif,3*d-dis-length));
    painter.drawLine(QPoint(2*d+dif,3*d-dis),QPoint(2*d+dis+length,3*d-dis));
    painter.drawLine(QPoint(2*d+dif,3*d+dis),QPoint(2*d+dif,3*d+dis+length));
    painter.drawLine(QPoint(2*d+dif,3*d+dis),QPoint(2*d+dis+length,3*d+dis));

    painter.drawLine(QPoint(2*d-dif,8*d-dis),QPoint(2*d-dif,8*d-dis-length));
    painter.drawLine(QPoint(2*d-dif,8*d-dis),QPoint(2*d-dis-length,8*d-dis));
    painter.drawLine(QPoint(2*d-dif,8*d+dis),QPoint(2*d-dif,8*d+dis+length));
    painter.drawLine(QPoint(2*d-dif,8*d+dis),QPoint(2*d-dis-length,8*d+dis));
    painter.drawLine(QPoint(2*d+dif,8*d-dis),QPoint(2*d+dif,8*d-dis-length));
    painter.drawLine(QPoint(2*d+dif,8*d-dis),QPoint(2*d+dis+length,8*d-dis));
    painter.drawLine(QPoint(2*d+dif,8*d+dis),QPoint(2*d+dif,8*d+dis+length));
    painter.drawLine(QPoint(2*d+dif,8*d+dis),QPoint(2*d+dis+length,8*d+dis));

    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dis+length,4*d+dis));

    painter.drawLine(QPoint(3*d-dif,7*d-dis),QPoint(3*d-dif,7*d-dis-length));
    painter.drawLine(QPoint(3*d-dif,7*d-dis),QPoint(3*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(3*d-dif,7*d+dis),QPoint(3*d-dif,7*d+dis+length));
    painter.drawLine(QPoint(3*d-dif,7*d+dis),QPoint(3*d-dis-length,7*d+dis));
    painter.drawLine(QPoint(3*d+dif,7*d-dis),QPoint(3*d+dif,7*d-dis-length));
    painter.drawLine(QPoint(3*d+dif,7*d-dis),QPoint(3*d+dis+length,7*d-dis));
    painter.drawLine(QPoint(3*d+dif,7*d+dis),QPoint(3*d+dif,7*d+dis+length));
    painter.drawLine(QPoint(3*d+dif,7*d+dis),QPoint(3*d+dis+length,7*d+dis));

    painter.drawLine(QPoint(5*d-dif,4*d-dis),QPoint(5*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(5*d-dif,4*d-dis),QPoint(5*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(5*d-dif,4*d+dis),QPoint(5*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(5*d-dif,4*d+dis),QPoint(5*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(5*d+dif,4*d-dis),QPoint(5*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(5*d+dif,4*d-dis),QPoint(5*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(5*d+dif,4*d+dis),QPoint(5*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(5*d+dif,4*d+dis),QPoint(5*d+dis+length,4*d+dis));

    painter.drawLine(QPoint(5*d-dif,7*d-dis),QPoint(5*d-dif,7*d-dis-length));
    painter.drawLine(QPoint(5*d-dif,7*d-dis),QPoint(5*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(5*d-dif,7*d+dis),QPoint(5*d-dif,7*d+dis+length));
    painter.drawLine(QPoint(5*d-dif,7*d+dis),QPoint(5*d-dis-length,7*d+dis));
    painter.drawLine(QPoint(5*d+dif,7*d-dis),QPoint(5*d+dif,7*d-dis-length));
    painter.drawLine(QPoint(5*d+dif,7*d-dis),QPoint(5*d+dis+length,7*d-dis));
    painter.drawLine(QPoint(5*d+dif,7*d+dis),QPoint(5*d+dif,7*d+dis+length));
    painter.drawLine(QPoint(5*d+dif,7*d+dis),QPoint(5*d+dis+length,7*d+dis));

    painter.drawLine(QPoint(7*d-dif,4*d-dis),QPoint(7*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(7*d-dif,4*d-dis),QPoint(7*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(7*d-dif,4*d+dis),QPoint(7*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(7*d-dif,4*d+dis),QPoint(7*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(7*d+dif,4*d-dis),QPoint(7*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(7*d+dif,4*d-dis),QPoint(7*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(7*d+dif,4*d+dis),QPoint(7*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(7*d+dif,4*d+dis),QPoint(7*d+dis+length,4*d+dis));

    painter.drawLine(QPoint(7*d-dif,7*d-dis),QPoint(7*d-dif,7*d-dis-length));
    painter.drawLine(QPoint(7*d-dif,7*d-dis),QPoint(7*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(7*d-dif,7*d+dis),QPoint(7*d-dif,7*d+dis+length));
    painter.drawLine(QPoint(7*d-dif,7*d+dis),QPoint(7*d-dis-length,7*d+dis));
    painter.drawLine(QPoint(7*d+dif,7*d-dis),QPoint(7*d+dif,7*d-dis-length));
    painter.drawLine(QPoint(7*d+dif,7*d-dis),QPoint(7*d+dis+length,7*d-dis));
    painter.drawLine(QPoint(7*d+dif,7*d+dis),QPoint(7*d+dif,7*d+dis+length));
    painter.drawLine(QPoint(7*d+dif,7*d+dis),QPoint(7*d+dis+length,7*d+dis));

    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dis+length,4*d+dis));

    painter.drawLine(QPoint(8*d-dif,3*d-dis),QPoint(8*d-dif,3*d-dis-length));
    painter.drawLine(QPoint(8*d-dif,3*d-dis),QPoint(8*d-dis-length,3*d-dis));
    painter.drawLine(QPoint(8*d-dif,3*d+dis),QPoint(8*d-dif,3*d+dis+length));
    painter.drawLine(QPoint(8*d-dif,3*d+dis),QPoint(8*d-dis-length,3*d+dis));
    painter.drawLine(QPoint(8*d+dif,3*d-dis),QPoint(8*d+dif,3*d-dis-length));
    painter.drawLine(QPoint(8*d+dif,3*d-dis),QPoint(8*d+dis+length,3*d-dis));
    painter.drawLine(QPoint(8*d+dif,3*d+dis),QPoint(8*d+dif,3*d+dis+length));
    painter.drawLine(QPoint(8*d+dif,3*d+dis),QPoint(8*d+dis+length,3*d+dis));

    painter.drawLine(QPoint(8*d-dif,8*d-dis),QPoint(8*d-dif,8*d-dis-length));
    painter.drawLine(QPoint(8*d-dif,8*d-dis),QPoint(8*d-dis-length,8*d-dis));
    painter.drawLine(QPoint(8*d-dif,8*d+dis),QPoint(8*d-dif,8*d+dis+length));
    painter.drawLine(QPoint(8*d-dif,8*d+dis),QPoint(8*d-dis-length,8*d+dis));
    painter.drawLine(QPoint(8*d+dif,8*d-dis),QPoint(8*d+dif,8*d-dis-length));
    painter.drawLine(QPoint(8*d+dif,8*d-dis),QPoint(8*d+dis+length,8*d-dis));
    painter.drawLine(QPoint(8*d+dif,8*d+dis),QPoint(8*d+dif,8*d+dis+length));
    painter.drawLine(QPoint(8*d+dif,8*d+dis),QPoint(8*d+dis+length,8*d+dis));


    QString text = "楚河";
    QString text1 = "漢界";
    QRect rect(d, 5*d, 4*d, d);
    QRect rect1(5*d, 5*d, 4*d, d);
    painter.drawText(rect, Qt::AlignCenter, text);
    painter.drawText(rect1, Qt::AlignCenter, text1);
}

