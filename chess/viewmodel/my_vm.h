#ifndef MY_VM_H
#define MY_VM_H
#include<QObject>
#include"../model/Board.h"
class my_vm:public QObject
{
public:
    my_vm();
    ~my_vm();
    void set_model(std::shared_ptr<Board> b);
private:
    std::shared_ptr<Board> board;
};

#endif // MY_VM_H
