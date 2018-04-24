#include <cstdlib>
#include <iostream>
#include "ArrayList.h"

using namespace std;


int main()
{
    ArrayStack myStack;

    // insert into empty list
    myList.insertItem(42, 10);
    myList.printList();
    cout << "Insert into empty list success!" << endl << endl;

    // delete first item
    myList.deleteItem(42);
    cout << "Item deleted successfully!" << endl << endl;

    // populate list
    myList.addItem(5);
    myList.addItem(7);
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

    // insert data
    myList.insertItem(66, 5);
    myList.printList();
    cout << "Data inserted successfully!" << endl << endl;

    // insert data beyond bounds
    myList.insertItem(44, 20);
    myList.printList();
    cout << "Beyond bounds index check successful!" << endl << endl;

    cout << "All tests passed!" << endl << endl;    

    return 0;
}