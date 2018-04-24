#include <cstdlib>
#include <iostream>

#include "ArrayList.h"

using namespace std;


//constructor
ArrayList::ArrayList()
{
    topIndex = -1;
}

void ArrayList::addItem(int newValue)
{
    if (topIndex < 9)
    {
    topIndex++;
    myStack[topIndex] = newValue;
    }
    else
    {
        cout << "The list is full!" << endl;
    }
}

int ArrayList::insertItem(int data, int listIndex)
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

void deleteItem(int deleteData)
{
    // code here
}

void ArrayList::printList()
{
    for (int i = 0; i <= topIndex; i++)
    {
        cout << myStack[i] << endl;
    }
}