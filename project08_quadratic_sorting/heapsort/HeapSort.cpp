//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based heap sort
// Complexity: O(nLogn)
//*****************************************************************
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "HeapSort.h"

using std::cout;
using std::endl;
using std::swap;


HeapSort::HeapSort()
{

}

void HeapSort::heapify(int array[], int heapSize, int rootIndex) // Total (worst case): O(Logn + 6)
{
    // largestValue is the array index of the presumed largest value so far...
    int largestValue = rootIndex; // O(1)
    int leftChild = 2 * rootIndex + 1; // O(1)
    int rightChild = 2 * rootIndex + 2; // O(1)

    // Is the left child larger than our 'largestValue'?
    if (leftChild < heapSize && array[leftChild] > array[largestValue]) // O(1)
    {
        largestValue = leftChild;
    }

    // Is the right child larger than our 'largestValue' so far?
    if (rightChild < heapSize && array[rightChild] > array[largestValue]) // O(1)
    {
        largestValue = rightChild;
    }

    // If largestValue is not the current root, swap the values so it is!
    if (largestValue != rootIndex) // O(1)
    {
        swap(array[rootIndex], array[largestValue]); // O(1)

        // Recursively call this function to sort all items into a heap
        heapify(array, heapSize, largestValue); // O(Logn)
    }
}

void HeapSort::sort(int array[], int heapSize) // Total: O(nLogn)
{
    // Build heap
    for (int i = heapSize / 2 - 1; i >= 0; i--) // O(n)
    {
        heapify(array, heapSize, i); // (Logn)
    }

    // Sort array
    for (int i = heapSize - 1; i >= 0; i--) // O(n)
    {
        // Move largest value to the end of the list
        swap(array[0], array[i]); // O(1)

        // Heap data with reduced index
        heapify(array, i, 0); // O(Logn)
    }
}

void HeapSort::printList(int array[], int arraySize) // Total: O(n)
{
    for (int i = 0; i < arraySize; i++) // O(n)
    {
        cout << array[i] << endl;
    }
}