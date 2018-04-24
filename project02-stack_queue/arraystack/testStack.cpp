//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 23, 2018
// Project #2
// Driver Name: testStack.cpp
// Program Description: Stack implementation using array
//*****************************************************************
#include <cstdlib>
#include <iostream>
#include "ArrayStack.h"

using namespace std;


int main()
{
    ArrayStack myStack;

    // empty stack test
    myStack.pop();
    cout << "Pop attempt on empty list test success!" << endl << endl;

    myStack.push(3);
    myStack.push(5);
    myStack.push(7);
    myStack.push(9);
    myStack.push(11);
    myStack.printList();
    cout << "Pushed items onto list success!" << endl << endl;

    cout << myStack.peek() << endl;
    cout << "Peek at top item success!" << endl << endl;

    myStack.push(13);
    myStack.printList();
    cout << "Pushed additional item onto list success!" << endl << endl;

    myStack.pop();
    myStack.printList();
    cout << "Popped item from list success!" << endl << endl;

    myStack.pop();
    cout << myStack.peek() << endl;
    cout << "Popped item from list then peeked at new top success!" << endl << endl;

    myStack.push(15);
    cout << myStack.peek() << endl;
    cout << "Pushed item onto list then peeked at new top success!" << endl << endl;

    myStack.push(20);
    myStack.printList();
    cout << "Pushed item onto list then printed list success!" << endl << endl;

    // full stack test
    myStack.push(2);
    myStack.push(140);
    myStack.push(24);
    myStack.push(87);
    myStack.push(21);
    myStack.printList();  
    cout << "Attempted to overflow list success!" << endl << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.printList();
    cout << "Popped successive items from list and printed new list success!" << endl << endl;

    cout << "All tests passed!" << endl << endl;

    return 0;
}