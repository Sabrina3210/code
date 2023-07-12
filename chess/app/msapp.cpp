#include"msapp.h"
msapp::msapp()
{

}
msapp::~msapp() throw()
{

}
bool msapp::Init(MyWidget& w)
{
    //objects
    Model = std::make_shared<Board>();
    ViewModel = std::make_shared<my_vm>();
    ViewModel->set_model(Model);
    //binding
    // properties
//    w.set_block(ViewModel->get_block());
    // commands
//    w.set_restart_command(ViewModel->get_restart_command());
//    w.set_leftblock_command(ViewModel->get_leftblock_command());
//    w.set_rightblock_command(ViewModel->get_rightblock_command());
//    w.set_setting_command(ViewModel->get_resetblock_command());
//    w.set_rank_command(ViewModel->get_rankadd_command());
//    // notifications
//    ViewModel->AddPropertyNotification(w.get_propertty_sink());
    widget.setWindowTitle("Chinese chess");
    //widget.init();
    widget.show();
    return true;
}
