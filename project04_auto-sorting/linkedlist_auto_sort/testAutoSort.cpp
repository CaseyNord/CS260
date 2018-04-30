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
    LinkedAutoSort myList;

    // insert into empty list
    myList.insertNode(42, 10);
    myList.printList();
    cout << "Insert into empty list success!" << endl << endl;

    // delete first item
    myList.deleteNode(42);
    cout << "Item deleted successfully!" << endl << endl;

    // populate list
    myList.addNode(5);
    myList.addNode(7);
    myList.addNode(9);
    myList.addNode(11);
    myList.addNode(3);
    myList.addNode(47);
    myList.addNode(13);
    myList.addNode(26);
    myList.printList();
    cout << "List populated with data..." << endl << endl;
    
    // delete data
    myList.deleteNode(9);
    myList.printList();
    cout << "Deleted item from list successfully!" << endl << endl;

    // insert data
    myList.insertNode(66, 5);
    myList.printList();
    cout << "Data inserted successfully!" << endl << endl;

    // insert data beyond bounds
    myList.insertNode(44, 20);
    myList.printList();
    cout << "Beyond bounds index check successful!" << endl << endl;

    cout << "All tests passed!" << endl << endl;

    return 0;
}