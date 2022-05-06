#include <iostream>
#include <cstring>

using namespace std;

void print(const int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void print(int **arr, int n1, int n2) {
    for(int i=0;i<n1;++i)
        print(arr[i],n2);
}

int main() // &aaa, aaa (128)
{
    const int n1 = 2;
    const int n2 = 3;
    int **aaa = new int*[n1];
    for (int i = 0; i < n1; ++i)
        aaa[i] = new int[n2];
    aaa[0][0] = 1;
    aaa[0][1] = 4;
    aaa[0][2] = 6;
    aaa[1][0] = 8;
    aaa[1][1] = 10;
    aaa[1][2] = 11;
    print(aaa,n1,n2);
    for (int i=0;i<n1;++i) delete[] aaa[i];
    delete[] aaa;
    return 0;
}
