//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 30, 2018
// Project #3
// Driver Name: testList.cpp
// Program Description: Linked list with arbitrary insert/remove operations
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;


LinkedList::LinkedList() // Total: O(2)
{
    head = NULL; // O(1)
    tail = NULL; // O(1)
}

void LinkedList::addNode(int addData) // Total (worst case): O(7)
{
    node *newNode = new node; // O(1)
    newNode->data = addData; // O(1)
    newNode->next = NULL; // O(1)

    if(head != NULL) // O(1)
    {
        tail->next = newNode; // O(1)
        tail = newNode; // O(1)
    }
    else
    {
        head = newNode; // O(1)
        tail = newNode; // O(1)
        newNode = NULL;  // O(1)  <-- This garbage collection necessary?
    }
}

void LinkedList::insertNode(int addData, int listIndex) // Total (worst case): O(5n+12)
{
    node *newNode = new node; // O(1)
    newNode->data = addData; // O(1)
    newNode->next = NULL; // O(1)
    node *currentNode = head; // O(1)
    node *previousNode = head; // O(1)

    if(head == NULL) // O(1)
    {
        head = newNode; // O(1)
        tail = newNode; // O(1)
        newNode = NULL;  // O(1)  <-- This garbage collection necessary?
        cout << "List was empty, data used as new start of list..." << endl; // O(1)
        return; // O(1)
    }

    for(int i = 0; i < listIndex; i++) // O(2n+1)
    {
        if(currentNode != NULL) // O(n)
        {
            previousNode = currentNode; // O(n)
            currentNode = currentNode->next; // O(n)
        }
        else
        {
            tail->next = newNode; // O(1)
            tail = newNode; // O(1)
            cout << "List index out of range, data placed at end of list..." << endl; // O(1)
            return; // O(1)
        }
    }
    newNode->next = currentNode; // O(1)
    previousNode->next = newNode; // O(1)
}

void LinkedList::deleteNode(int deleteData) // Total (worst case): O(3n+12)
{
    node *deletePtr = NULL; // O(1)
    node *currentNode = head; // O(1)
    node *previousNode = head; // O(1)

    while(currentNode != NULL && currentNode->data != deleteData) // O(n)
    {
        previousNode = currentNode; // O(n)
        currentNode = currentNode->next; // O(n)
    }
    
    if(currentNode == NULL) // O(1)
    {
        cout << deleteData << " was not in the list" << endl; // O(1)
    }
    else
    {
        deletePtr = currentNode; // O(1)
        currentNode = currentNode->next; // O(1)
        previousNode->next = currentNode; // O(1)
        if(deletePtr == head) // O(1)
        {
            head = head->next; // O(1)
            previousNode = NULL; // O(1)
        }
        delete deletePtr;  // O(1)  <-- garbage collection
        cout << "The value " << deleteData << " was deleted" << endl; // O(1)
    }
}

void LinkedList::printList() // Total: O(3n+2)
{
    node *printNode = new node; // O(1)
    printNode = head; // O(1)
    while(printNode != NULL) // O(n)
    {
        cout << printNode->data << endl; // O(n)
        printNode = printNode->next; // O(n)
    }
}