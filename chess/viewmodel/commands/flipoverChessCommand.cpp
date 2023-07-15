#include"flipoverChessCommand.h"
#include"..//my_vm.h"
flipoverChessCommand::flipoverChessCommand(my_vm* p) throw():VM(p)
{

}
void flipoverChessCommand::SetParameter(const std::any& param)
{
    m_lparam = std::any_cast<DesParameter>(param);
}
void flipoverChessCommand::Exec()
{
    VM->flipoverchess(m_lparam.select_id);
}
