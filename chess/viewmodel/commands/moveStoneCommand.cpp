#include"moveStoneCommand.h"
#include"..//my_vm.h"
movechesscommand::movechesscommand(my_vm* p) throw():VM(p)
{

}
void movechesscommand::SetParameter(const std::any& param)
{
    m_lparam = std::any_cast<DesParameter>(param);
}
void movechesscommand::Exec()
{
    VM->movechess(m_lparam.row,m_lparam.col,m_lparam.select_id);
}
