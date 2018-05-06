//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 7, 2018
// Project #4
// Driver Name: testAutoSort.cpp
// Program Description: Linked list that auto sorts when items are added
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "LinkedAutoSort.h"

using namespace std;


int main(int argc, char** argv)
{
    LinkedAutoSort<string> myList;

    // populate list
    myList.addNode("apple");
    myList.addNode("taco");
    myList.addNode("fork");
    myList.addNode("steak");
    myList.addNode("banana");
    myList.addNode("knife");
    myList.addNode("burger");
    myList.addNode("avocado");
    myList.printList();
    cout << "List populated with data..." << endl << endl;
    
    // delete data
    myList.deleteNode("banana");
    myList.printList();
    cout << "Deleted item from list successfully!" << endl << endl;

    // insert repeat data data
    myList.addNode("taco");
    myList.printList();
    cout << "Data with repeated value inserted successfully!" << endl << endl;

    cout << "All tests passed!" << endl << endl;

    return 0;
}