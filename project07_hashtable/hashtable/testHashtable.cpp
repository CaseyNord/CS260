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
#include <fstream>

#include "Hashtable.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::string;


int main(int argc, char** argv)
{
    Hashtable<string> myHash;

    myHash.addItem("banana");
    myHash.addItem("fork");
    myHash.addItem("chicken");
    myHash.addItem("burger");
    myHash.addItem("lettuce");
    myHash.addItem("knife");
    myHash.addItem("apple");
    myHash.addItem("fish");
    myHash.addItem("salt");
    myHash.addItem("water");
    myHash.addItem("waffle");
    myHash.addItem("potato");

    myHash.printList();

    myHash.deleteItem("apple");
    myHash.deleteItem("salt");
    myHash.deleteItem("banana");
    myHash.deleteItem("burger");

    myHash.printList();

    cout << "Adding data from external source..." << endl << endl;

    // Using input stream to add a massive amount of entries to the table
    // First we declare an input file stream variable
    ifstream inFile;
    // Then we open the stream
    inFile.open("table_entries.txt");
    // Check is file was opened successfully
    if (!inFile)
    {
        cerr << "Unable to open file table_entries.txt" << endl << endl;
        exit(1); // Stop program
    }

    // Read the stream
    string x;
    while (inFile >> x)
    {
        myHash.addItem(x);
    }

    //close the stream
    inFile.close();

    myHash.printList();

    return 0;
}