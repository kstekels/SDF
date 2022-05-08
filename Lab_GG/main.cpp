#include <iostream>
#include "lab_G14.h"

using namespace std;

int main()
{
    // Allocate Head and Tail for Odd and Even Doubly linked lists
    Node *firstOdd = NULL;
    Node *lastOdd;
    Node *firstEven = NULL;
    Node *lastEven;

    // User input array size and numbers to operate with
    int sizeOfArray = 0;
    cout << "Size of array: ";
    while(!(cin>>sizeOfArray))
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    int numbers[sizeOfArray];
    cout << "Enter Numbers: ";
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> numbers[i];
    }
    cout << endl;

    // Print the user Input
    cout << "List of given Numbers: ";
    for (auto num: numbers)
        cout << num << " ";
    cout << endl;

    // Create a Odd and Even linked list from input
    printOdd(numbers, sizeOfArray, firstOdd, lastOdd);
    printEven(numbers, sizeOfArray, firstEven, lastEven);

    // Free the allocated memory for linked list
    rem(firstOdd);
    rem(firstEven);

    return 0;
}
