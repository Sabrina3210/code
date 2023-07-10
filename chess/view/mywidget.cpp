#include "mywidget.h"
#include "qpainter.h"
#include "ui_mywidget.h"
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    int x=ev->pos().x();
    int y=ev->pos().y();
     qDebug("Released at (%d, %d)", x/40, y/40);
}
void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //画10横线
    int d=40;
    for(int i=1;i<11;i++)
    {
        painter.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }
    //画9列
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
    //画边框
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

    painter.drawEllipse(d/2,3.5*d,d,d);

    painter.drawLine(QPoint(d+dis,7*d-dis-length),QPoint(d+dis,7*d-dis));
    painter.drawLine(QPoint(d+dis,7*d-dis),QPoint(d+dis+length,7*d-dis));
    painter.drawLine(QPoint(d+dis,7*d+dis),QPoint(d+dis,7*d+dis+length));
    painter.drawLine(QPoint(d+dis,7*d+dis),QPoint(d+dis+length,7*d+dis));

    painter.drawEllipse(d/2,6.5*d,d,d);

    painter.drawLine(QPoint(9*d-dis,4*d-dis-length),QPoint(9*d-dis,4*d-dis));
    painter.drawLine(QPoint(9*d-dis,4*d-dis),QPoint(9*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(9*d-dis,4*d+dis),QPoint(9*d-dis,4*d+dis+length));
    painter.drawLine(QPoint(9*d-dis,4*d+dis),QPoint(9*d-dis-length,4*d+dis));

    painter.drawEllipse(8.5*d,3.5*d,d,d);

    painter.drawLine(QPoint(9*d-dis,7*d-dis-length),QPoint(9*d-dis,7*d-dis));
    painter.drawLine(QPoint(9*d-dis,7*d-dis),QPoint(9*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(9*d-dis,7*d+dis),QPoint(9*d-dis,7*d+dis+length));
    painter.drawLine(QPoint(9*d-dis,7*d+dis),QPoint(9*d-dis-length,7*d+dis));

    painter.drawEllipse(8.5*d,6.5*d,d,d);

    painter.drawLine(QPoint(2*d-dif,3*d-dis),QPoint(2*d-dif,3*d-dis-length));
    painter.drawLine(QPoint(2*d-dif,3*d-dis),QPoint(2*d-dis-length,3*d-dis));
    painter.drawLine(QPoint(2*d-dif,3*d+dis),QPoint(2*d-dif,3*d+dis+length));
    painter.drawLine(QPoint(2*d-dif,3*d+dis),QPoint(2*d-dis-length,3*d+dis));
    painter.drawLine(QPoint(2*d+dif,3*d-dis),QPoint(2*d+dif,3*d-dis-length));
    painter.drawLine(QPoint(2*d+dif,3*d-dis),QPoint(2*d+dis+length,3*d-dis));
    painter.drawLine(QPoint(2*d+dif,3*d+dis),QPoint(2*d+dif,3*d+dis+length));
    painter.drawLine(QPoint(2*d+dif,3*d+dis),QPoint(2*d+dis+length,3*d+dis));

    painter.drawEllipse(1.5*d,2.5*d,d,d);

    painter.drawLine(QPoint(2*d-dif,8*d-dis),QPoint(2*d-dif,8*d-dis-length));
    painter.drawLine(QPoint(2*d-dif,8*d-dis),QPoint(2*d-dis-length,8*d-dis));
    painter.drawLine(QPoint(2*d-dif,8*d+dis),QPoint(2*d-dif,8*d+dis+length));
    painter.drawLine(QPoint(2*d-dif,8*d+dis),QPoint(2*d-dis-length,8*d+dis));
    painter.drawLine(QPoint(2*d+dif,8*d-dis),QPoint(2*d+dif,8*d-dis-length));
    painter.drawLine(QPoint(2*d+dif,8*d-dis),QPoint(2*d+dis+length,8*d-dis));
    painter.drawLine(QPoint(2*d+dif,8*d+dis),QPoint(2*d+dif,8*d+dis+length));
    painter.drawLine(QPoint(2*d+dif,8*d+dis),QPoint(2*d+dis+length,8*d+dis));

    painter.drawEllipse(1.5*d,7.5*d,d,d);

    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dis+length,4*d+dis));

    painter.drawEllipse(2.5*d,3.5*d,d,d);

    painter.drawLine(QPoint(3*d-dif,7*d-dis),QPoint(3*d-dif,7*d-dis-length));
    painter.drawLine(QPoint(3*d-dif,7*d-dis),QPoint(3*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(3*d-dif,7*d+dis),QPoint(3*d-dif,7*d+dis+length));
    painter.drawLine(QPoint(3*d-dif,7*d+dis),QPoint(3*d-dis-length,7*d+dis));
    painter.drawLine(QPoint(3*d+dif,7*d-dis),QPoint(3*d+dif,7*d-dis-length));
    painter.drawLine(QPoint(3*d+dif,7*d-dis),QPoint(3*d+dis+length,7*d-dis));
    painter.drawLine(QPoint(3*d+dif,7*d+dis),QPoint(3*d+dif,7*d+dis+length));
    painter.drawLine(QPoint(3*d+dif,7*d+dis),QPoint(3*d+dis+length,7*d+dis));

    painter.drawEllipse(2.5*d,6.5*d,d,d);

    painter.drawLine(QPoint(5*d-dif,4*d-dis),QPoint(5*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(5*d-dif,4*d-dis),QPoint(5*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(5*d-dif,4*d+dis),QPoint(5*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(5*d-dif,4*d+dis),QPoint(5*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(5*d+dif,4*d-dis),QPoint(5*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(5*d+dif,4*d-dis),QPoint(5*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(5*d+dif,4*d+dis),QPoint(5*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(5*d+dif,4*d+dis),QPoint(5*d+dis+length,4*d+dis));

    painter.drawEllipse(4.5*d,3.5*d,d,d);

    painter.drawLine(QPoint(5*d-dif,7*d-dis),QPoint(5*d-dif,7*d-dis-length));
    painter.drawLine(QPoint(5*d-dif,7*d-dis),QPoint(5*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(5*d-dif,7*d+dis),QPoint(5*d-dif,7*d+dis+length));
    painter.drawLine(QPoint(5*d-dif,7*d+dis),QPoint(5*d-dis-length,7*d+dis));
    painter.drawLine(QPoint(5*d+dif,7*d-dis),QPoint(5*d+dif,7*d-dis-length));
    painter.drawLine(QPoint(5*d+dif,7*d-dis),QPoint(5*d+dis+length,7*d-dis));
    painter.drawLine(QPoint(5*d+dif,7*d+dis),QPoint(5*d+dif,7*d+dis+length));
    painter.drawLine(QPoint(5*d+dif,7*d+dis),QPoint(5*d+dis+length,7*d+dis));

    painter.drawEllipse(4.5*d,6.5*d,d,d);

    painter.drawLine(QPoint(7*d-dif,4*d-dis),QPoint(7*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(7*d-dif,4*d-dis),QPoint(7*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(7*d-dif,4*d+dis),QPoint(7*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(7*d-dif,4*d+dis),QPoint(7*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(7*d+dif,4*d-dis),QPoint(7*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(7*d+dif,4*d-dis),QPoint(7*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(7*d+dif,4*d+dis),QPoint(7*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(7*d+dif,4*d+dis),QPoint(7*d+dis+length,4*d+dis));

    painter.drawEllipse(6.5*d,3.5*d,d,d);

    painter.drawLine(QPoint(7*d-dif,7*d-dis),QPoint(7*d-dif,7*d-dis-length));
    painter.drawLine(QPoint(7*d-dif,7*d-dis),QPoint(7*d-dis-length,7*d-dis));
    painter.drawLine(QPoint(7*d-dif,7*d+dis),QPoint(7*d-dif,7*d+dis+length));
    painter.drawLine(QPoint(7*d-dif,7*d+dis),QPoint(7*d-dis-length,7*d+dis));
    painter.drawLine(QPoint(7*d+dif,7*d-dis),QPoint(7*d+dif,7*d-dis-length));
    painter.drawLine(QPoint(7*d+dif,7*d-dis),QPoint(7*d+dis+length,7*d-dis));
    painter.drawLine(QPoint(7*d+dif,7*d+dis),QPoint(7*d+dif,7*d+dis+length));
    painter.drawLine(QPoint(7*d+dif,7*d+dis),QPoint(7*d+dis+length,7*d+dis));

    painter.drawEllipse(6.5*d,6.5*d,d,d);

    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d-dif,4*d-dis),QPoint(3*d-dis-length,4*d-dis));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d-dif,4*d+dis),QPoint(3*d-dis-length,4*d+dis));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dif,4*d-dis-length));
    painter.drawLine(QPoint(3*d+dif,4*d-dis),QPoint(3*d+dis+length,4*d-dis));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dif,4*d+dis+length));
    painter.drawLine(QPoint(3*d+dif,4*d+dis),QPoint(3*d+dis+length,4*d+dis));

    painter.drawEllipse(2.5*d,3.5*d,d,d);

    painter.drawLine(QPoint(8*d-dif,3*d-dis),QPoint(8*d-dif,3*d-dis-length));
    painter.drawLine(QPoint(8*d-dif,3*d-dis),QPoint(8*d-dis-length,3*d-dis));
    painter.drawLine(QPoint(8*d-dif,3*d+dis),QPoint(8*d-dif,3*d+dis+length));
    painter.drawLine(QPoint(8*d-dif,3*d+dis),QPoint(8*d-dis-length,3*d+dis));
    painter.drawLine(QPoint(8*d+dif,3*d-dis),QPoint(8*d+dif,3*d-dis-length));
    painter.drawLine(QPoint(8*d+dif,3*d-dis),QPoint(8*d+dis+length,3*d-dis));
    painter.drawLine(QPoint(8*d+dif,3*d+dis),QPoint(8*d+dif,3*d+dis+length));
    painter.drawLine(QPoint(8*d+dif,3*d+dis),QPoint(8*d+dis+length,3*d+dis));

    painter.drawEllipse(7.5*d,2.5*d,d,d);

    painter.drawLine(QPoint(8*d-dif,8*d-dis),QPoint(8*d-dif,8*d-dis-length));
    painter.drawLine(QPoint(8*d-dif,8*d-dis),QPoint(8*d-dis-length,8*d-dis));
    painter.drawLine(QPoint(8*d-dif,8*d+dis),QPoint(8*d-dif,8*d+dis+length));
    painter.drawLine(QPoint(8*d-dif,8*d+dis),QPoint(8*d-dis-length,8*d+dis));
    painter.drawLine(QPoint(8*d+dif,8*d-dis),QPoint(8*d+dif,8*d-dis-length));
    painter.drawLine(QPoint(8*d+dif,8*d-dis),QPoint(8*d+dis+length,8*d-dis));
    painter.drawLine(QPoint(8*d+dif,8*d+dis),QPoint(8*d+dif,8*d+dis+length));
    painter.drawLine(QPoint(8*d+dif,8*d+dis),QPoint(8*d+dis+length,8*d+dis));

    //绘制棋子
    painter.drawEllipse(7.5*d,7.5*d,d,d);
    for(int i=1;i<=9;i++)
    {
        painter.drawEllipse(d*(i-0.5),0.5*d,d,d);
    }
    for(int i=1;i<=9;i++)
    {
        painter.drawEllipse(d*(i-0.5),9.5*d,d,d);
    }
    QFont font("Arial", 12); // 创建字体对象
    font.setPointSize(16); // 设置字体大小
    painter.setFont(font);
    painter.setPen(Qt::red);
    for(int i=1;i<=5;i++)
    {
        QRect rect_chess((2*i-1.5)*d,6.5*d,d,d);
        QString chess = "兵";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((6*i-4.5)*d,7.5*d,d,d);
        QString chess = "炮";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((8*i-7.5)*d,9.5*d,d,d);
        QString chess = "车";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((6*i-4.5)*d,9.5*d,d,d);
        QString chess = "馬";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((4*i-1.5)*d,9.5*d,d,d);
        QString chess = "相";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((2*i+1.5)*d,9.5*d,d,d);
        QString chess = "仕";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QString chess;
        if(i==1)
        {
            painter.setPen(Qt::black);
            chess= "将";
        }
        else
        {
            painter.setPen(Qt::red);
            chess = "帅";
        }
        QRect rect_chess(4.5*d,(9*i-8.5)*d,d,d);
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    painter.setPen(Qt::black);
    for(int i=1;i<=5;i++)
    {
        QRect rect_chess((2*i-1.5)*d,3.5*d,d,d);
        QString chess = "卒";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((6*i-4.5)*d,2.5*d,d,d);
        QString chess = "砲";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((8*i-7.5)*d,0.5*d,d,d);
        QString chess = "車";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((6*i-4.5)*d,0.5*d,d,d);
        QString chess = "马";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((4*i-1.5)*d,0.5*d,d,d);
        QString chess = "象";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    for(int i=1;i<=2;i++)
    {
        QRect rect_chess((2*i+1.5)*d,0.5*d,d,d);
        QString chess = "士";
        painter.drawText(rect_chess, Qt::AlignCenter, chess);
    }
    QString text = "楚河";
    QString text1 = "漢界";
    QRect rect(d, 5*d, 4*d, d);
    QRect rect1(5*d, 5*d, 4*d, d);
    painter.drawText(rect, Qt::AlignCenter, text);
    painter.drawText(rect1, Qt::AlignCenter, text1);
}
