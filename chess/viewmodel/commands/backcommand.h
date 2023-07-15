#ifndef BACKCOMMAND_H
#define BACKCOMMAND_H
#include "../../common/etlbase.h"
#include"../../common/parameter.h"
class my_vm;
class backCommand: public ICommandBase
{
public:
    backCommand(my_vm* p)throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();
private:
    my_vm* VM;
};

#endif // BACKCOMMAND_H
