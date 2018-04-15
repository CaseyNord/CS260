//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 09, 2018
// Project #1
// Driver Name: main.cpp
// Program Description: Bag class for Project #1
//*****************************************************************
#include <iostream>

using namespace std;

// Implementing marbles as an array of structs?
// Variable scope in classes?
// Implementing struct values as randomly picked enums?
// Hold function for holding removed marble and
// Replace function for replacing held marble
// toString() function for displaying marble information.
// At this point should probably make marble its own class!

class Bag
{
    private:
        static const int MAX_SIZE = 10;
        int marbles[MAX_SIZE];
        int top;
        bool isOpen;

        /*
        enum class size { small, medium, large };
        enum class material { glass };
        enum class color { transparent, red, orange, yellow, green, blue, violet };

        struct Marble {
            size size;
            material material;
            color color;
        };
        */

    public:
        Bag()
        {
            top = 0;
            isOpen = false;
        }

        void toString()
        {
            cout << "Holding: " << top << ", Can hold: " << MAX_SIZE << ", Is open: " << isOpen << endl <<endl;
        }

        void openBag()
        {
            isOpen = true;
            cout << "Bag is open." << endl << endl;
        }

        void closeBag()
        {
            isOpen = false;
            cout << "Bag is closed." << endl << endl;
        }

        void addMarble()
        {
            if (!(isOpen))
            {
                cout << "Bag is closed, cannot add marble." << endl << endl;
            }
            else if (top < MAX_SIZE)
            {
                marbles[top] = 1;
                top++;
                cout << "Added a marble to the bag." << endl << endl;
            }
            else
            {
                cout << "Bag is full!" << endl << endl;
            }
                
        }

        int removeMarble()
        {
            int marble = marbles[top];
            if (!(isOpen))
            {
                cout << "Bag is closed, cannot remove marble." << endl << endl;
            }
            else if (top == 0)
            // else if (marble == 0)
            {
                cout << "The bag is empty!" << endl << endl;
            }
            else
            {
                marbles[top] = 0;
                top--;
                cout << "Removed a marble from the bag." << endl << endl;
            }
            return marble;
        }
};