#ifndef F_BOARD_H
#define F_BOARD_H
#include<QString>
#include"../common/step.h"
class F_Stone{
public:
    F_Stone();
    ~F_Stone();
    enum TYPE{CHE, MA, PAO, BING, JIANG, SHI, XIANG};
    void init(int id);
    int _row;
    int _col;
    TYPE _type;
    bool _dead;
    bool _red;
    int _id;
    int _level;
    QString name();

};
class F_Board{
public:
    F_Board();
    ~F_Board();
    bool now_camp_red;
    void init();
    F_Stone* getstone();
    bool cover[32];
private:
    F_Stone chess[32];
};

#endif
