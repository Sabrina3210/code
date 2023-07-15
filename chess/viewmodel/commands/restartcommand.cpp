#include "restartcommand.h"
#include"..//my_vm.h"
restartCommand::restartCommand(my_vm* p) throw():VM(p)
{

}
void restartCommand::SetParameter(const std::any& param)
{

}
void restartCommand::Exec()
{
    VM->restart();
}


