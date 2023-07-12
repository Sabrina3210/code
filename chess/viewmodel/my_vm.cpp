#include "my_vm.h"

my_vm::my_vm()
{

}
my_vm::~my_vm()
{

}
void my_vm::set_model(std::shared_ptr<Board> b)
{
    board=b;
}
