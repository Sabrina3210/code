#include "funnychess.h"

FunnyChess::FunnyChess()
{
    memset(board, 0, sizeof(board));
    new Jiang(Point(0, 0), RED, *this);
    new Jiang(Point(0, 1), BLACK, *this);
    new Ju(Point(0, 2), RED, *this);
    new Ju(Point(0, 3), BLACK, *this);
    new Xiang(Point(0, 4), RED, *this);
    new Xiang(Point(0, 5), BLACK, *this);
    new Ma(Point(0, 6), RED, *this);
    new Ma(Point(0, 7), BLACK, *this);
    new Shi(Point(1, 0), RED, *this);
    new Shi(Point(1, 1), RED, *this);
    new Ju(Point(1, 2), RED, *this);
    new Ju(Point(1, 3), BLACK, *this);
    new Shi(Point(1, 4), RED, *this);
    new Shi(Point(1, 5), RED, *this);
    new Ma(Point(1, 6), RED, *this);
    new Ma(Point(1, 7), BLACK, *this);
    new Xiang(Point(2, 0), RED, *this);
    new Xiang(Point(2, 1), BLACK, *this);
    new Pao(Point(2, 2), RED, *this);
    new Pao(Point(2, 3), BLACK, *this);
    new Pao(Point(2, 4), RED, *this);
    new Pao(Point(2, 5), BLACK, *this);
    new Bing(Point(2, 6), RED, *this);
    new Bing(Point(2, 7), RED, *this);
    new Bing(Point(3, 0), RED, *this);
    new Bing(Point(3, 1), RED, *this);
    new Bing(Point(3, 2), RED, *this);
    new Bing(Point(3, 3), BLACK, *this);
    new Bing(Point(3, 4), BLACK, *this);
    new Bing(Point(3, 5), BLACK, *this);
    new Bing(Point(3, 6), BLACK, *this);
    new Bing(Point(3, 7), BLACK, *this);
}

FunnyChess::~FunnyChess()
{
    for (ChessPiece *p : red)
        delete p;
    for (ChessPiece *p : black)
        delete p;
}

bool ChessPiece::MoveTo(const Point &point)
{
    if (CanMoveTo(point))
    {
        board.GetChess(pt) = nullptr;
        pt.x = point.x;
        pt.y = point.y;
        board.RemoveChess(point);
        board.GetChess(point) = this;
        return true;
    }
    return false;
}

void FunnyChess::RemoveChess(const Point &point)
{
    if (GetChess(point))
    {
        if (GetChess(point)->cl == RED)
        {
            red.erase(std::find(red.begin(), red.end(), GetChess(point)));
        }
        else
        {
            black.erase(std::find(black.begin(), black.end(), GetChess(point)));
        }
        //        delete GetChess(point);
        GetChess(point) = nullptr;
    }
}
