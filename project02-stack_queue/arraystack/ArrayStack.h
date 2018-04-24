//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 23, 2018
// Project #2
// Driver Name: testStack.cpp
// Program Description: Stack implementation using array
//*****************************************************************

/*

Trying to include an const int or int value
for MAX causes strange issues with the compilation
and output of this program.

*/

class ArrayStack
{
    private:
        int myStack[10];
        int topIndex;

    public:
        ArrayStack();
        void push(int newValue);
        int pop();
        int peek();
        void printList();
};