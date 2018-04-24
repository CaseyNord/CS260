//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 23, 2018
// Project #2
// Driver Name: testQueue.cpp
// Program Description: Queue implementation with linked list
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "LinkedQueue.h"

using namespace std;


LinkedQueue::LinkedQueue() // Total: O(2)
{
    head = NULL; // O(1)
    tail = NULL; // O(1)
}

void LinkedQueue::add(int addData) // Total (worst case): O(6)
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

void LinkedQueue::remove() // **Total (worst case): O(2n+8)
{
    if (head != NULL) // O(1)
    {
    node *deletePtr = NULL; // O(1)
    node *currentNode = head; // O(1)
    node *previousNode = head; // O(1)

    while(currentNode->next != NULL) // O(2n)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    deletePtr = currentNode; // O(1)
    previousNode->next = NULL; // O(1)
    tail = previousNode; // O(1)
    delete deletePtr; // garbage collection // O(1)
    }
    else
    {
        cout << "The list is empty!" << endl; // O(1)
    }
}

void LinkedQueue::printList() // Total: O(2n+2)
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

** Denotes the most complex function in the class. In this case removing an item and
    printing the list are the two most complex functions in the class.  Removing an
    item has the potential of adding a few more contant operations, making it slightly
    more complex, however these constants don't seem to be significant and will
    probably start being ignored in future projects.  As it stands, this specific
    queue class (though not optimized or robust enough to be considered a real
    analysis of a queue) runs in linear time.

*/