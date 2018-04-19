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

void LinkedList::sort()
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