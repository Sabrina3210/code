#include "my_vmsink.h"
//#include "model/my_model.h"
#include"..//my_vm.h"
ViewModelSink::ViewModelSink(my_vm* p) throw():m_pVM(p)
{
}

void ViewModelSink::OnPropertyChanged(const std::string &str)
{
    m_pVM->Fire_OnPropertyChanged(str);
}
