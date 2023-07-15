#include "mywidget.h"
#include "qpainter.h"
#include "ui_mywidget.h"
#include"..//common/parameter.h"
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    m_sink_property=std::make_shared<SinkProperty>(this) ;
    select_id=-1;
    game_type=false;
}

MainWidget::~MainWidget()
{
    delete ui;
}
void MainWidget::set_board(const std:: shared_ptr<Board> b)
{
    this->board=b;
}
void MainWidget::set_FBoard(const std:: shared_ptr<F_Board> f)
{
    this->FBoard=f;
}
void MainWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    int d = this->height() / 11;
    double x=ev->pos().x();
    double y=ev->pos().y();
    if(game_type)
    {
        double row=x/d;
        double col=y/d;
        if(row>9.5||row<0.5||col>10.5||col<0.5)
        {
            //qDebug()<<"error";
            return;
        }
        for(int i=1;i<10;i++)
        {
            for(int j=1;j<11;j++)
            {
                double dis=(row-i)*(row-i)+(col-j)*(col-j);
                if(dis<0.25)
                {
                    row=i;
                    col=j;
                    break;
                }
            }
        }
        if(select_id!=-1)
        {
            std::any param1 (std::make_any<DesParameter>());
            DesParameter& ts= std::any_cast<DesParameter&>(param1);
            ts.row = row;
            ts.col = col;
            ts.select_id = select_id;

            move_command->SetParameter(param1);
            move_command->Exec();
            select_id=-1;
            update();
        }
        else{
            int i;
            for(i=0;i<32;i++)
            {
                if(board->getstone()[i]._row==row&&board->getstone()[i]._col==col)
                {
                    select_id=i;
                    update();
                    break;
                }

            }
        }
        qDebug("%lf %lf",row,col);
    }
    else
    {
        double row=x/d;
        double col=y/d;
        if(row>8.5||row<0.5||col>4.5||col<0.5)
        {
            //qDebug()<<"error";
            return;
        }
        for(int i=1;i<9;i++)
        {
            for(int j=1;j<5;j++)
            {
                double dis=(row-i)*(row-i)+(col-j)*(col-j);
                if(dis<0.25)
                {
                    row=i;
                    col=j;
                    break;
                }
            }
        }
        if(select_id==-1)
        {
            int i;
            for(i=0;i<32;i++)
            {
                if(FBoard->getstone()[i]._row==row&&FBoard->getstone()[i]._col==col)
                {
                    int id=i;
                    if(FBoard->cover[id])
                    {
                        select_id=id;
                        update();
                        break;
                    }
                    else
                    {
                        std::any param1 (std::make_any<DesParameter>());
                        DesParameter & ts= std::any_cast<DesParameter&>(param1);
                        ts.col=col;
                        ts.row=row;
                        ts.select_id= id;

                        flip_over_command->SetParameter(param1);
                        flip_over_command->Exec();
                        select_id=-1;
                        update();
                        break;
                    }
                }
            }
        }
        else
        {
            std::any param1 (std::make_any<DesParameter>());
            DesParameter& ts= std::any_cast<DesParameter&>(param1);
            ts.row = row;
            ts.col = col;
            ts.select_id = select_id;
            move_command_f->SetParameter(param1);
            move_command_f->Exec();
            select_id=-1;
            update();
        }
    }
}
void MainWidget::set_move_command(const std::shared_ptr<ICommandBase>& cmd)
{
    move_command=cmd;
}
void MainWidget::set_flip_over_command(const std::shared_ptr<ICommandBase>& cmd)
{
    flip_over_command=cmd;
}
void MainWidget::set_move_command_f(const std::shared_ptr<ICommandBase>& cmd)
{
    move_command_f=cmd;
}
std::shared_ptr<IPropertyNotification> MainWidget::get_propertty_sink() throw()
{
    return std::static_pointer_cast<IPropertyNotification>(m_sink_property);
}
void MainWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //画10横线
    int d = this->height() / 11;
    if(game_type)
    {
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
    }
    else
    {
        for(int i=1;i<6;i++)
        {
            painter.drawLine(QPoint(0.5*d,(i-0.5)*d),QPoint(8.5*d,(i-0.5)*d));
        }
        //画9列
        for(int i=1;i<10;i++)
        {
            painter.drawLine(QPoint((i-0.5)*d,0.5*d),QPoint((i-0.5)*d,4.5*d));
        }

    }
    //绘制棋子
    for(int i=0;i<32;i++)
        drawchess(painter,i,game_type);

}
void MainWidget::drawchess(QPainter& painter,int id,bool type)
{
    int d = this->height() / 11;
    if(type)
    {
        Stone* chess=board->getstone();
         //qDebug("%d",board->chess[id]._id);
        if(chess[id]._dead==true) return;
        painter.drawEllipse((chess[id]._row-0.5)*d,(chess[id]._col-0.5)*d,d,d);


        if(id == select_id)
            painter.setBrush(Qt::gray);
        else painter.setBrush(Qt::yellow);

        //painter.setBrush(QBrush(Qt::yellow)); // 使用红色填充
        painter.setPen(Qt::NoPen); // 不画边框
        painter.drawEllipse((chess[id]._row-0.5)*d,(chess[id]._col-0.5)*d,d,d);

        QFont font("Arial", 12); // 创建字体对象
        font.setPointSize(16); // 设置字体大小
        painter.setFont(font);
        if(chess[id]._red)
            painter.setPen(Qt::red);
        else
            painter.setPen(Qt::black);
        QRect rect_chess((chess[id]._row-0.5)*d,(chess[id]._col-0.5)*d,d,d);
        QString word = chess[id].name();
        painter.drawText(rect_chess, Qt::AlignCenter, word);
        painter.setPen(Qt::black);
        QString text = "楚河";
        QString text1 = "漢界";
        QRect rect(d, 5*d, 4*d, d);
        QRect rect1(5*d, 5*d, 4*d, d);
        painter.drawText(rect, Qt::AlignCenter, text);
        painter.drawText(rect1, Qt::AlignCenter, text1);
    }
    else
    {
        F_Stone* chess=FBoard->getstone();
            //qDebug("%d",board->chess[id]._id);
        if(chess[id]._dead==true) return;
        painter.drawEllipse((chess[id]._row-0.5)*d,(chess[id]._col-0.5)*d,d,d);

        if(FBoard->cover[id])
        {
            if(id == select_id)
                painter.setBrush(Qt::gray);
            else painter.setBrush(Qt::yellow);
        }
        else
        {
            painter.setBrush(Qt::yellow);
        }
        //painter.setBrush(QBrush(Qt::yellow)); // 使用红色填充
        painter.setPen(Qt::NoPen); // 不画边框
        painter.drawEllipse((chess[id]._row-0.5)*d,(chess[id]._col-0.5)*d,d,d);
        if(FBoard->cover[id])
        {
            QFont font("Arial", 12); // 创建字体对象
            font.setPointSize(16); // 设置字体大小
            painter.setFont(font);
            if(chess[id]._red)
                painter.setPen(Qt::red);
            else
                painter.setPen(Qt::black);
            QRect rect_chess((chess[id]._row-0.5)*d,(chess[id]._col-0.5)*d,d,d);
            QString word = chess[id].name();
            painter.drawText(rect_chess, Qt::AlignCenter, word);
        }
    }

}
