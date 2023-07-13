#ifndef CLICK_COMMAND_H
#define CLICK_COMMAND_H
#include "..//..//common/etlbase.h"
#include "model/my_model.h"

class click_command: public ICommandBase
{
public:
    click_command(MyModel* p)throw();
    virtual void SetParameter(const std::any &lparam);
    virtual void Exec();
private:
    MyModel* m_pVM;

    //PosParameter m_lparam;
};

#endif // CLICK_COMMAND_H
