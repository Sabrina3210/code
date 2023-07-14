#ifndef MOVESTONECOMMAND_H
#define MOVESTONECOMMAND_H

#include "../../common/etlbase.h"


class my_vm;
class movechesscommand : public ICommandBase
{
public:
    movechesscommand(my_vm* p) throw();
    virtual void SetParameter(const std::any &lparam);
    virtual void Exec();
private:
    my_vm* VM;

    //PosParameter m_lparam;

};
#endif
