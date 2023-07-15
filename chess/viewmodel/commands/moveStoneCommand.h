#ifndef MOVESTONECOMMAND_H
#define MOVESTONECOMMAND_H

#include "../../common/etlbase.h"
#include"../../common/parameter.h"

class my_vm;
class movechesscommand : public ICommandBase
{
public:
    movechesscommand(my_vm* p) throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();
private:
    my_vm* VM;
    DesParameter m_lparam;

};
#endif
