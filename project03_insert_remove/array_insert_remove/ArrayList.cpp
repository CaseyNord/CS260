//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 30, 2018
// Project #3
// Driver Name: testList.cpp
// Program Description: Array based list with arbitrary insert/remove operations
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "ArrayList.h"

using namespace std;


ArrayList::ArrayList() // Total: O(2n+1)
{
    topIndex = -1; // O(1)
    // Is this good practice?
    for (int i = 0; i < 10; i++) // O(2n)
    {
        myList[i] = NULL; // O(n)
    }
}

void ArrayList::addItem(int newValue) // Total (worst case): O(3)
{
    if (topIndex < 9) // O(1)
    {
    topIndex++; // O(1)
    myList[topIndex] = newValue; // O(1)
    }
    else
    {
        cout << "The list is full!" << endl; // O(1)
    }
}

void ArrayList::insertItem(int data, int listIndex) // Total (worst case): O(2n+4)
{
    if (listIndex > topIndex + 1) // O(1)
    {
        cout << "This insert is out of bounds!" << endl; // O(1)
        return; // O(1)
    }
    else if (topIndex < 10) // O(1)
    {
        for (int i = topIndex; i > listIndex; i--)  // O(2n)
        {
            myList[i] = myList[i-1]; // O(n)
        }
        topIndex++; // O(1)
        myList[listIndex] = data; // O(1)
    }
    else
    {
        cout << "The list is full!" << endl; // O(1)
    }
}

void ArrayList::deleteItem(int deleteData) // Total (worst case): O(6n+4) 
{
    int listIndex = topIndex; // O(1)
    while (listIndex >= 0) // O(n)
    {
        if (myList[listIndex] != deleteData) // O(n)
        {
            listIndex--; // O(n)
        }
        else
        {
            // Again, Is this good practice?
            myList[listIndex] = NULL; // O(1)
            topIndex--; // O(1)
            break; // O(1)
        }
    }

    while (listIndex < topIndex)  // O(n)
    {
        myList[listIndex] = myList[listIndex + 1]; // O(n)
        listIndex++; // O(n)
    }

    /*

    Is it true that each operation inside of a while loop could be considered
    O(n) because it has to perform an action for each item in the list?  If that
    is the case, then this function would be O(6n+3) because in the worst case (item
    deleted is at index 0), the function would run through and perform 6 operations
    on each item in the list!

    */
}

void ArrayList::printList() // Total (worst case): O(2n)
{
    for (int i = 0; i <= topIndex; i++) // O(n)
    {
        cout << myList[i] << endl; // O(n)
    }
}