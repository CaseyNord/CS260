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


int main()
{
    MergeSort myMerge;

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

    myMerge.printList(list, arraySize);

    cout << endl << "Using merge sort to sort data..." << endl << endl;

    myMerge.sort(list, 0, arraySize - 1);

    cout << "Mergesort complete.." << endl << endl;

    myMerge.printList(list, arraySize);
    
    return 0;
}