#ifndef FUNNYCHESS_H
#define FUNNYCHESS_H
#include<list>

const bool BLACK = 0;
const bool RED = 1;
class Point
{
public:
    int x, y;
    Point(int nx, int ny) : x(nx), y(ny) {}
    bool IsSafe() const
    {
        return x >= 0 && x <= 3 && y >= 0 && y <= 7;
    }
};

bool operator==(const Point &a, const Point &b)
{
    return a.x == b.x && a.y == b.y;
}

class ChessPiece;

class FunnyChess
{
private:
    friend class ChessPiece;
    ChessPiece *board[4][8];
    std::list<ChessPiece *> red, black;
public:
    FunnyChess();
    const std::list<ChessPiece *> &GetRedPieces() const
    {
        return red;
    }
    const std::list<ChessPiece *> &GetBlackPieces() const
    {
        return black;
    }
    ChessPiece *&GetChess(const Point &point)
    {
        return board[point.x][point.y];
    }
    ChessPiece *const &GetChess(const Point &point) const
    {
        return board[point.x][point.y];
    }
    void RemoveChess(const Point &point);
    ~FunnyChess();
};

class ChessPiece
{
protected:
    Point pt;
    FunnyChess &board;

public:
    const bool cl;
    int Chesslevel;
    bool IfOverturn = 1;
    ChessPiece(const Point &point, bool color, FunnyChess &chessboard) : pt(point), board(chessboard),cl(color)
    {
        if (cl == BLACK)
            board.black.push_back(this);
        else
            board.red.push_back(this);
        board.GetChess(pt) = this;
    }
    const Point &GetPoint() const
    {
        return pt;
    }
    virtual bool CanMoveTo(const Point &point) const = 0;
    virtual const char *GetName() const = 0;
    bool MoveTo(const Point &point);
};

class Ju : public ChessPiece // 車
{
public:
    Ju(const Point &point, bool color, FunnyChess &chessboard) : ChessPiece(point, color, chessboard) { this->Chesslevel = 3; }
    virtual bool CanMoveTo(const Point &point) const override
    {
        static const Point s[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 車可以到达的四个点
        if (board.GetChess(point) == nullptr || (board.GetChess(point)->cl != this->cl &&
                                                 this->Chesslevel >= board.GetChess(point)->Chesslevel && board.GetChess(point)->IfOverturn == 1))
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (point == Point(pt.x + s[i].x, pt.y + s[i].y))
                {
                    return true;
                }
            }
        }
        return false;
    }
    virtual const char *GetName() const override
    {
        return "車";
    }
};

class Xiang : public ChessPiece // 象
{
public:
    Xiang(const Point &point, bool color, FunnyChess &chessboard) : ChessPiece(point, color, chessboard) { this->Chesslevel = 5; }
    virtual bool CanMoveTo(const Point &point) const override
    {
        static const Point s[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 象可以到达的四个点
        if (board.GetChess(point) == nullptr || (board.GetChess(point)->cl != this->cl && this->Chesslevel >= board.GetChess(point)->Chesslevel && board.GetChess(point)->IfOverturn == 1))
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (point == Point(pt.x + s[i].x, pt.y + s[i].y))
                {
                    return true;
                }
            }
        }
        return false;
    }
    virtual const char *GetName() const override
    {
        return cl == BLACK ? "象" : "相";
    }
};

class Jiang : public ChessPiece // 将
{
public:
    Jiang(const Point &point, bool color, FunnyChess &chessboard) : ChessPiece(point, color, chessboard) { this->Chesslevel = 7; }
    virtual bool CanMoveTo(const Point &point) const override
    {
        static const Point s[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 車可以到达的四个点
        if (board.GetChess(point) == nullptr || (board.GetChess(point)->cl != this->cl && this->Chesslevel >= board.GetChess(point)->Chesslevel && board.GetChess(point)->IfOverturn == 1))
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (point == Point(pt.x + s[i].x, pt.y + s[i].y))
                {
                    return true;
                }
            }
        }
        return false;
    }
    virtual const char *GetName() const override
    {
        return cl == BLACK ? "將" : "帥";
    }
};

