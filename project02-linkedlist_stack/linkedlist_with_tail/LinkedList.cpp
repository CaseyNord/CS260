#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;



LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
    temp = NULL;
}

void LinkedList::addNode(int addData)
{
    nodePtr n = new node;
    n->data = addData;
    n->next = NULL;

    if(head != NULL)
    {
        current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
    }
    else
    {
        head = n;
        tail = n; // where to put tail?
    }
}

void LinkedList::deleteNode(int deleteData)
{
    nodePtr deletePtr = NULL;
    current = head;
    temp = head;

    // iterate through the list until the desired data is found (deleteData)
    // or the end of the list is reached (NULL)
    while(current != NULL && current->data != deleteData) // seg faults if these conditions are reversed
    {
        temp = current;
        current = current->next;
    }
    // iterated all the way through until the end of the list
    if(current == NULL)
    {
        cout << deleteData << " was not in the list" << endl;
        delete deletePtr; // garbage collection -- this call isn't necessary
    }
    // desired data (deleteData) has been found
    else
    {
        deletePtr = current;
        current = current->next;
        temp->next = current;
        if(deletePtr == head)
        {
            head = head->next;
            temp = NULL;
        }
        delete deletePtr; // garbage collection
        cout << "The value " << deleteData << " was deleted" << endl;
    }
}

void LinkedList::printList()
{
    current = head;
    while(current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
}