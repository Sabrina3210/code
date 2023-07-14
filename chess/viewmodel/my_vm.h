#ifndef MY_VM_H
#define MY_VM_H
#include"../model/my_model.h"
#include "..//common/etlbase.h"
#include"commands/moveStoneCommand.h"
#include"sinks/my_vmsink.h"
class my_vm: public Proxy_CommandNotification<my_vm>, public Proxy_PropertyNotification<my_vm>
{
public:
    my_vm();
    ~my_vm();
    std::shared_ptr<Board> get_board();
    void set_model(std::shared_ptr<MyModel> b);

    std::shared_ptr<ICommandBase> get_move_command() throw();
    bool movechess(int x,int y,int id);
    std::shared_ptr<IPropertyNotification> get_propertty_sink() throw();
private:
    std::shared_ptr<MyModel> Model;
    std::shared_ptr<movechesscommand> move_command;
    std::shared_ptr<ViewModelSink>m_sink_property;
};

#endif // MY_VM_H
