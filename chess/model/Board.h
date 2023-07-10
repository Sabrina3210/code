#ifndef BOARD_H
#define BOARD_H
#include"Stone.h"
class Board{
public:
    Board();
    ~Board();
    Stone* getstone();
private:
    Stone chess[32];
};

#endif
