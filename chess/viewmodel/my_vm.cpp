#include "my_vm.h"

my_vm::my_vm()
{

}
my_vm::~my_vm()
{

}
void my_vm::set_model(std::shared_ptr<MyModel>& b)
{
    Model=b;
}
std::shared_ptr<ICommandBase> my_vm::get_click_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(click_command);
}
std::shared_ptr<MyModel>& my_vm::get_model()
{
    return Model;
}
