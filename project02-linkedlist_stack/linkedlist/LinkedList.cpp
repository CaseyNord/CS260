#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;


// constructor
LinkedList::LinkedList()
{
    head = NULL;
    current = NULL;
    temp = NULL;
}

void LinkedList::addNode(int addData)
{
    nodePtr n = new node;  // declaration of node object
    n->data = addData;
    n->next = NULL;

    // if the list has already been created and has at least one element
    if(head != NULL)
    {
        // set current to the head of the list and then iterate through to the end
        current = head;
        // while the address pointed to AT the address that current points to is not NULL
        while(current->next != NULL)
        {
            current = current->next;
        }
        // if it is NULL, that means it was previously the end of the list, so set it now
        // to point to the address of the node just created
        current->next = n;
    }
    // and if head is NULL than only one node has been created, so set head to point to the
    // first node so it can be kept track of
    else
    {
        head = n;
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