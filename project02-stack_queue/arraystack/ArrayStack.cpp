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


ArrayStack::ArrayStack() // O(1)
{
    topIndex = -1; // O(1)
}

void ArrayStack::push(int newValue) // Total (worst case): O(3)
{
    if (topIndex < 9) // O(1)
    {
    topIndex++; // O(1)
    myStack[topIndex] = newValue; // O(1)
    }
    else
    {
        cout << "The stack is full!" << endl; // O(1)
    }
}

int ArrayStack::pop() // Total (worst case): O(5)
{
    int value = myStack[topIndex]; // O(1)
    if (topIndex >= 0) // O(1)
    {
        myStack[topIndex] = 0; // O(1)
        topIndex--; // O(1)
    }
    else
    {
        cout << "The stack is empty!" << endl; // O(1)
    }
    return value; // O(1)
}

int ArrayStack::peek() // Total: O(1)
{
    return myStack[topIndex]; // O(1)
}

void ArrayStack::printList() // **Total: O(n)
{
    for (int i = 0; i <= topIndex; i++) // O(n)
    {
        cout << myStack[i] << endl;
    }
}

/*

** Denotes the most complex function in the class. In this case printing the list
    is the only function that won't run in constant time, because it has to iterate
    through the list in order to print the contents. This could be greater if the
    size of the stack wasn't restricted (i.e. allocating a new array once the 
    maximum is reached). This will be explored in future projects. 

*/