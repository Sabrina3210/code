#ifndef MY_MODEL_H
#define MY_MODEL_H
#include"../common/etlbase.h"
#include"../common/Board.h"
#include"../common/F_Board.h"

class MyModel : public Proxy_CommandNotification<MyModel>, public Proxy_PropertyNotification<MyModel>
{
public:
    MyModel();
    std::shared_ptr<Board> get_board() throw();
    std::shared_ptr<F_Board> get_FBoard() throw();
    //provide interface of functions
    bool movechess(int ed_x,int ed_y, int select_id);
    bool flipoverchess(int select_id);
    bool movechess_f(int ed_x,int ed_y, int select_id);
    bool restart();
    bool RecoverLastStep();
    //    bool restart(int row, int col, int boom_num);
    //    bool leftblock(int x_pos, int y_pos);
    //    bool rightblock(int x_pos, int y_pos);
private:
    std::shared_ptr<Board> b;
    std::vector<step_record> record;
    std::shared_ptr<F_Board> f;

    bool CanMoveJiang(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    bool CanMoveShi(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    bool CanMoveXiang(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    bool CanMoveMa(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    bool CanMoveChe(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    bool CanMovePao(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    bool CanMoveBing(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);

    int JudgeWin();
    int StoneInPos(int pos_x, int pos_y);
    int NumChessPassBy(int st_x, int st_y, int ed_x, int ed_y);
    int PosChange(int st_x, int st_y, int ed_x, int ed_y);
    bool IfPosInBoard(int pos_x, int pos_y);
    bool IfPosInSudoku(int pos_x, int pos_y, bool IsRed);
    bool IfPosInOwnCamp(int pos_x, int pos_y, bool IsRed);


    bool F_Can_Move_Pao(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    bool F_Can_Move_Chess(int st_x, int st_y, int ed_x, int ed_y, bool IsRed);
    int F_StoneInPos(int pos_x, int pos_y);
    int F_NumChessPassBy(int st_x, int st_y, int ed_x, int ed_y);
    int F_PosChange(int st_x, int st_y, int ed_x, int ed_y);
    bool F_IfPosInBoard(int pos_x, int pos_y);
};

#endif // MSDATAMODEL_H
