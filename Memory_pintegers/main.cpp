#include <iostream>

using namespace std;

int main() // &d
{

    int a = 3;
    int *b = &a;
    int c = 5;
    int &d = c;

    cout << a << ", " << b << ", " << c << ", " << d << endl; // 3, 0x61fe0c, 5, 5

    return 0;
}
