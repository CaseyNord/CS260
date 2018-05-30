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

#include "QuickSort.h"

using std::cout;
using std::endl;


int main()
{
    QuickSort mySort;

    /*
    // Test list of 10 items
    int list[] = {22, 37, 13, 64, 72, 11, 3, 303, 45, 87};
    int arraySize = sizeof(list)/sizeof(list[0]);
    */

    // Big list of random values
    int arraySize = 100;
    int list[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        list[i] = rand() % 1000;
    }

    cout << "Test array of 10 values created" << endl << endl;

    mySort.printList(list, arraySize);

    cout << endl << "Using quick sort to sort data..." << endl << endl;

    mySort.sort(list, 0, arraySize - 1);

    cout << "Mergesort complete.." << endl << endl;

    mySort.printList(list, arraySize);
    
    return 0;
}