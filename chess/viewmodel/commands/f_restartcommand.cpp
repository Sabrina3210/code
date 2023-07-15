#include "f_restartcommand.h"
#include"../my_vm.h"
f_restartCommand::f_restartCommand(my_vm *p)throw():VM(p)
{

}

void f_restartCommand::SetParameter(const std::any& param)
{

}
void f_restartCommand::Exec()
{
    VM->f_restart();
}
