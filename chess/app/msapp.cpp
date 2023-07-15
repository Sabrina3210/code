#include"msapp.h"
msapp::msapp()
{

}
msapp::~msapp() throw()
{

}
bool msapp::Init(MainWidget& w)
{
    //objects
    std::shared_ptr<MyModel> Model(std::make_shared<MyModel>());
    ViewModel = std::make_shared<my_vm>();
    ViewModel->set_model(Model);
    //
    w.set_board(ViewModel->get_board());
    w.set_FBoard(ViewModel->get_FBoard());
    //binding
    // properties
    // commands
    w.set_move_command(ViewModel->get_move_command());
    w.set_flip_over_command(ViewModel->get_flipover_command());
    w.set_move_command_f(ViewModel->get_move_command_f());


    // notifications
    Model->AddPropertyNotification(ViewModel->get_propertty_sink());
    ViewModel->AddPropertyNotification(w.get_propertty_sink());
    w.setWindowTitle("Chinese chess");
    return true;
}

