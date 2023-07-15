#include"moveStoneCommand_f.h"
#include"..//my_vm.h"
movechesscommand_f::movechesscommand_f(my_vm* p) throw():VM(p)
{

}
void movechesscommand_f::SetParameter(const std::any& param)
{
    m_lparam = std::any_cast<DesParameter>(param);
}
void movechesscommand_f::Exec()
{
    VM->movechess_f(m_lparam.row,m_lparam.col,m_lparam.select_id);
}
