// G14 STL list
// ks21180, Kārlis Štekels
#include <iostream>
#include <list>

using namespace std;

// Print given list values
void printList(list<int>& listOfNumbers, string type)
{
    cout << type << " numbers: ";
    for (auto num: listOfNumbers)
        cout << num << " ";
    cout << endl;
}

// Get all Odd numbers from given list of numbers
void getOdd(int sizeOfArr, int arr[], list<int>& odd)
{
    for (int i = 0; i < sizeOfArr; i++) // Iterate through all elements in given list
    {
        if (arr[i] % 2 != 0) // if remainder is not 0, then add new element to end of new list
            odd.push_back(arr[i]); // Add element to end of the list
    }
}

// Get all Even numbers from given list of numbers
void getEven(int sizeOfArr, int arr[], list<int>& even)
{
    for (int i = 0; i < sizeOfArr; i++) // Iterate through all elements in given list
    {
        if (arr[i] % 2 == 0) // if remainder is 0, then add new element to end of new list
            even.push_back(arr[i]); // Add element to end of the list
    }
}

int main()
{

    int sizeOfArray; // Create a new integer variable which hold array size
    cout << "Enter a size of array: "; // Console message to user ask to input the size of array
    cin >> sizeOfArray; // Store user input in variable

    int numbers[sizeOfArray]; // Create a new integer array, which has specified size from user input
    cout << "Enter a sequence of numbers: "; // Console message to user ask to input the numbers
    for (int i = 0; i < sizeOfArray; i++) { // iterate through array
        cin >> numbers[i]; // Add all user numbers to array
    }
    cout << endl;

    // Print user initial input
    cout << "Given array of numbers: ";
    for (auto n: numbers)
        cout << n << " ";
    cout << endl;

    list<int> oddNumbers={}; // Create a new empty list for odd numbers
    list<int> evenNumbers={}; // Create a new empty list for even numbers

    getOdd(sizeOfArray, numbers, oddNumbers); // Get all odd numbers and store them to new list
    getEven(sizeOfArray, numbers, evenNumbers); // Get all even numbers and store them to new list

    printList(oddNumbers, "Odd"); // Print all odd numbers to console
    printList(evenNumbers, "Even"); // Print all even numbers to console



    return 0;
}
