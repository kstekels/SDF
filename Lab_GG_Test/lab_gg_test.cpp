// ks21180, Karlis Stekels
#include <iostream>
#include "../Lab_GG/lab_G14.h"
using namespace std;


// Helper function to create a test linked list
Node* createTestNode(int numbers[], int sizeOfnumbers) // takes number array and its size as an  argument
{

    Node* head = NULL; // Create node pointer for linked list head
    Node* tail = NULL; // Create node pointer for linked list tail
    for (int i = 0; i <= sizeOfnumbers; ++i) // The for loop will iterate from 0 to size of given array
    {
        Node* node = new Node(); // New node pointer instance
        if (!head) // if head is Null, then create first linked list element where head and tail is the same node
        {
            node->value = numbers[i]; // first element value
            node->next = nullptr; // node next element is null
            head = node; // node is head
            tail = node; // tail is also head
        } else { // if node is not empty, then:
            node->value = numbers[i]; // assign node value to new number
            node->next = nullptr; // node next element is null
            tail->next = node; // tail next element becoms new node
            tail = node; // new node becomes a tail
        }
    }
    return head; // return a node head pointer
}

// Helper function to count all values in both linked list
int compareLinkedListValues(Node*& first, Node*& second, int possibleCoincidences) // takes two node pointers and possible coincidence number
{
    int counter = 0; // create a counter variable
    for (int i = 0; i < possibleCoincidences; ++i) // loop will iterate max coincidence times
    {
        if (first->value == second->value) // if desired and checking linked list value will match, then it will count matches
        {
            ++counter; // counter increment
            first = first->next; // move first node pointer to next value
            second = second->next; // move second node pointer to next value
        } else {
            return 0; // if mismatch, then it will return 0 and stop the for loop
        }
    }
    return counter;
}

// Helper function to print a Array
void printArray(int arr[], int sizeOfArr, string name) // Takes array and its size as arguments
{
    cout << name << ": "; // Prefix string for array
    for (int i = 0; i < sizeOfArr; ++i) // iterate trought array
        cout << arr[i] << " "; // print in console all numbers
    cout << endl; // end row line in terminal
}

bool checkOutputOdd(int testArr[], int sizeOfTestArr, int desiredArr[], int sizeOfDesiredArr) // Function to check odd output
{
    printArray(testArr, sizeOfTestArr, "Given input"); // Print input numbers for checking

    Node *firstOdd = NULL; // create an empty Node pointer for head to test printOdd function (required)
    Node *lastOdd; // create an empty Node pointer for tail to test printOdd function (required)
    printArray(desiredArr, sizeOfDesiredArr, "Desired output"); // Print desired output for given numbers
    Node* testNumbers = printOdd(testArr, sizeOfTestArr, firstOdd, lastOdd); // save returned value from function to testNumbers pointer Node
    Node* testNode = createTestNode(desiredArr, sizeOfDesiredArr); // Create a test node for desired response to compare with function response
    int coincidences = compareLinkedListValues(testNumbers, testNode, sizeOfDesiredArr); // Use helper function to compare desired linked list with result linked list
    rem(testNumbers); // Delete testNumbers linked list
    rem(testNode);  // Delete testNode linked list
    if (coincidences == sizeOfDesiredArr) // If coincidences is equal of size of desired numbers count, then return true or 1, otherwise, will return false or 0
        return 1;
    else
        return 0;
}

bool checkOutputEven(int testArr[], int sizeOfTestArr, int desiredArr[], int sizeOfDesiredArr) // Function to check even output
{
    printArray(testArr, sizeOfTestArr, "Given input"); // Print input numbers for checking
    Node *firstOdd = NULL; // create an empty Node pointer for head to test printOdd function (required)
    Node *lastOdd; // create an empty Node pointer for tail to test printOdd function (required)
    printArray(desiredArr, sizeOfDesiredArr, "Desired output"); // Print desired output for given numbers
    Node* testNumbers = printEven(testArr, sizeOfTestArr, firstOdd, lastOdd); // save returned value from function to testNumbers pointer Node
    Node* testNode = createTestNode(desiredArr, sizeOfDesiredArr); // Create a test node for desired response to compare with function response
    int coincidences = compareLinkedListValues(testNumbers, testNode, sizeOfDesiredArr); // Use helper function to compare desired linked list with result linked list
    rem(testNumbers); // Delete testNumbers linked list
    rem(testNode);  // Delete testNode linked list
    if (coincidences == sizeOfDesiredArr) // If coincidences is equal of size of desired numbers count, then return true or 1, otherwise, will return false or 0
        return 1;
    else
        return 0;
}

