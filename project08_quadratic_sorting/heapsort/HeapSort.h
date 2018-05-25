//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based heap sort
// Complexity:
//*****************************************************************
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

#define MAX 10

template <class T>
class HeapSort
{
    private:
        T myList[MAX];
        int topIndex;

    public:
        Heapsort();
        void addItem(T newValue);
        void deleteItem(T deleteData);
        void printList();
};

template <class T>
Heapsort<T>::Heapsort() // Total: O(2n+1)
{
    topIndex = -1; // O(1)
    
    /*
    // Initialze the array with NULL values
    for (int i = 0; i < MAX; i++) // O(2n)
    {
        myList[i] = NULL; // O(n)
    }
    */
}

template <class T>
void Heapsort<T>::addItem(T newValue) // Total (worst case): O(4n+4)
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
    else if (topIndex >= MAX-1)
    {
        cout << "The list is full!" << endl; // O(1)
        return; // O(1)
    }
    else
    {
        // Travel through the list and find the existing
        // value that is bigger than the value I am trying to add
        while (newValue > myList[insertIndex] && insertIndex <= topIndex) // O(2n)
        {
            insertIndex++;
        }
        
        // Shift all items in the list up to make space for the new item
        if (topIndex != 0)
        {
            topIndex++; // O(1)
            for (int i = topIndex; i > insertIndex; i--)  // O(2n)
            {
                myList[i] = myList[i-1]; // O(n)
            }
            // Place new item in its spot
            myList[insertIndex] = newValue; // O(1)
        }
        // Special case where second element added is smaller than first
        else
        {
            topIndex++;
            myList[topIndex] = myList[topIndex-1];
            myList[insertIndex] = newValue;
        }
    }
}

template <class T>
void Heapsort<T>::deleteItem(T deleteData) // Total (worst case): O(6n+4) 
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
            topIndex--; // O(1)
            break; // O(1)
        }
    }

    // Run back up the list and shift all items over to fill the gap
    while (listIndex <= topIndex)  // O(n)
    {
        myList[listIndex] = myList[listIndex + 1]; // O(n)
        listIndex++; // O(n)
    }

    // Remove copy of last item in list from index beyond topIndex
    //myList[listIndex+1] = NULL; // O(1)
}

template <class T>
void Heapsort<T>::printList() // Total (worst case): O(2n)
{
    for (int i = 0; i <= topIndex; i++) // O(n)
    {
        cout << myList[i] << endl; // O(n)
    }
}