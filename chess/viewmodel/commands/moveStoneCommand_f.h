#ifndef MOVESTONECOMMAND_F_H
#define MOVESTONECOMMAND_F_H

#include "../../common/etlbase.h"
#include"../../common/parameter.h"

class my_vm;
class movechesscommand_f : public ICommandBase
{
public:
    movechesscommand_f(my_vm* p) throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();
private:
    my_vm* VM;
    DesParameter m_lparam;

};
#endif
