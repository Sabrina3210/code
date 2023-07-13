#ifndef BOARD_H
#define BOARD_H
#include<QString>
class Stone{
public:
    Stone();
    ~Stone();
    enum TYPE{CHE, MA, PAO, BING, JIANG, SHI, XIANG};
    void init(int id);
    int _row;
    int _col;
    TYPE _type;
    bool _dead;
    bool _red;
    int _id;
    QString name();

};
class Board{
public:
    Board();
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    ~Board()noexcept;
    void init();
    Stone* getstone();
    int select_id;
private:
    Stone chess[32];
};

#endif
