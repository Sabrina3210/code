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
    std::shared_ptr<Board> board(std::make_shared<Board>());
    std::shared_ptr<MyModel> Model(std::make_shared<MyModel>());
    ViewModel = std::make_shared<my_vm>();
    ViewModel->set_model(Model);
    w.set_board(board);
    //binding
    // properties
    //w.set_board(ViewModel->get_model());
    // commands
    w.set_left_click_command(ViewModel->get_click_command());
//    w.set_leftblock_command(ViewModel->get_leftblock_command());

//    // notifications
    ViewModel->AddPropertyNotification(w.get_propertty_sink());
    w.setWindowTitle("Chinese chess");
    //widget.init();
    w.show();
    return true;
}

