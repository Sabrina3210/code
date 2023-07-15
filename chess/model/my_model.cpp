#include"my_model.h"
#include <iostream>

MyModel::MyModel()
{
    b=std::make_shared<Board>();
    //b=source;
    f=std::make_shared<F_Board>();
}
std::shared_ptr<Board> MyModel::get_board()throw()
{
    return b;
}
std::shared_ptr<F_Board> MyModel::get_FBoard()throw()
{
    return f;
}
bool MyModel::movechess(int ed_x,int ed_y, int select_id)
{
    //function
    Stone &now_stone = b->getstone()[select_id];
    int st_x = now_stone._row;
    int st_y = now_stone._col;
    int now_type = now_stone._type;
    bool IsRed = now_stone._red;
    bool &now_camp_red = b->now_camp_is_red;
    if(IsRed != now_camp_red)
        return false;
    int end_index = StoneInPos(ed_x, ed_y);
    Stone &end_stone = b->getstone()[end_index];
    bool flag = false;

    step_record new_record;
    new_record.camp = now_camp_red;
    new_record.start_id = select_id;
    new_record.end_id = end_index;
    new_record.st_x = st_x;
    new_record.st_y = st_y;
    new_record.ed_x = ed_x;
    new_record.ed_y = ed_y;
    record.push_back(new_record);

    switch (now_type)
    {

    case 0:// che
        if(CanMoveChe(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                flag = true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    flag = true;
                }
            }
        }
        break;

    case 1:// ma
        if(CanMoveMa(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                flag = true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    flag = true;
                }
            }
        }
        break;

    case 2:// pao
        if(CanMovePao(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                if(NumChessPassBy(st_x, st_y, ed_x, ed_y) == 1)
                {
                    return false;
                }
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                flag = true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    if(NumChessPassBy(st_x, st_y, ed_x, ed_y) == 0)
                    {
                        return false;
                    }
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    flag = true;
                }
            }
        }
        break;

    case 3:// bing
        if(CanMoveBing(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                flag = true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    flag = true;
                }
            }
        }
        break;

    case 4:// jiang
        if(CanMoveJiang(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                flag = true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    flag = true;
                }
            }
        }
        break;

    case 5:// shi
        if(CanMoveShi(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                flag = true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    flag = true;
                }
            }
        }
        break;

    case 6:// xiang
        if(CanMoveXiang(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                flag = true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    flag = true;
                }
            }
        }
        break;

    default:
        break;
    }
    if(flag)
    {
        std::string str="move";
        Fire_OnPropertyChanged( str);
        now_camp_red = !now_camp_red;
        int j = JudgeWin();
        if(j == 1)
        {
            std::string win_str="red_win";
            Fire_OnPropertyChanged(win_str);

        }
        else if(j == -1)
        {
            std::string win_str="black_win";
            Fire_OnPropertyChanged(win_str);
        }
        else
        {

        }
//        int i = record.size() - 1;
//        std::cout << record[i].camp << " " << record[i].start_id << " " << record[i].st_x << " " << record[i].st_y << " " << record[i].end_id << " " << record[i].ed_x << " " << record[i].ed_y << " " << std::endl;
        return true;
    }
    else
    {
        record.pop_back();
        return false;
    }
}
bool MyModel::flipoverchess(int select_id)
{
    if(f->cover[select_id])
    {
        return false;
    }
    else
    {
        f->cover[select_id]=true;
        std::string flip_str="fliped";
        Fire_OnPropertyChanged(flip_str);
        return true;
    }
}
int MyModel::JudgeWin()
{
    for(int i = 0; i < 32; i++)
    {
        Stone st = b->getstone()[i];
        if(st._dead && st._type == Stone::JIANG)
        {
            if(!st._red)
            {
                //std::cout << "red_win" << std::endl;
                return 1;
            }
            else
            {
                //std::cout << "black_win" << std::endl;
                return -1;
            }
        }
    }
    return 0;
}

int MyModel::StoneInPos(int pos_x, int pos_y)
{
    // 返回当前坐标位置的棋子下标，没有返回-1
    for(int i = 0; i < 32; i++)
    {
        Stone tmp = b->getstone()[i];
        if(!tmp._dead && tmp._row == pos_x && tmp._col == pos_y)
            return i;
    }
    return -1;
}