class Shi : public ChessPiece // 士
{
public:
    Shi(const Point &point, bool color, FunnyChess &chessboard) : ChessPiece(point, color, chessboard) { this->Chesslevel = 6; }
    virtual bool CanMoveTo(const Point &point) const override
    {
        static const Point s[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 士可以到达的四个点
        if (board.GetChess(point) == nullptr || (board.GetChess(point)->cl != this->cl && this->Chesslevel >= board.GetChess(point)->Chesslevel && board.GetChess(point)->IfOverturn == 1))
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (point == Point(pt.x + s[i].x, pt.y + s[i].y))
                {
                    return true;
                }
            }
        }
        return false;
    }
    virtual const char *GetName() const override
    {
        return "士";
    }
};

class Ma : public ChessPiece // 马
{
public:
    Ma(const Point &point, bool color, FunnyChess &chessboard) : ChessPiece(point, color, chessboard) { this->Chesslevel = 4; }
    virtual bool CanMoveTo(const Point &point) const override
    {
        static const Point s[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 马可以到达的四个点
        if (board.GetChess(point) == nullptr || (board.GetChess(point)->cl != this->cl && this->Chesslevel >= board.GetChess(point)->Chesslevel && board.GetChess(point)->IfOverturn == 1))
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (point == Point(pt.x + s[i].x, pt.y + s[i].y))
                {
                    return true;
                }
            }
        }
        return false;
    }
    virtual const char *GetName() const override
    {
        return "马";
    }
};

class Bing : public ChessPiece // 兵
{
public:
    Bing(const Point &point, bool color, FunnyChess &chessboard) : ChessPiece(point, color, chessboard) { this->Chesslevel = 1; }
    virtual bool CanMoveTo(const Point &point) const override
    {
        static const Point s[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 马可以到达的四个点
        if (board.GetChess(point) == nullptr || (board.GetChess(point)->cl != this->cl && this->Chesslevel >= board.GetChess(point)->Chesslevel && board.GetChess(point)->IfOverturn == 1))
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (point == Point(pt.x + s[i].x, pt.y + s[i].y))
                {
                    return true;
                }
            }
        }
        return false;
    }
    virtual const char *GetName() const override
    {
        return cl == BLACK ? "卒" : "兵";
    }
};

class Pao : public ChessPiece // 炮
{
public:
    Pao(const Point &point, bool color, FunnyChess &chessboard) : ChessPiece(point, color, chessboard) { this->Chesslevel = 2; }
    virtual bool CanMoveTo(const Point &point) const override
    {
        static const Point s[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 炮不吃子可以到达的四个点
        if (board.GetChess(point) == nullptr)
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (point == Point(pt.x + s[i].x, pt.y + s[i].y))
                {
                    return true;
                }
            }
        }
        else if ((board.GetChess(point)->cl != this->cl && board.GetChess(point)->IfOverturn == 1) || board.GetChess(point)->IfOverturn == 0)
        {
            int count = 0;
            if (point.x == pt.x)
            {
                if (point.y < pt.y)
                {
                    for (int i = point.y + 1; i < pt.y; i++)
                    {
                        if (board.GetChess(Point(point.x, i)))
                            count++;
                    }
                }
                else
                {
                    for (int i = pt.y + 1; i < point.y; i++)
                    {
                        if (board.GetChess(Point(point.x, i)))
                            count++;
                    }
                }
            }
            else if (point.y == pt.y)
            {
                if (point.x < pt.x)
                {
                    for (int i = point.x + 1; i < pt.x; i++)
                    {
                        if (board.GetChess(Point(i, point.y)))
                            count++;
                    }
                }
                else
                {
                    for (int i = pt.x + 1; i < point.x; i++)
                    {
                        if (board.GetChess(Point(i, point.y)))
                            count++;
                    }
                }
            }
            if (count == 1)
                return true;
        }
        return false;
    }
    virtual const char *GetName() const override
    {
        return "炮";
    }
};

class ChessGame
{
private:
    bool nextPlayer;
    FunnyChess board;

public:
    ChessGame() : nextPlayer(RED) {}
    const FunnyChess &GetBoard() const
    {
        return board;
    }
    bool Move(const Point &a, const Point &b)
    {
        if (board.GetChess(a) && board.GetChess(a)->cl == nextPlayer)
        {
            if (board.GetChess(a)->MoveTo(b))
            {
                nextPlayer = !nextPlayer;
                return true;
            }
            return false;
        }
        return false;
    }
    bool GetNextPlayer() const
    {
        return nextPlayer;
    }
    int GetWinner() const
    {
        return 1;
    }
};
#endif // FUNNYCHESS_H
