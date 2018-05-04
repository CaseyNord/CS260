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

const int MAX_ARRAY = 10;

ArrayList::ArrayList() // Total: O(2n+1)
{
    topIndex = -1; // O(1)
    // Is this good practice?
    for (int i = 0; i < MAX_ARRAY; i++) // O(2n)
    {
        myList[i] = NULL; // O(n)
    }
}

int ArrayList::binarySearch(int data, int start, int end)
{
    // Terminate if start is greater than end
    if (start > end)
    {
        return 0;
    }

    // This is the mid
    int sortIndex = start + (end - start) / 2;

    // Is an item of the same value in the sortIndex?
    if (myList[sortIndex] == data)
        return sortIndex;
    else if (myList[sortIndex] > data && myList[sortIndex - 1] <= 0)
        return sortIndex;
    else if (myList[sortIndex] < data && myList[sortIndex + 1] >= MAX_ARRAY)
        return sortIndex;
    else if (myList[sortIndex] > data && myList[sortIndex - 1] < data)
        return sortIndex;
    else if (myList[sortIndex] < data && myList[sortIndex + 1] < data)
        return sortIndex;

    if (myList[sortIndex] > data)
        return binarySearch(data, start, sortIndex - 1);
    if (myList[sortIndex] < data)
        return binarySearch(data, sortIndex + 1, end);
}

void ArrayList::addItem(int newValue) // Total (worst case): O(2n+4)
{
    int insertIndex = 0;

    if (topIndex < 0) // O(1)
    {
        // Add item to an empty list
        topIndex++; // O(1)
        myList[topIndex] = newValue; // O(1)
        return; // O(1)
    }
    else if (topIndex >= MAX_ARRAY)
    {
        cout << "The list is full!" << endl; // O(1)
    }
    else if (topIndex < MAX_ARRAY) // O(1)
    {
        insertIndex = binarySearch(newValue, 0, topIndex);

        for (int i = topIndex; i > insertIndex; i--)  // O(2n)
        {
            myList[i] = myList[i-1]; // O(n)
        }
        topIndex++; // O(1)
        myList[insertIndex] = newValue; // O(1)
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

    Is it true that each operation inside of a while loop or a for loop could be considered
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