int MyModel::NumChessPassBy(int st_x, int st_y, int ed_x, int ed_y)
{
    int del = PosChange(st_x, st_y, ed_x, ed_y);
    int count = 0;
    if(del / 10 == 0)
    {
        // 找y轴经过的棋子
        for(int i = 0; i < 32; i++)
        {
            Stone tmp = b->getstone()[i];
            if(!tmp._dead && tmp._row == st_x && ((tmp._col > st_y && tmp._col < ed_y) || (tmp._col > ed_y && tmp._col < st_y)))
            {
                count++;
            }
        }
    }
    else if(del % 10 == 0)
    {
        // 找x轴经过的棋子
        for(int i = 0; i < 32; i++)
        {
            Stone tmp = b->getstone()[i];
            if(!tmp._dead && tmp._col == st_y && ((tmp._row > st_x && tmp._row < ed_x) || (tmp._row > ed_x && tmp._row < st_x)))
            {
                count++;
            }
        }
    }
    else
    {

    }
    return count;
}

int MyModel::PosChange(int st_x, int st_y, int ed_x, int ed_y)
{
    return abs(ed_x - st_x) * 10 + abs(ed_y - st_y);
}

bool MyModel::IfPosInBoard(int pos_x, int pos_y)
{
    if(pos_x >= 1 && pos_x <= 9 && pos_y >= 1 && pos_y <=10)
        return true;
    else
        return false;
}

bool MyModel::IfPosInSudoku(int pos_x, int pos_y, bool IsRed)
{
    if(IsRed)
    {
        if(pos_x >= 4 && pos_x <= 6 && pos_y >= 8 && pos_y <=10)
            return true;
        else
            return false;
    }
    else
    {
        if(pos_x >= 4 && pos_x <= 6 && pos_y >= 1 && pos_y <=3)
            return true;
        else
            return false;
    }
}

bool MyModel::IfPosInOwnCamp(int pos_x, int pos_y, bool IsRed)
{
    if(IsRed)
    {
        if(pos_y >= 6 && pos_y <= 10)
            return true;
        else
            return false;
    }
    else
    {
        if(pos_y >= 1 && pos_y <= 5)
            return true;
        else
            return false;
    }
}

bool MyModel::CanMoveJiang(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!IfPosInBoard(ed_x, ed_y))
        return false;
    if(PosChange(st_x, st_y, ed_x, ed_y) / 10 == 0)
    {
        if(NumChessPassBy(st_x, st_y, ed_x, ed_y) == 0)
        {
            int index = StoneInPos(ed_x, ed_y);
            Stone st = b->getstone()[index];
            if(!st._dead && st._type == 4 && st._red == !IsRed)
                return true;
        }
    }
    if(IfPosInSudoku(ed_x, ed_y, IsRed))
    {
        if(PosChange(st_x, st_y, ed_x, ed_y) == 1 || PosChange(st_x, st_y, ed_x, ed_y) == 10)
            return true;
    }
    return false;
}

bool MyModel::CanMoveShi(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!IfPosInBoard(ed_x, ed_y))
        return false;
    if(IfPosInSudoku(ed_x, ed_y, IsRed))
    {
        if(PosChange(st_x, st_y, ed_x, ed_y) == 11)
            return true;
    }
    return false;
}

bool MyModel::CanMoveXiang(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!IfPosInBoard(ed_x, ed_y))
        return false;
    if(IfPosInOwnCamp(ed_x, ed_y, IsRed))
    {
        if(PosChange(st_x, st_y, ed_x, ed_y) == 22)
        {
            if(StoneInPos((st_x + ed_x) / 2, (st_y + ed_y) / 2 ) >= 0)
            {
                return false;
            }
            return true;
        }
    }
    return false;
}

