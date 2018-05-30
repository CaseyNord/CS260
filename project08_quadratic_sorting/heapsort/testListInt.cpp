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

#include "HeapSort.h"

using std::cout;
using std::endl;


int main()
{
    HeapSort myHeap;

    /*
    // Test list of 10 items
    int heap[] = {22, 37, 13, 64, 72, 11, 3, 303, 45, 87};
    int arraySize = sizeof(heap)/sizeof(heap[0]);
    */

    // Big list of random values
    int arraySize = 100;
    int heap[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        heap[i] = rand() % 1000;
    }

    cout << "Test array of 10 values created" << endl << endl;

    myHeap.printList(heap, arraySize);

    cout << endl << "Heapifying data..." << endl;

    myHeap.heapify(heap, arraySize, 0);

    cout << endl << "Heapify complete..." << endl << endl;

    myHeap.printList(heap, arraySize);
    
    cout << endl << "Note how the values have been 'heaped', not quite sure" << endl;
    cout << "exactly how this plays out but the values are moving around!" << endl << endl;

    cout << "Running heapsort..." << endl << endl;

    myHeap.sort(heap, arraySize);

    cout << "Heapsort complete.." << endl << endl;

    myHeap.printList(heap, arraySize);

    return 0;
}