//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 21, 2018
// Project #7
// Program Description: Hashtable
// Complexity: 
//*****************************************************************

/*

This hashtable takes a value and determines an array index based on a very
simple hashing algorithm...

It may be obvious but collisions will instantly put us in situations where
we could lose track of data.

An example of this would be a collision where an item would be moved to a
different index.

If the previous data (i.e. parent data to data added that experienced collision)
is deleted, then the hash will not be able to locate the collision.

Though this is undesirable, it illustrates an important problem with hashing
and gives insight into the complexity of designing a good hash.

Because of this I have implemented a (very poor) way to handle collisions
that causes the data to pile up after the value's index that it collides
with.

Again, this illustrates an important problem with hashing and gives insight
into the complexity of designing a good hash.

*/

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

#define MAX 10

template <class T>
class Hashtable
{
    private:
        T myTable[MAX];
        T collisionTable[MAX];

        int collisionIndex; 

    public:
        Hashtable();
        int hash(T data);
        void addItem(T newValue);
        void deleteItem(T deleteData);
        void printList();
};


template <class T>
Hashtable<T>::Hashtable()
{
    collisionIndex = 0;

    for (int i = 0; i < MAX; i++)
    {
        myTable[i] = NULL;
    }
}

template <class T>
int Hashtable<T>::hash(T data)
{
    if (data % 10 == 0)
    {
        data++;
    }

    data = data * 42 % MAX;

    return data; 
}

template <class T>
void Hashtable<T>::addItem(T newValue)
{
    int index = hash(newValue);

    if (myTable[index] == NULL)
    {
        myTable[index] = newValue;
    }
    else
    {
        while(myTable[index] != NULL)
        {
            if (myTable[index] < MAX)
            {
                index++;
            }
            else
            {
                index = 0;
            }
        }
        myTable[index] = newValue;
        collisionTable[collisionIndex] = newValue;
        collisionIndex++;

    }
}

template <class T>
void Hashtable<T>::deleteItem(T deleteData)
{
    int index = hash(deleteData);

    if (myTable[index] == deleteData)
    {
        myTable[index] = NULL;
        cout << "The value " << deleteData << " has been removed from the table" << endl << endl;
    }
    else
    {
        cout << "The value " << deleteData << " wasn't found in the table" << endl << endl;
    }
}

template <class T>
void Hashtable<T>::printList() // Total (worst case): O(2n)
{
    for (int i = 0; i < MAX; i++) // O(n)
    {
        cout << myTable[i] << endl; // O(n)
    }
}

