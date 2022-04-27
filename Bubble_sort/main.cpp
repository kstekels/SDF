#include<iostream>
using namespace std;

void print(int array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i)
        cout << array[i] << " ";
    cout << endl;
}

void bubble_sort(int array[], int sizeOfArray)
{
    for (int i=0; i<sizeOfArray-1; ++i)
    {
        for (int k=0; k<sizeOfArray-i-1; ++k)
        {
            if (array[k] > array[k+1]) {
                int temporary = array[k];
                array[k] = array[k+1];
                array[k+1] = temporary;
            }
        }
    }
}

int main()
{
    int arrayOfNumbers[6]={1,8,4,6,5,7};
    print(arrayOfNumbers, 6);
    bubble_sort(arrayOfNumbers, 6);
    print(arrayOfNumbers, 6);
    return 0;
}
