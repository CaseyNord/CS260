//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 23, 2018
// Project #2
// Driver Name: testQueue.cpp
// Program Description: Queue implementation with linked list
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "LinkedQueue.h"

using namespace std;


int main(int argc, char** argv)
{
    LinkedQueue myQueue;

    // empty queue test
    myQueue.remove();
    cout << "Remove attempt on empty queue success!" << endl << endl;

    myQueue.add(3);
    myQueue.add(5);
    myQueue.add(7);
    myQueue.add(9);
    myQueue.add(11);
    myQueue.printList();
    cout << "Added items onto queue success!" << endl << endl;

    myQueue.remove();
    myQueue.printList();
    cout << "Remove item from queue success!" << endl << endl;

    myQueue.add(20);
    myQueue.printList();
    cout << "Added another item to queue success!" << endl << endl;

    myQueue.remove();
    myQueue.remove();
    myQueue.remove();
    myQueue.printList();
    cout << "Removed successive items from queue success!" << endl << endl;

    cout << "All tests passed!" << endl << endl;

    return 0;
}