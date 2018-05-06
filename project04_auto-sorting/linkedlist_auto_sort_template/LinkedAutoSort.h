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

using std::cout;
using std::endl;


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
void LinkedAutoSort<T>::addNode(T addData) // Total (worst case): O(3n+9)
{
    node *newNode = new node; // O(1)
    newNode->data = addData; // O(1)
    newNode->next = NULL; // O(1)
    node *currentNode = head; // O(1)
    node *previousNode = head; // O(1)

    if(head != NULL) // O(1)
    {
        // Is current HEAD larger than the value I am trying to add?
        if(head->data > newNode->data) // O(1)
        {
            // If so newValue becomes HEAD
            newNode->next = head; // O(1)
            head = newNode; // O(1)
        }
        else
        {
            // Travel through the list
            while (currentNode != NULL) // O(n)
            {
                // Is the value I am trying to add less then the value we are looking at?
                if(newNode->data < currentNode->data) // O(n)
                {
                    // If so place it before that value
                    newNode->next = previousNode->next; // O(1)
                    previousNode->next = newNode; // O(1)
                    return; // O(1)
                }
                else
                {
                    // If not keep travelling through the list
                    previousNode = currentNode; // O(n)
                    currentNode = currentNode->next; // O(n)
                }
            }
            // If we reach the end this new item must be bigger than any other
            // It becomes the new tail
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

    // Travel through the list and check for the data we want to delete
    while(currentNode != NULL && currentNode->data != deleteData) // O(n)
    {
        previousNode = currentNode; // O(n)
        currentNode = currentNode->next; // O(n)
    }
    
    // If we reach the end the item must not exist in the list
    if(currentNode == NULL) // O(1)
    {
        cout << deleteData << " was not in the list" << endl; // O(1)
    }
    else
    {
        // The item is found and deleted
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
void LinkedAutoSort<T> ::printList() // Total: O(3n+2)
{
    node *printNode = new node; // O(1)
    printNode = head; // O(1)
    while(printNode != NULL) // O(n)
    {
        cout << printNode->data << endl; // O(n)
        printNode = printNode->next; // O(n)
    }
}