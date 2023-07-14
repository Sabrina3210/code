#include"moveStoneCommand.h"
#include"..//my_vm.h"
movechesscommand::movechesscommand(my_vm* p) throw():VM(p)
{

}
void movechesscommand::SetParameter(const std::any &lparam)
{

}
void movechesscommand::Exec()
{
    int x=0,y=0;

    VM->movechess(x,y);
}
