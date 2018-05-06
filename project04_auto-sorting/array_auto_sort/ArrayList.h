//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 7, 2018
// Project #4
// Driver Name: testList.cpp
// Program Description: Array based that auto sorts when items are added
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

#define MAX 10

template <class T>
class ArrayList
{
    private:
        T myList[MAX];
        int topIndex;

    public:
        ArrayList();
        void addItem(T newValue);
        void deleteItem(T deleteData);
        void printList();
};

template <class T>
ArrayList<T>::ArrayList() // Total: O(2n+1)
{
    topIndex = -1; // O(1)
    
    // Initialze the array with NULL values
    for (int i = 0; i < MAX; i++) // O(2n)
    {
        myList[i] = NULL; // O(n)
    }
}

template <class T>
void ArrayList<T>::addItem(T newValue) // Total (worst case): O(4n+4)
{
    int insertIndex = 0;

    // If the array is empty
    if (topIndex < 0) // O(1)
    {
        // Add item to the empty list
        topIndex++; // O(1)
        myList[topIndex] = newValue; // O(1)
        return; // O(1)
    }
    // If the array is full
    else if (topIndex >= MAX)
    {
        cout << "The list is full!" << endl; // O(1)
    }
    else if (topIndex < MAX) // O(1)
    {
        // Travel through the list and find the existing
        // value that is bigger than the value I am trying to add
        while (newValue > myList[insertIndex] && insertIndex <= topIndex) // O(2n)
        {
            insertIndex++;
        }
        
        // Shift all items in the list up to make space for the new item
        for (int i = topIndex; i > insertIndex; i--)  // O(2n)
        {
            myList[i] = myList[i-1]; // O(n)
        }
        topIndex++; // O(1)
        // Place new item in its spot
        myList[insertIndex] = newValue; // O(1)
    }
}

template <class T>
void ArrayList<T>::deleteItem(T deleteData) // Total (worst case): O(6n+4) 
{
    int listIndex = topIndex; // O(1)
    // Seach backwards through the list for the item I want to delete
    while (listIndex >= 0) // O(n)
    {
        if (myList[listIndex] != deleteData) // O(n)
        {
            listIndex--; // O(n)
        }
        else
        {
            // If the item is found set its value to NULL
            myList[listIndex] = NULL; // O(1)
            topIndex--; // O(1)
            break; // O(1)
        }
    }

    // Run back up the list and shift all items over to fill the gap
    while (listIndex < topIndex)  // O(n)
    {
        myList[listIndex] = myList[listIndex + 1]; // O(n)
        listIndex++; // O(n)
    }
}

template <class T>
void ArrayList<T>::printList() // Total (worst case): O(2n)
{
    for (int i = 0; i <= topIndex; i++) // O(n)
    {
        cout << myList[i] << endl; // O(n)
    }
}