bool test_A1()
{
    // Input array
    const int sizeOfArr = 6; // Size of numbers array
    int numbers[sizeOfArr] = {1, 2, 3, 4, 5, 6}; // Numbers for testing
    // Desired output array
    const int sizeOfTestNums = 3; // Size of required test result array
    int testNums[3] = {1, 3, 5}; // required test array numbers to compare with result from function
    return checkOutputOdd(numbers, sizeOfArr, testNums, sizeOfTestNums);
}

bool test_A2()
{
    // Input array
    const int sizeOfArr = 6; // Size of numbers array
    int numbers[sizeOfArr] = {1, 2, 3, 4, 5, 6}; // Numbers for testing
    // Desired output array
    const int sizeOfTestNums = 3; // Size of required test result array
    int testNums[3] = {2, 4, 6}; // required test array numbers to compare with result from function
    return checkOutputEven(numbers, sizeOfArr, testNums, sizeOfTestNums);
}

bool test_B1()
{
    // Input array
    const int sizeOfArr = 10; // Size of numbers array
    int numbers[sizeOfArr] = {1, 5, 3, 2, 5, 1, 7, 9, 4, 6}; // Numbers for testing
    // Desired output array
    const int sizeOfTestNums = 7; // Size of required test result array
    int testNums[sizeOfTestNums] = {1, 5, 3, 5, 1, 7, 9}; // required test array numbers to compare with result from function
    return checkOutputOdd(numbers, sizeOfArr, testNums, sizeOfTestNums);
}

bool test_B2()
{
    // Input array
    const int sizeOfArr = 10; // Size of numbers array
    int numbers[sizeOfArr] = {1, 5, 3, 2, 5, 1, 7, 9, 4, 6}; // Numbers for testing
    // Desired output array
    const int sizeOfTestNums = 3; // Size of required test result array
    int testNums[sizeOfTestNums] = {2, 4, 6}; // required test array numbers to compare with result from function
    return checkOutputEven(numbers, sizeOfArr, testNums, sizeOfTestNums);
}

bool test_C1()
{
    // Input array
    const int sizeOfArr = 8; // Size of numbers array
    int numbers[sizeOfArr] = {1, 3, 2, 4, 5, 8, 6, 9}; // Numbers for testing
    // Desired output array
    const int sizeOfTestNums = 4; // Size of required test result array
    int testNums[sizeOfTestNums] = {1, 3, 5, 9}; // required test array numbers to compare with result from function
    return checkOutputOdd(numbers, sizeOfArr, testNums, sizeOfTestNums);
}

bool test_C2()
{
    // Input array
    const int sizeOfArr = 8; // Size of numbers array
    int numbers[sizeOfArr] = {1, 3, 2, 4, 5, 8, 6, 9}; // Numbers for testing
    // Desired output array
    const int sizeOfTestNums = 4; // Size of required test result array
    int testNums[sizeOfTestNums] = {2, 4, 8, 6}; // required test array numbers to compare with result from function
    return checkOutputEven(numbers, sizeOfArr, testNums, sizeOfTestNums);
}


int main()
{
    cout << "Test_A1: \n" << test_A1() << endl << endl; // test case 1 for odd
    cout << "Test_A2: \n" << test_A2() << endl << endl; // test case 1 for even
    cout << "Test_B1: \n" << test_B1() << endl << endl; // test case 2 for odd
    cout << "Test_B2: \n" << test_B2() << endl << endl; // test case 2 for even
    cout << "Test_C1: \n" << test_C1() << endl << endl; // test case 3 for odd
    cout << "Test_C2: \n" << test_C2() << endl << endl; // test case 3 for even
    Node* justTest = NULL;
    try{
        printLinkedList(justTest);
    } catch(const char *e){
        cout << "Error: " << e << endl;
    }

}
