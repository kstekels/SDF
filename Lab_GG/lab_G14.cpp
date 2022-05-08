// ks21180, Karlis Stekels
#include "lab_G14.h"
#include <iostream>
using namespace std;

void printLinkedList(Node* node) // Function to print Linked list values in Console
{
    if (node == NULL) throw "The provided node is NULL";
    else
    {
        while (node != NULL) // Loop until Node become Null
        {
            cout << node->value << " "; // Print in console given Node value
            node = node->next; // Assign next value to current node
        }
        cout << endl;
    }

}

Node* printOdd(int numbers[], int sizeOfArray, Node*& first, Node*& last) // Create a Doubly Linked List for Odd numbers
{
    Node* node = new Node(); // Allocating node pointer
    for (int i = 0; i < sizeOfArray; ++i) // Loop through each number in given array
    {
    if (numbers[i] % 2 != 0) // If number has remainder, that is not 0, then it is Odd
    {
        if (node->value == 0) // (0 == NULL), Checks if linked list is empty
        {
            node->value = numbers[i]; // Assign the number from given list
            node->next = nullptr; // Next points to NULL
            node->previous = nullptr; // Previous points to NULL
            first = node; // First linked list element becomes (first or head)
            last = node; // First linked list element becomes (last or tail)
        }
        else // if list is not empty and there is at least one Node
        {
            node = new Node(); // Reuse the same pointer for new Node
            node->value = numbers[i]; // Assign the number from given list
            node->next = nullptr; // Node next point to null
            node->previous = last; // Node previous point to last or tail
            last->next = node; // Adding new node to end or tail->next
            last = node;  // Tail become a new node

        }
    }

    }
    cout << "Odd Doubly Linked list: ";
    printLinkedList(first); // Print a new Odd Linked List
    return first;
}


Node* printEven(int numbers[], int sizeOfArray, Node*& first, Node*& last) // Create a Doubly Linked List for Even numbers
{
    Node* node = new Node(); // Allocating node pointer
    for (int i = 0; i < sizeOfArray; ++i) // Loop through each number in given array
    {
    if (numbers[i] % 2 == 0) // If number has remainder 0, then it is Even
    {
        if (node->value == 0) // (0 == NULL), Checks if linked list is empty
        {
            node->value = numbers[i]; // Assign the number from given list
            node->next = nullptr; // Next points to NULL
            node->previous = nullptr; // Previous points to NULL
            first = node; // First linked list element becomes (first or head)
            last = node; // First linked list element becomes (last or tail)
        }
        else // if list is not empty and there is at least one Node
        {
            node = new Node(); // Reuse the same pointer for new Node
            node->value = numbers[i]; // Assign the number from given list
            node->next = nullptr; // Node next point to null
            node->previous = last; // Node previous point to last or tail
            last->next = node; // Adding new node to end or tail->next
            last = node; // Tail become a new node

        }
    }

    }
    cout << "Even Doubly Linked list: ";
    printLinkedList(first); // Print a new Even Linked List
    return first;
}

void rem(Node*&node) // Allocated memory for structure Node is removed
{
    while (node!=NULL) // While node is not null, continue
    {
        Node *p = node->next; // Allocate a new node pointer for next node
        delete node; // delete current node
        node = p; // make current node to next node
    }
    // Do that while are nodes is not NULL
}
