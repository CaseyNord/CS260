//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 21, 2018
// Project #7
// Program Description: Hashtable
// Complexity: 
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "Hashtable.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
    Hashtable<int> myHash;

    myHash.addItem(10);
    myHash.addItem(67);
    myHash.addItem(42);
    // HANGS HERE myHash.addItem(36);
    //myHash.addItem(13);
    //myHash.addItem(77);
    //myHash.addItem(44);
    //myHash.addItem(41);
    //myHash.addItem(89);
    //myHash.addItem(127);

    myHash.printList();

    return 0;
}