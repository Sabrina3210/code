#include "backcommand.h"
#include "../my_vm.h"
backCommand::backCommand(my_vm* p)throw():VM(p)
{

}
void backCommand::SetParameter(const std::any& param)
{

}
void backCommand::Exec()
{
    VM->backchess();
}
