#ifndef SINKPROPERTY_H
#define SINKPROPERTY_H

#include "../../common/etlbase.h"

class MainWidget;

class SinkProperty : public IPropertyNotification
{
public:
    SinkProperty(MainWidget* pW) throw();

    virtual void OnPropertyChanged(const std::string& str);

private:
    MainWidget* m_pW;
};

#endif // MAINWINDOWPROPERTYSINK_H
