#include "SinkProperty.h"
#include "../Mywidget.h"
SinkProperty::SinkProperty(MainWidget* pW) throw() : m_pW(pW)
{
}

void SinkProperty::OnPropertyChanged(const std::string& str)
{
    if( str == "move" )
    {
        m_pW->update();
    }
    if( str == "move_f" )
    {
        m_pW->update();
        //m_pW->show_win();
    }
    if(str == "red_win")
    {
        QMessageBox::information(NULL,"游戏结束","红方获胜！");
    }
    if(str == "black_win")
    {
        QMessageBox::information(NULL,"游戏结束","黑方获胜！");
    }
    if( str == "restart")
    {
        m_pW->update();
        //QMessageBox::information(NULL,"Sorry","You lose!");
    }
    if (str == "back")
    {
        m_pW->update();
    }
}
