#include "SinkProperty.h"
#include "../Mywidget.h"
SinkProperty::SinkProperty(MainWidget* pW) throw() : m_pW(pW)
{
}

void SinkProperty::OnPropertyChanged(const std::string& str)
{
//    if( str == "move" )
//    {
//        m_pW->update();
//    }
////    if( str == "win" )
////    {
////        m_pW->update();
////        //m_pW->show_win();
////    }
////    if( str == "lose")
////    {
////        m_pW->update();
////        //QMessageBox::information(NULL,"Sorry","You lose!");
////    }
////    if (str == "restart_block")
////    {
//////        m_pW->paint_flag=0;
//////        m_pW->init();
//////        m_pW->time_init();
////        m_pW->update();
////    }
}
