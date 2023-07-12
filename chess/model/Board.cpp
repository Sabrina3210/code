#include"Board.h"
Board::Board()
{
    for(int i=0;i<32;i++)
        chess[i].init(i);
}
Board::~Board()
{

}
Stone* Board::getstone()
{
    return chess;
}

