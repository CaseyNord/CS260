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

using namespace std;


template <class T>
class LinkedAutoSort 
{
    private:
        struct node{
            T data;
            node *next;
        };

        node *head;
        node *tail;

    public:
        LinkedAutoSort();
        void addNode(T addData);
        void deleteNode(T deleteData);
        void printList();
};


template <class T>
LinkedAutoSort<T>::LinkedAutoSort() // Total: O(2)
{
    head = NULL; // O(1)
    tail = NULL; // O(1)
}

template <class T>
void LinkedAutoSort<T>::addNode(T addData) // Total (worst case): Rewrite
{
    node *newNode = new node; // O(1)
    newNode->data = addData; // O(1)
    newNode->next = NULL; // O(1)
    node *currentNode = head;
    node *previousNode = head; // O(1)

    if(head != NULL) // O(1)
    {
        // Is head larger than the value I am trying to add?
        // If so newValue becomes the head
        if(head->data > newNode->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            while (currentNode != NULL)
            {
                if(newNode->data < currentNode->data) // O(n)
                {
                    newNode->next = previousNode->next; // O(1)
                    previousNode->next = newNode; // O(1)
                    return;
                }
                else
                {
                    previousNode = currentNode; // O(n)
                    currentNode = currentNode->next; // O(n)
                }
            }
            // New item must be placed at the end of the list!
            tail->next = newNode; // O(1)
            tail = newNode; // O(1)
        }
    }
    else
    {
        head = newNode; // O(1)
        tail = newNode; // O(1)
    }
}

template <class T>
void LinkedAutoSort<T>::deleteNode(T deleteData) // Total (worst case): O(3n+12)
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

template <class T>
void LinkedAutoSort<T>::printList() // Total: O(3n+2)
{
    node *printNode = new node; // O(1)
    printNode = head; // O(1)
    while(printNode != NULL) // O(n)
    {
        cout << printNode->data << endl; // O(n)
        printNode = printNode->next; // O(n)
    }
}