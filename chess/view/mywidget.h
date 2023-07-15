#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QMouseEvent>
#include <QPushButton>
#include"../common/etlbase.h"
#include"../common/Board.h"
#include"../common/F_Board.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

#include"sink/SinkProperty.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void paintEvent(QPaintEvent *);
    void drawchess(QPainter& p,int id,bool type);
    void mouseReleaseEvent(QMouseEvent *ev);

//commmand
    void set_move_command(const std::shared_ptr<ICommandBase>& cmd);
    void set_flip_over_command(const std::shared_ptr<ICommandBase>& cmd);
    void set_move_command_f(const std::shared_ptr<ICommandBase>& cmd);
    void set_restart_command(const std::shared_ptr<ICommandBase>& cmd);
    void set_f_restart_command(const std::shared_ptr<ICommandBase>& cmd);
    void set_back_command(const std::shared_ptr<ICommandBase>& cmd);
    void set_board(const std:: shared_ptr<Board> b);
    void set_FBoard(const std:: shared_ptr<F_Board> f);
    std::shared_ptr<IPropertyNotification> get_propertty_sink() throw();
    //click click_t;
    bool game_type;
private:

    Ui::MyWidget *ui;
    QPushButton * back_button;
    QPushButton * f_restart_button;
    QPushButton * restart_button;
    QPushButton * close_button;
    std::shared_ptr<ICommandBase> move_command;
    std::shared_ptr<ICommandBase> flip_over_command;
    std::shared_ptr<ICommandBase> move_command_f;
    std::shared_ptr<ICommandBase> restart_command;
    std::shared_ptr<ICommandBase> f_restart_command;
    std::shared_ptr<ICommandBase> back_command;
    std::shared_ptr<Board> board;
    std::shared_ptr<F_Board> FBoard;
    std::shared_ptr<SinkProperty> m_sink_property;
    int select_id;
};
#endif // MYWIDGET_H
