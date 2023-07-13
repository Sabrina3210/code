#include"my_model.h"
MyModel::MyModel()
{

}
std::shared_ptr<Board> MyModel::get_board()throw()
{
    return b;
}
void MyModel::init_game()
{
    b->init();
}
void MyModel::leftchess(int x,int y)
{
    int i;
    for(i=0;i<32;i++)
    {

    }
    b->select_id=i;
}
