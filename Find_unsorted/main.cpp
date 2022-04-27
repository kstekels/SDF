#include<iostream>
using namespace std;

void print(int array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i)
        cout << array[i] << " ";
    cout << endl;
}

int find_unsorted(int array[], int sizeOfArray, int value)
{
    for (int i =0; i < sizeOfArray; ++i)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

int main()
{
    int arrayOfNumbers[6] = {1,8,4,6,5,7};
    print(arrayOfNumbers, 6);
    cout << find_unsorted(arrayOfNumbers, 6, 5) << endl;
    return 0;
}
