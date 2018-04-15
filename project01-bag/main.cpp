//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 09, 2018
// Project #1
// Driver Name: main.cpp
// Program Description: Driver program for Project #1
//*****************************************************************
#include <iostream>
#include <cstdlib>
#include "bag.cpp"

using namespace std;

// Input validation?

int main()
{
    Bag myBag;

    system("clear"); // Clear console Bash
    bool menuLoop = true;
    while(menuLoop)
    { 
        cout << "Please select from the following options:" << endl << endl;
        cout << "1: Open bag" << endl;
        cout << "2: Close bag" << endl;
        cout << "3: Add a marble" << endl;
        cout << "4: Remove a marble" << endl;
        cout << "5: Display bag information" << endl;
        cout << "0: Exit" << endl;

        int selection;
        cin >> selection;

        //system("cls"); // Clear console Windows
        system("clear"); // Clear console Bash

        switch (selection)
        {
            case 0:
                cout << "Goodbye" << endl << endl;
                menuLoop = false;
                break;

            case 1:
                myBag.openBag();
                break;

            case 2:
                myBag.closeBag();
                break;

            case 3:
                myBag.addMarble();
                break;

            case 4:
                myBag.removeMarble();
                break;
            
            case 5:
                myBag.toString();
                break;
        }
    }

    return 0;
}