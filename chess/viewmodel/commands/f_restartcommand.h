#ifndef F_RESTARTCOMMAND_H
#define F_RESTARTCOMMAND_H
#include "../../common/etlbase.h"
#include"../../common/parameter.h"
class my_vm;
class f_restartCommand:public ICommandBase
{
public:
    f_restartCommand(my_vm *p)throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();
private:
    my_vm* VM;
};

#endif // F_RESTARTCOMMAND_H


