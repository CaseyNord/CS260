//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 23, 2018
// Project #2
// Driver Name: testList.cpp
// Program Description: Stack implementation using linked list
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "LinkedStack.h"

using namespace std;


LinkedStack::LinkedStack() // Total: O(2)
{
    head = NULL; // O(1)
    tail = NULL; // O(1)
}

void LinkedStack::push(int addData) // Total (worst case): O(6)
{
    node *newNode = new node; // O(1)
    newNode->data = addData; // O(1)
    if (head != NULL) // O(1)
    {
        newNode->next = head; // O(1)
        head = newNode; // O(1)
    }
    else
    {
        head = newNode; // O(1)
        tail = newNode; // O(1)
    }
    newNode = NULL; // this necessary garbage collection? // O(1)
}

void LinkedStack::pop() // Total (worst case): O(5)
{
    if (head != NULL) // O(1)
    {
        node *deletePtr = NULL; // O(1)
        deletePtr = head; // O(1)
        head = head->next; // O(1)
        delete deletePtr; // garbage collection // O(1)
    }
    else
    {
        cout << "The stack is empty!" << endl; // O(1)
    }
}

void LinkedStack::peek() // Total: O(1)
{
    cout << head->data << endl; // O(1)
}

void LinkedStack::printList() // **Total: O(2n+2)
{
    node *printNode = new node; // O(1)
    printNode = head; // O(1)
    while(printNode != NULL) // O(2n)
    {
        cout << printNode->data << endl;
        printNode = printNode->next;
    }
}

/*

** Denotes the most complex function in the class. In this case print the list is the
    most complex functions in the class.  This specific linked list (though not 
    optimized or robust enough to be considered a real analysis of a linked list) runs 
    in linear time.

*/