#ifndef PARAMETER_H
#define PARAMETER_H


class DesParameter
{
public:
    DesParameter()throw();
    DesParameter(const DesParameter& src);
    DesParameter(DesParameter&& src);

    DesParameter(int a, int b, int c);
    DesParameter& operator=(const DesParameter& src);
    DesParameter& operator=(DesParameter&& src);
public:
    int row;
    int col;
    int select_id;
};

#endif // PARAMETER_H
