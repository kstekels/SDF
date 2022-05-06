#include <iostream>
#include <cstring>

using namespace std;

void print(const int arr[], int n)
{
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    const int n = 3;
    int *aa = new int[n];
    aa[0] = 2;
    aa[1] = 4;
    aa[2] = 6;
    print(aa, n);
    delete[] aa;

    return 0;
}
