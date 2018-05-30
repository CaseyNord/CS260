//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based merge sort
// Complexity: O(nLogn)
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "MergeSort.h"

using std::cout;
using std::endl;

MergeSort::MergeSort()
{

}

void MergeSort::merge(int array[], int left, int middle, int right) // Total (worst case): O((4n + 9)/2 + 6)
{
    int leftIndex = middle - left + 1; // O(1)
    int rightIndex = right - middle; // O(1)

    // Temporary arrays to split data into independent groups for merging
    int leftArray[leftIndex], rightArray[rightIndex]; // O(1)

    // Data gets copied into each new array...
    for (int i = 0; i < leftIndex; i++) // O(n/2)
    {
        leftArray[i] = array[left + i]; // O(1)
    }
    for (int i = 0; i < rightIndex; i++) // O(n/2)
    {
        rightArray[i] = array[middle + 1 + i]; // O(1)
    }

    /*
    *   i keeps track of the left array
    *   j keeps track of the right array
    *   k keeps track of the original array
    */
    int i = 0, j = 0, k = left; // O(1)
    // Are we still within the bounds of our left and right arrays?
    while (i < leftIndex && j < rightIndex) // (worst case): O(n/2)
    {
        // If so, is the value in the leftArray less than the value in the rightArray?
        if (leftArray[i] <= rightArray[j]) // O(1)
        {
            // If it is then the value in the leftArray gets merged
            array[k] = leftArray[i]; // O(1)
            i++; // O(1)
        }
        else
        {
            // If not the value in the rightArray gets merged
            array[k] = rightArray[j]; // O(1)
            j++; // O(1)
        }
        // Increment the original array as we work through the process
        k++; // O(1)
    }

    // Are there any values remaining in the leftArray?
    while (i < leftIndex) // (worst case): O(n/2)
    {
        // If so add them to the original array
        array[k] = leftArray[i]; // O(1)
        i++; // O(1)
        k++; // O(1)
    }

    // Are there any value remaining in the rightArray?
    while (j < rightIndex) // (worst case): O(n/2)
    {
        // If so add them to the original array
        array[k] = rightArray[j]; // O(1)
        j++; // O(1)
        k++; // O(1)
    }
}

void MergeSort::sort(int array[], int left, int right) // Total (worst case): O(nLogn)
{
    if (left < right) // O(1)
    {
        int middle = left + (right - left) / 2; // O(1)

        // Sort left half
        sort(array, left, middle); // O(Logn)
        // Sort right half
        sort(array, middle + 1, right); // O(Logn)

        merge(array, left, middle, right); // O(Logn)
    }
}

void MergeSort::printList(int array[], int arraySize) // Total: O(n)
{
    for (int i = 0; i < arraySize; i++) // O(n)
    {
        cout << array[i] << endl; // O(1)
    }
}