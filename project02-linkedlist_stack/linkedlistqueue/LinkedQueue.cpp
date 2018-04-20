#include <cstdlib>
#include <iostream>

#include "LinkedQueue.h"

using namespace std;


LinkedQueue::LinkedQueue()
{
    head = NULL;
    tail = NULL;
}

void LinkedQueue::add(int addData)
{
    node *newNode = new node;
    newNode->data = addData;
    if (head != NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
    newNode = NULL; // this necessary garbage collection?
}

void LinkedQueue::remove()
{
    node *deletePtr = NULL;
    node *currentNode = head;
    node *previousNode = head;

    while(currentNode->next != NULL)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    deletePtr = currentNode;
    previousNode->next = NULL;
    tail = previousNode;
    delete deletePtr; // garbage collection
}

void LinkedQueue::printList()
{
    node *printNode = new node;
    printNode = head;
    while(printNode != NULL)
    {
        cout << printNode->data << endl;
        printNode = printNode->next;
    }
}