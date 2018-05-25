//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based heapsort
// Complexity:
//*****************************************************************
#include <cstdlib>
#include <iostream>
#include "MergeSort.h"

using std::cout;
using std::endl;


int main()
{
    MergeSort<int> myList;

    // populate list
    myList.addItem(7);
    myList.addItem(5);
    myList.addItem(9);
    myList.addItem(11);
    myList.addItem(3);
    myList.addItem(47);
    myList.addItem(13);
    myList.addItem(26);
    myList.printList();
    cout << "List populated with data..." << endl << endl;
    
    // delete data
    myList.deleteItem(9);
    myList.printList();
    cout << "Deleted item from list successfully!" << endl << endl;

    // add item back to list
    myList.addItem(8);
    myList.printList();
    cout << "Item added to list successfully!" << endl << endl;

    // add duplicate item to list
    myList.addItem(11);
    myList.printList();
    cout << "Duplicate item added to list successfully!" << endl << endl;

    // attempt to overfill list
    myList.addItem(62);
    myList.addItem(6);
    myList.printList();
    cout << "Attempt to overfill successfully!" << endl << endl;


    cout << "All tests passed!" << endl << endl;    

    return 0;
}