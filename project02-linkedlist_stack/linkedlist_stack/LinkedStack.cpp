#include <cstdlib>
#include <iostream>

#include "LinkedStack.h"

using namespace std;


LinkedStack::LinkedStack()
{
    head = NULL;
    tail = NULL;
}

void LinkedStack::push(int addData)
{
    node *newNode = new node;
    newNode->data = addData;
    newNode->next = NULL;

    if(head != NULL)
    {
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
        newNode = NULL; // garbage collection?
    }
}

void LinkedStack::pop()
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

void LinkedStack::peek()
{
    cout << tail->data << endl;
}

void LinkedStack::printList()
{
    node *printNode = new node;
    printNode = head;
    while(printNode != NULL)
    {
        cout << printNode->data << endl;
        printNode = printNode->next;
    }
}