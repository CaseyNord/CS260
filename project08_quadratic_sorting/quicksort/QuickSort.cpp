//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based quick sort
// Complexity: O(n^2)
//*****************************************************************
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "QuickSort.h"

using std::cout;
using std::endl;
using std::swap;


QuickSort::QuickSort()
{

}

int QuickSort::partition(int array[], int low, int high) // Total (worst case): O(3n + 4)
{
    int pivot = array[high]; // O(1)
    int i = (low - 1); // O(1)

    for (int j = low; j <= high - 1; j++) // O(n)
    {
        // Is the current value less then or equal to the pivot?
        if (array[j] <= pivot) // O(1)
        {
            // If so increment the index of the smaller element
            i++; // O(1)
            swap(array[i], array[j]); // O(1)
        }
    }
    swap(array[i + 1], array[high]); // O(1)
    return (i + 1); // O(1)
}

void QuickSort::sort(int array[], int low, int high) // Total (worst case): O(n^2 + 2)
{
    if (low < high) // O(1)
    {
        // Our partition function seeks the highest array element
        // and pivots all data around it.  This index effectively
        // separates the list into two chunks
        int partitionIndex = partition(array, low, high); // O(1)
    
        // Recursively sort all data on each side of the
        // partition index...
        sort(array, low, partitionIndex - 1); // O(n)
        sort(array, partitionIndex + 1, high); // O(n)
    }
}

void QuickSort::printList(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << endl;
    }
}