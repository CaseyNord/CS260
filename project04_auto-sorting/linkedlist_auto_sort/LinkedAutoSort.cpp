//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 7, 2018
// Project #4
// Driver Name: testAutoSort.cpp
// Program Description: Linked list that auto sorts when items are added
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "LinkedAutoSort.h"

using namespace std;


LinkedAutoSort::LinkedAutoSort() // Total: O(2)
{
    head = NULL; // O(1)
    tail = NULL; // O(1)
}

void LinkedAutoSort::addNode(int addData) // Total (worst case): O(7)
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

// Merge this function with add to create a list that sorts itself
void LinkedAutoSort::sort()
{
    node *currentNode = head;
    node *testNode = head;
    int temp = 0;
    int listSize = 0;
    int listIndex = 0;

    if(head == NULL)
    {
        cout << "The list is empty!" << endl;
    }
    else if(head->next == NULL)
    {
        cout << "The list only has one item!" << endl;
    }
    else
    {
        while(currentNode != NULL)
        {
            currentNode = currentNode->next;
            listSize++;
        }
        currentNode = head;

        while(testNode != NULL)
        {
            for(int i = listIndex; i < listSize; i++)
            {
                if(testNode->data > currentNode->data)
                {
                    temp = testNode->data;
                    testNode->data = currentNode->data;
                    currentNode->data = temp;
                }       
                currentNode = currentNode->next;
            }
            testNode = testNode->next;
            currentNode = testNode;
            listIndex++;     
        }
    }
}

void LinkedAutoSort::deleteNode(int deleteData) // Total (worst case): O(3n+12)
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

void LinkedAutoSort::printList() // Total: O(3n+2)
{
    node *printNode = new node; // O(1)
    printNode = head; // O(1)
    while(printNode != NULL) // O(n)
    {
        cout << printNode->data << endl; // O(n)
        printNode = printNode->next; // O(n)
    }
}