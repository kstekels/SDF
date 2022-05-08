#include <iostream>
#include "formula.h"
using namespace std;

int main()
{
    int a=1, b=5;
    try {
        cout << formula(a, b) << endl;
    } catch(int e) {
        cout << "Error #" << e << endl;
    }
}
