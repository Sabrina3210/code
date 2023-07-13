#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include"QMouseEvent"
#include"..//common/etlbase.h"
#include"sink/SinkProperty.h"
#include"../common/Board.h"
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
//commmand
    void set_left_click_command(const std::shared_ptr<ICommandBase>& cmd);
    void set_draw_chess_command(const std::shared_ptr<ICommandBase>& cmd);
    void set_board(const std:: shared_ptr<Board> b);
    std::shared_ptr<IPropertyNotification> get_propertty_sink() throw();
    //click click_t;
private:
    Ui::MyWidget *ui;
    std::shared_ptr<ICommandBase> click_command;
    std::shared_ptr<Board> board;
    //std::shared_ptr<SinkProperty> m_sink_property;
    //my_vm vm;
};
#endif // MYWIDGET_H
