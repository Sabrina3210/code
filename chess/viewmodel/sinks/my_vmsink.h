#ifndef MY_VMSINK_H
#define MY_VMSINK_H
#include "../../common/etlbase.h"
class my_vm;

class ViewModelSink : public IPropertyNotification
{
public:
    ViewModelSink(my_vm* p) throw();
    virtual void OnPropertyChanged(const std::string &str);
private:
    my_vm* m_pVM;
};
#endif
