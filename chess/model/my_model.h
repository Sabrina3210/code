#ifndef MY_MODEL_H
#define MY_MODEL_H
#include"../common/etlbase.h"
#include"../common/Board.h"

class MyModel : public Proxy_PropertyNotification<MyModel>
{
public:
    MyModel();
    std::shared_ptr<Board> get_board() throw();
    //provide interface of functions
    void init_game();
    void leftchess(int x,int y);
//    bool restart(int row, int col, int boom_num);
//    bool leftblock(int x_pos, int y_pos);
//    bool rightblock(int x_pos, int y_pos);
private:
    std::shared_ptr<Board> b;
};

#endif // MSDATAMODEL_H
