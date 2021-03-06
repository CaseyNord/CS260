//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 7, 2018
// Project #4
// Driver Name: testList.cpp
// Program Description: Array based that auto sorts when items are added
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>
#include "ArrayList.h"

using std::cout;
using std::endl;
using std::string;


int main()
{
    ArrayList<string> myList;

    // populate list
    myList.addItem("banana");
    myList.addItem("turkey");
    myList.addItem("apple");
    myList.addItem("spinach");
    myList.addItem("knife");
    myList.addItem("chocolate");
    myList.addItem("coconut");
    myList.addItem("fork");
    myList.printList();
    cout << "List populated with data..." << endl << endl;
    
    // delete data
    myList.deleteItem("turkey");
    myList.printList();
    cout << "Deleted item from list successfully!" << endl << endl;

    // add item back to list
    myList.addItem("onion");
    myList.printList();
    cout << "Item added to list successfully!" << endl << endl;

    // add duplicate item to list
    myList.addItem("spinach");
    myList.printList();
    cout << "Duplicate item added to list successfully!" << endl << endl;

    // attempt to overfill list
    myList.addItem("soup");
    myList.addItem("hamburger");
    myList.printList();
    cout << "Attempt to overfill successfully!" << endl << endl;


    cout << "All tests passed!" << endl << endl;    

    return 0;
}