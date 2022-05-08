#include "formula.h"

int dv(int a, int b)
{
    if (b == 0) throw -99;
    return a/b;
}
int formula(int a, int b)
{
    return dv(10,a+dv(5,b));
}
