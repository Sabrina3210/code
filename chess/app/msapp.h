#ifndef MSAPP_H
#define MSAPP_H
#include<QApplication>
#include "../viewmodel/my_vm.h"
#include "../view/mywidget.h"
#include"../model/Board.h"
////////////////////////////////////////////////////////////////////////////////

class msapp
{
public:
    msapp();
    ~msapp() throw();

    bool Init(MyWidget& w);
    void run();
private:
    std::shared_ptr<my_vm>  ViewModel;
    std::shared_ptr<Board>  Model;
    MyWidget  widget;
};
#endif
