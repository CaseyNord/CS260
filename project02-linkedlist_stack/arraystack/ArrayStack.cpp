#include <cstdlib>
#include <iostream>

#include "ArrayStack.h"

using namespace std;


//constructor
ArrayStack::ArrayStack()
{
    topIndex = -1;
}

void ArrayStack::push(int newValue)
{
    if (topIndex < 9)
    {
    topIndex++;
    myStack[topIndex] = newValue;
    }
    else
    {
        cout << "The stack is full!" << endl;
    }
}

int ArrayStack::pop()
{
    int value = myStack[topIndex];
    if (topIndex >= 0)
    {
        myStack[topIndex] = 0;
        topIndex--;
    }
    else
    {
        cout << "The stack is empty!" << endl;
    }
    return value;
}

int ArrayStack::peek()
{
    return myStack[topIndex]; 
}

void ArrayStack::printList()
{
    for (int i = 0; i <= topIndex; i++)
    {
        cout << myStack[i] << endl;
    }
}