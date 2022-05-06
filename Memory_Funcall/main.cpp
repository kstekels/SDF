#include <iostream>
#include <cstring>
using namespace std;

int add(const int a, const int b) {
    int c = a + b;
    return c;
}

int main()
{
    int x=3;
    int y=4;
    int z = add(x,y);
    cout<<z<<endl;
    return 0;
}
