//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 7, 2018
// Project #4
// Driver Name: testList.cpp
// Program Description: Array based that auto sorts (using a binary search) when items are added
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>
#include "ArrayList.h"

using namespace std;


int main()
{
    ArrayList myList;

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

    cout << "All tests passed!" << endl << endl;    

    return 0;
}