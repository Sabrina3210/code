#ifndef MY_VM_H
#define MY_VM_H
#include"../model/my_model.h"
#include "..//common/etlbase.h"
class my_vm: public Proxy_CommandNotification<my_vm>, public Proxy_PropertyNotification<my_vm>
{
public:
    my_vm();
    ~my_vm();
    std::shared_ptr<MyModel>& get_model();
    void set_model(std::shared_ptr<MyModel>& b);
    std::shared_ptr<ICommandBase> get_click_command() throw();

private:
    std::shared_ptr<MyModel> Model;
    std::shared_ptr<ICommandBase> click_command;
};

#endif // MY_VM_H
