#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;


int main(int argc, char** argv)
{
    LinkedList myList;

    //test empty list
    //myList.sort();

    //test list with one element
    /*
    myList.addNode(11);
    myList.sort();
    */

    //test regular unsorted list
    
    myList.addNode(11);
    myList.addNode(5);
    myList.addNode(4);
    myList.addNode(9);
    myList.addNode(63);
    myList.addNode(6);
    myList.addNode(20);
    myList.addNode(677);
    myList.addNode(8);
    myList.addNode(1);
    myList.addNode(35);
    myList.addNode(90);
    myList.addNode(6);
    myList.addNode(47);
    myList.addNode(1072);
    myList.addNode(54);
    myList.addNode(21);
    myList.addNode(2);
    myList.addNode(7);
    myList.addNode(0);
    

    //test reverse sorted list
    /*
    for (int i = 19; i >= 0; i--)
    {
        myList.addNode(i);
    }
    */

    //test sorted list
    /*
    for (int i = 0; i <= 19; i++)
    {
        myList.addNode(i);
    }
    */

    myList.printList();
    cout << endl;
    myList.sort();
    myList.printList();

    return 0;
}