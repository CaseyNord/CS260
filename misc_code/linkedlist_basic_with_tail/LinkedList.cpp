#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;


LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

void LinkedList::addNode(int addData)
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

void LinkedList::deleteNode(int deleteData)
{
    node *deletePtr = NULL;
    node *currentNode = head;
    node *previousNode = head;

    while(currentNode != NULL && currentNode->data != deleteData)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    if(currentNode == NULL)
    {
        cout << deleteData << " was not in the list" << endl;
    }
    else
    {
        deletePtr = currentNode;
        currentNode = currentNode->next;
        previousNode->next = currentNode;
        if(deletePtr == head)
        {
            head = head->next;
            previousNode = NULL;
        }
        delete deletePtr; // garbage collection
        cout << "The value " << deleteData << " was deleted" << endl;
    }
}

void LinkedList::printList()
{
    node *printNode = new node;
    printNode = head;
    while(printNode != NULL)
    {
        cout << printNode->data << endl;
        printNode = printNode->next;
    }
}