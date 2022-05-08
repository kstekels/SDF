#include<iostream>
#include "../Formula/formula.h"
using namespace std;

bool test_A()
{
    return formula(1,5) == 5;
}

bool test_B()
{
    return formula(0,1) == 2;
}

bool test_C()
{
    try
    {
        formula(1,0);
    }
    catch (int e){
        if (e == -99) return true;
        else return false;
    }
}

bool test_D()
{
    try
    {
        formula(5,-1);
    }
    catch (int e){
        if (e == -99) return true;
        else return false;
    }
}

bool test_E()
{
    return formula(1,2) == 3;
}

int main()
{
    cout << test_A() << endl;
    cout << test_B() << endl;
    cout << test_C() << endl;
    cout << test_D() << endl;
    cout << test_E() << endl;
}
