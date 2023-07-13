#ifndef SINKPROPERTY_H
#define SINKPROPERTY_H

#include "../../common/etlbase.h"

class MyWidget;

class SinkProperty : public IPropertyNotification
{
public:
    SinkProperty(MyWidget* pW) throw();

    virtual void OnPropertyChanged(const std::string& str);

private:
    MyWidget* m_pW;
};

#endif // MAINWINDOWPROPERTYSINK_H
