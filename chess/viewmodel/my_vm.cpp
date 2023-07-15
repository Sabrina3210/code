#include "my_vm.h"

my_vm::my_vm()
{
    move_command=std::make_shared<movechesscommand>(this) ;
    flipoverCommand =std::make_shared<flipoverChessCommand>(this);
    move_command_f=std::make_shared<movechesscommand_f>(this);
    restartcommand=std::make_shared<restartCommand>(this);
    backcommand=std::make_shared<backCommand>(this);
    f_restartcommand=std::make_shared<f_restartCommand>(this);
    m_sink_property=std::make_shared<ViewModelSink>(this);
}
my_vm::~my_vm()
{

}
void my_vm::set_model(std::shared_ptr<MyModel> b)
{
    Model=b;
}
std::shared_ptr<ICommandBase> my_vm::get_move_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(move_command);
}
std::shared_ptr<ICommandBase> my_vm::get_flipover_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(flipoverCommand);
}
std::shared_ptr<ICommandBase> my_vm::get_move_command_f() throw()
{
    return std::static_pointer_cast<ICommandBase>(move_command_f);
}
std::shared_ptr<ICommandBase> my_vm::get_restart_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(restartcommand);
}
std::shared_ptr<ICommandBase> my_vm::get_f_restart_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(f_restartcommand);
}
std::shared_ptr<ICommandBase> my_vm::get_back_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(backcommand);
}
std::shared_ptr<Board> my_vm::get_board()
{
    return Model->get_board();
}
std::shared_ptr<F_Board> my_vm::get_FBoard()
{
    return Model->get_FBoard();
}
bool my_vm::movechess(int x,int y,int id)
{
    return Model->movechess(x,y,id);
}
bool my_vm::flipoverchess(int id)
{
    return Model->flipoverchess(id);
}
bool my_vm::movechess_f(int x,int y, int id)
{
    return Model->movechess_f(x,y,id);
}
bool my_vm::restart()
{
    return Model->restart();
}
bool my_vm::f_restart()
{
    return Model->f_restart();
}
bool my_vm::backchess()
{
    return Model->RecoverLastStep();
}
std::shared_ptr<IPropertyNotification> my_vm::get_propertty_sink() throw()
{
    return std::static_pointer_cast<IPropertyNotification>(m_sink_property);
}
