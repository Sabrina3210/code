#include "my_vm.h"

my_vm::my_vm()
{
    move_command=std::make_shared<movechesscommand>(this) ;
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
std::shared_ptr<Board> my_vm::get_board()
{
    return Model->get_board();
}
bool my_vm::movechess(int x,int y,int id)
{
    return Model->movechess(x,y,id);
}
std::shared_ptr<IPropertyNotification> my_vm::get_propertty_sink() throw()
{
    return std::static_pointer_cast<IPropertyNotification>(m_sink_property);
}
