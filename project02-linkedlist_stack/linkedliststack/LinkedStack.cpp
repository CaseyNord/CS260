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

void LinkedStack::pop()
{
    node *deletePtr = NULL;
    deletePtr = head;
    head = head->next;
    delete deletePtr; // garbage collection
}

void LinkedStack::peek()
{
    cout << head->data << endl;
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