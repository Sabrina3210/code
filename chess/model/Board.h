#ifndef BOARD_H
#define BOARD_H
#include"Stone.h"
#include"../common/etlbase.h"
class Board:public Proxy_PropertyNotification<Board>{
public:
    Board();
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    ~Board()noexcept;
    //std::shared_ptr<PcCfg> GetCfg() noexcept;
    Stone* getstone();
    int select_id;
private:
    Stone chess[32];
    //std::shared_ptr<Stone> b;
};

#endif