bool MyModel::CanMoveMa(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!IfPosInBoard(ed_x, ed_y))
        return false;
    int pc = PosChange(st_x, st_y, ed_x, ed_y);
    if(pc == 21 || pc == 12)
    {
        if(pc == 21)
        {
            if(StoneInPos((st_x + ed_x) / 2, st_y) >= 0)
            {
                return false;
            }
        }
        if(pc == 12)
        {
            if(StoneInPos(st_x, (st_y + ed_y) / 2) >= 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool MyModel::CanMoveChe(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!IfPosInBoard(ed_x, ed_y))
        return false;
    if(PosChange(st_x, st_y, ed_x, ed_y) / 10 == 0 || PosChange(st_x, st_y, ed_x, ed_y) % 10 == 0)
    {
        if(NumChessPassBy(st_x, st_y, ed_x, ed_y) == 0)
            return true;
    }
    return false;
}

bool MyModel::CanMovePao(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!IfPosInBoard(ed_x, ed_y))
        return false;
    if(PosChange(st_x, st_y, ed_x, ed_y) / 10 == 0 || PosChange(st_x, st_y, ed_x, ed_y) % 10 == 0)
    {
        if(NumChessPassBy(st_x, st_y, ed_x, ed_y) == 0 || NumChessPassBy(st_x, st_y, ed_x, ed_y) == 1)
            return true;
    }
    return false;
}

bool MyModel::CanMoveBing(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!IfPosInBoard(ed_x, ed_y))
        return false;
    if(IfPosInOwnCamp(st_x, st_y, IsRed))
    {
        if(IsRed)
        {
            if(ed_y - st_y == -1 && ed_x == st_x)
                return true;
        }
        else
        {
            if(ed_y - st_y == 1 && ed_x == st_x)
                return true;
        }
    }
    else
    {
        int del = PosChange(st_x, st_y, ed_x, ed_y);
        if(IsRed)
        {
            if((ed_y - st_y == -1 && ed_x == st_x) || del == 10)
                return true;
        }
        else
        {
            if((ed_y - st_y == 1 && ed_x == st_x) || del == 10)
                return true;
        }
    }
    return false;
}

bool MyModel::RecoverLastStep()
{
    //std::cout << 0;
    if(record.size() == 0)
        return false;
    step_record last_step = record[record.size() - 1];
    record.pop_back();
    b->now_camp_is_red = last_step.camp;
    if(last_step.start_id >= 0)
    {
        //std::cout << 1;
        Stone &st_stone = b->getstone()[last_step.start_id];
        st_stone._row = last_step.st_x;
        st_stone._col = last_step.st_y;
    }
    if(last_step.end_id >= 0)
    {
        //std::cout << 5;
        Stone &ed_stone = b->getstone()[last_step.end_id];
        ed_stone._dead = false;
        ed_stone._row = last_step.ed_x;
        ed_stone._col = last_step.ed_y;
    }
    std::string back_str="back";
    Fire_OnPropertyChanged(back_str);
    return true;
}

bool MyModel::movechess_f(int ed_x,int ed_y, int select_id)
{
    //function
    bool &now_camp_red = b->now_camp_is_red;
    F_Stone &now_stone = f->getstone()[select_id];
    int st_x = now_stone._row;
    int st_y = now_stone._col;
    int now_type = now_stone._type;
    bool IsRed = now_stone._red;
    if(IsRed != now_camp_red)
        return false;
    int end_index = F_StoneInPos(ed_x, ed_y);  //返回当前坐标棋子的下标，没有返回-1
    F_Stone &end_stone = f->getstone()[end_index];

    switch (now_type)
    {

    case 0:// che
        if(F_Can_Move_Chess(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                std::string str="move_f";
                Fire_OnPropertyChanged( str);
                now_camp_red = !now_camp_red;
                return true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    std::string str="move_f";
                    Fire_OnPropertyChanged( str);
                    now_camp_red = !now_camp_red;
                    return true;
                }
            }
        }
        break;

    case 1:// ma
        if(F_Can_Move_Chess(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                std::string str="move_f";
                Fire_OnPropertyChanged( str);
                now_camp_red = !now_camp_red;
                return true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    std::string str="move_f";
                    Fire_OnPropertyChanged( str);
                    now_camp_red = !now_camp_red;
                    return true;
                }
            }
        }
        break;

    case 2:// pao
        if(F_Can_Move_Pao(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                if(F_NumChessPassBy(st_x, st_y, ed_x, ed_y) == 1)
                {
                    return false;
                }
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                std::string str="move_f";
                Fire_OnPropertyChanged( str);
                now_camp_red = !now_camp_red;
                return true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    if(F_NumChessPassBy(st_x, st_y, ed_x, ed_y) == 0)
                    {
                        return false;
                    }
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    std::string str="move_f";
                    Fire_OnPropertyChanged( str);
                    now_camp_red = !now_camp_red;
                    return true;
                }
            }
        }
        break;

    case 3:// bing
        if(F_Can_Move_Chess(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                std::string str="move_f";
                Fire_OnPropertyChanged( str);
                now_camp_red = !now_camp_red;
                return true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    std::string str="move_f";
                    Fire_OnPropertyChanged( str);
                    now_camp_red = !now_camp_red;
                    return true;
                }
            }
        }
        break;

    case 4:// jiang
        if(F_Can_Move_Chess(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                std::string str="move_f";
                Fire_OnPropertyChanged( str);
                now_camp_red = !now_camp_red;
                return true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    std::string str="move_f";
                    Fire_OnPropertyChanged( str);
                    now_camp_red = !now_camp_red;
                    return true;
                }
            }
        }
        break;

    case 5:// shi
        if(F_Can_Move_Chess(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                std::string str="move_f";
                Fire_OnPropertyChanged( str);
                now_camp_red = !now_camp_red;
                return true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    std::string str="move_f";
                    Fire_OnPropertyChanged( str);
                    now_camp_red = !now_camp_red;
                    return true;
                }
            }
        }
        break;

    case 6:// xiang
        if(F_Can_Move_Chess(st_x, st_y, ed_x, ed_y, IsRed))
        {
            if(end_index < 0)
            {
                now_stone._row = ed_x;
                now_stone._col = ed_y;
                std::string str="move_f";
                Fire_OnPropertyChanged( str);
                now_camp_red = !now_camp_red;
                return true;
            }
            else
            {
                if(IsRed == end_stone._red)
                {
                    return false;
                }
                else
                {
                    now_stone._row = ed_x;
                    now_stone._col = ed_y;
                    end_stone._row = -1;
                    end_stone._col = -1;
                    end_stone._dead = true;
                    std::string str="move_f";
                    Fire_OnPropertyChanged( str);
                    now_camp_red = !now_camp_red;
                    return true;
                }
            }
        }
        break;

    default:
        break;
    }
    return false;
}
bool MyModel::restart()
{
    b->init();
    record.clear();
    std::string str="restart";
    Fire_OnPropertyChanged( str);
    return true;
}
int MyModel::F_StoneInPos(int pos_x, int pos_y)
{
    // 返回当前坐标位置的棋子下标，没有返回-1
    for(int i = 0; i < 32; i++)
    {
        F_Stone tmp = f->getstone()[i];
        if(!tmp._dead && tmp._row == pos_x && tmp._col == pos_y)
            return i;
    }
    return -1;
}

