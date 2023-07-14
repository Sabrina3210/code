#include "parameter.h"

DesParameter::DesParameter(int a, int b, int c)
{
    this->row = a;
    this->col = b;
    this->select_id = c;
}
DesParameter& DesParameter::operator=(const DesParameter& src)
{
    if( this != &src ) {
        row = src.row;
        col = src.col;
        select_id = src.select_id;
    }
    return *this;
}

DesParameter& DesParameter::operator=(DesParameter&& src)
{
    if( this != &src ) {
        row = src.row;
        col = src.col;
        select_id = src.select_id;
    }
    return *this;
}
DesParameter::DesParameter() throw(){

}
DesParameter::DesParameter(const DesParameter& src):row(src.row), col(src.col), select_id(src.select_id)
{
}
DesParameter::DesParameter(DesParameter&& src){
    row = static_cast<int&&>(src.row);
    col = static_cast<int&&>(src.col);
    select_id = static_cast<int&&>(src.select_id);
}
