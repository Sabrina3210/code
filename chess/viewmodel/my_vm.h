#ifndef MY_VM_H
#define MY_VM_H
#include"../model/my_model.h"
#include "..//common/etlbase.h"
#include"commands/moveStoneCommand.h"
#include"commands/flipoverChessCommand.h"
#include"commands/moveStoneCommand_f.h"
#include"commands/restartcommand.h"
#include"commands/backcommand.h"
#include"commands/f_restartcommand.h"
#include"sinks/my_vmsink.h"
class my_vm: public Proxy_CommandNotification<my_vm>, public Proxy_PropertyNotification<my_vm>
{
public:
    my_vm();
    ~my_vm();
    std::shared_ptr<Board> get_board();
    std::shared_ptr<F_Board> get_FBoard();
    void set_model(std::shared_ptr<MyModel> b);

    std::shared_ptr<ICommandBase> get_move_command() throw();
    std::shared_ptr<ICommandBase> get_flipover_command() throw();
    std::shared_ptr<ICommandBase> get_move_command_f() throw();
    std::shared_ptr<ICommandBase> get_restart_command() throw();
    std::shared_ptr<ICommandBase> get_back_command() throw();
    std::shared_ptr<ICommandBase> get_f_restart_command() throw();
    bool movechess(int x,int y,int id);
    bool flipoverchess(int id);
    bool movechess_f(int x,int y,int id);
    bool restart();
    bool backchess();
    bool f_restart();
    std::shared_ptr<IPropertyNotification> get_propertty_sink() throw();
private:
    std::shared_ptr<MyModel> Model;
    std::shared_ptr<movechesscommand> move_command;
    std::shared_ptr<flipoverChessCommand> flipoverCommand;
    std::shared_ptr<movechesscommand_f> move_command_f;
    std::shared_ptr<restartCommand> restartcommand;
    std::shared_ptr<f_restartCommand> f_restartcommand;
    std::shared_ptr<backCommand> backcommand;
    std::shared_ptr<ViewModelSink>m_sink_property;
};

#endif // MY_VM_H