int MyModel::F_NumChessPassBy(int st_x, int st_y, int ed_x, int ed_y)
{
    int del = F_PosChange(st_x, st_y, ed_x, ed_y);
    int count = 0;
    if(del / 10 == 0)
    {
        // 找y轴经过的棋子
        for(int i = 0; i < 32; i++)
        {
            F_Stone tmp = f->getstone()[i];
            if(!tmp._dead && tmp._row == st_x && ((tmp._col > st_y && tmp._col < ed_y) || (tmp._col > ed_y && tmp._col < st_y)))
            {
                count++;
            }
        }
    }
    else if(del % 10 == 0)
    {
        // 找x轴经过的棋子
        for(int i = 0; i < 32; i++)
        {
            F_Stone tmp = f->getstone()[i];
            if(!tmp._dead && tmp._col == st_y && ((tmp._row > st_x && tmp._row < ed_x) || (tmp._row > ed_x && tmp._row < st_x)))
            {
                count++;
            }
        }
    }
    else
    {

    }
    return count;
}

int MyModel::F_PosChange(int st_x, int st_y, int ed_x, int ed_y)
{
    return abs(ed_x - st_x) * 10 + abs(ed_y - st_y);
}

bool MyModel::F_IfPosInBoard(int pos_x, int pos_y)
{
    if(pos_x >= 1 && pos_x <= 8 && pos_y >= 1 && pos_y <=4)
        return true;
    else
        return false;
}

bool MyModel::F_Can_Move_Pao(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!F_IfPosInBoard(ed_x, ed_y))
        return false;
    if(st_x == ed_x || st_y == ed_y){
        return true;
    }
    return false;
}

bool MyModel::F_Can_Move_Chess(int st_x, int st_y, int ed_x, int ed_y, bool IsRed)
{
    if(!F_IfPosInBoard(ed_x, ed_y))
        return false;
    int start_index = F_StoneInPos(st_x, st_y);
    F_Stone &start_stone = f->getstone()[start_index];
    int end_index = F_StoneInPos(ed_x, ed_y);
    F_Stone &end_stone = f->getstone()[end_index];
    if(st_x == ed_x){
        if(abs(st_y-ed_y) == 1 ){
            if(start_stone._level == 1){
                if(end_stone._level == 7 || end_stone._level == 1) return true;
            }else if(end_stone._level <= start_stone._level){
                return true;
            }
            return false;
        }
    }else if(st_y == ed_y){
        if(abs(st_x-ed_x) == 1 ){
            if(start_stone._level == 1){
                if(end_stone._level == 7 || end_stone._level == 1) return true;
            }else if(end_stone._level <= start_stone._level){
                return true;
            }
            return false;
        }
    }
    return false;
}
