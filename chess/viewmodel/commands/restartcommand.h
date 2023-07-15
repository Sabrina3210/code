#ifndef RESTARTCOMMAND_H
#define RESTARTCOMMAND_H

#include "../../common/etlbase.h"
#include"../../common/parameter.h"

class my_vm;
class restartCommand: public ICommandBase
{
public:
    restartCommand(my_vm* p)throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();
private:
    my_vm* VM;
};

#endif // RESTARTCOMMAND_H
