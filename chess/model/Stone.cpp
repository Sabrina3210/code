#include"Stone.h"
Stone::Stone()
{

}
Stone::~Stone()
{

}
QString Stone::name()
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

void Stone::init(int id)
{
    struct {
        int row, col;
        Stone::TYPE type;
    } pos[16] = {
    {1, 1, Stone::CHE},
    {2, 1, Stone::MA},
    {3, 1, Stone::XIANG},
    {4, 1, Stone::SHI},
    {5, 1, Stone::JIANG},
    {6, 1, Stone::SHI},
    {7, 1, Stone::XIANG},
    {8, 1, Stone::MA},
    {9, 1, Stone::CHE},

    {2, 3, Stone::PAO},
    {8, 3, Stone::PAO},
    {1, 4, Stone::BING},
    {3, 4, Stone::BING},
    {5, 4, Stone::BING},
    {7, 4, Stone::BING},
    {9, 4, Stone::BING},
    };

    if(id < 16)
    {
        this->_col = pos[id].col;
        this->_row = pos[id].row;
        this->_type = pos[id].type;
    }
    else
    {
        this->_col = 11-pos[id-16].col;
        this->_row = pos[id-16].row;
        this->_type = pos[id-16].type;
    }

    this->_dead = false;
    this->_red = id<16;
}

