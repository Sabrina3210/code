#include<random>
#include<ctime>
#include"F_Board.h"

F_Board::F_Board()
{
    unsigned seed;
    seed=time(0);
    srand(seed);
    int a[32];
    for(int i=0;i<32;i++)
    {
        a[i]=i;
        cover[i]=false;
    }
    for(int i=31;i>=1;i--)
    {
        std::swap(a[i],a[rand()%i]);
    }
    for(int i=0; i<32; ++i)
    {
        chess[i].init(i);
        chess[i]._row=a[i]/4+1;
        chess[i]._col=a[i]%4+1;
        chess[i]._id=i;
    }

}
F_Board::~F_Board()
{

}
F_Stone* F_Board::getstone()
{
    return chess;
}
F_Stone::F_Stone()
{

}
F_Stone::~F_Stone()
{

}
QString F_Stone::name()
{
    switch(this->_type)
    {
    case CHE:
        if(this->_red)
        return QString::fromUtf8("车");
        else
        return QString::fromUtf8("車");
    case MA:
        if(this->_red)
        return QString::fromUtf8("马");
        else
        return QString::fromUtf8("馬");
    case PAO:
        if(this->_red)
        return QString::fromUtf8("炮");
        else
        return QString::fromUtf8("砲");
    case BING:
        if(this->_red)
        return QString::fromUtf8("兵");
        else
        return QString::fromUtf8("卒");
    case JIANG:
        if(this->_red)
        return QString::fromUtf8("帅");
        else
        return "将";
    case SHI:
        if(this->_red)
        return QString::fromUtf8("仕");
        else
        return "士";
    case XIANG:
        if(this->_red)
        return "相";
        else
        return "象";
    }
    return "错误";
}

void F_Stone::init(int id)
{

    struct {
        int row, col;
        F_Stone::TYPE type;
        int level;
    } pos[32] = {
    {1, 1, F_Stone::CHE,3},
    {2, 1, F_Stone::MA,4},
    {3, 1, F_Stone::XIANG,5},
    {4, 1, F_Stone::SHI,6},
    {5, 1, F_Stone::JIANG,7},
    {6, 1, F_Stone::SHI,6},
    {7, 1, F_Stone::XIANG,5},
    {8, 1, F_Stone::MA,4},

    {8, 2, F_Stone::CHE,3},
    {1, 2, F_Stone::PAO,2},
    {2, 2, F_Stone::PAO,2},
    {3, 2, F_Stone::BING,1},
    {4, 2, F_Stone::BING,1},
    {5, 2, F_Stone::BING,1},
    {6, 2, F_Stone::BING,1},
    {7, 2, F_Stone::BING,1},

        {1, 3, F_Stone::CHE,3},
        {2, 3, F_Stone::MA,4},
        {3, 3, F_Stone::XIANG,5},
        {4, 3, F_Stone::SHI,6},
        {5, 3, F_Stone::JIANG,7},
        {6, 3, F_Stone::SHI,6},
        {7, 3, F_Stone::XIANG,5},
        {8, 3, F_Stone::MA,4},

        {8, 4, F_Stone::CHE,3},
        {1, 4, F_Stone::PAO,2},
        {2, 4, F_Stone::PAO,2},
        {3, 4, F_Stone::BING,1},
        {4, 4, F_Stone::BING,1},
        {5, 4, F_Stone::BING,1},
        {6, 4, F_Stone::BING,1},
        {7, 4, F_Stone::BING,1},
    };

    if(id < 32)
    {
        this->_col = pos[id].col;
        this->_row = pos[id].row;
        this->_type = pos[id].type;
        this->_level = pos[id].level;
    }

    this->_dead = false;
    this->_red = id>=16;
    this->_id=id;
}

