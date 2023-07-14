#include"my_model.h"
MyModel::MyModel()
{
    b=std::make_shared<Board>();
    //b=source;
    //b=std::make_shared<Board>();
}
std::shared_ptr<Board> MyModel::get_board()throw()
{
    return b;
}
bool MyModel::movechess(int x,int y,int id)
{
    //function

    std::string str="move";
    Fire_OnPropertyChanged( str);
    return true;
}
