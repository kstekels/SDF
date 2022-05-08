// ks21180, Karlis Stekels
#pragma once

struct Node // Structure for Doubly linked list Node
{
    int value; // Node Value
    Node* next; // Pointer to the next node
    Node* previous; // Pointer to previous node
};


void printLinkedList(Node* node);

Node* printOdd(int numbers[], int sizeOfArray, Node*& first, Node*& last);

Node* printEven(int numbers[], int sizeOfArray, Node*& first, Node*& last);

void rem(Node*&node);
