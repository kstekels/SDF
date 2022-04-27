#include<iostream>
using namespace std;

void print(int array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i)
        cout << array[i] << " ";
    cout << endl;
}

int find_sorted(int array[], int sizeOfArray, int value)
{
    int left=0;
    int right=sizeOfArray-1;
    while (left<=right)
    {
        int mid = (left+right)/2;
        if (array[mid]==value)
        {
            return mid;
        }
        else if (value < array[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arrayOfNumbers[6]={1,4,5,6,7,8};
    print(arrayOfNumbers, 6);
    cout << find_sorted(arrayOfNumbers, 6, 8) << endl;
    return 0;
}
