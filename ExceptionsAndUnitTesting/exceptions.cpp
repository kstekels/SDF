
#include <iostream>
using namespace std;

int dv(int a, int b)
{
    if (b == 0) throw -99;
    return a/b;
}
int formula(int a, int b)
{
    return dv(10,(a+dv(5,b)));
}

int main()
{
    int a = 1, b = 0;
    try{
        cout << formula(a, b) << endl;
    }
    catch(const char *e) {
        cout << e << endl;
    }
    catch(int e) {
        cout << "Error: " << e << endl;
    }
    catch(...) {
        cout << "Undefined Error" << endl;
    }

}

