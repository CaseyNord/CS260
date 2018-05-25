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

Important notes:
    With a small table (an array of 10 indexes), a list of 1500 items will
    cause so many collisions that the table will never actually grow.  That is
    to say that the hashing algorithm with a list of 1500 random words never
    produces a range of indexes that would make it hit the rehash threshold.

    With an array capacity of 100 indexes, a list of 10000 items only produces
    16 unique hash indexes.

    With an array capacity of 1000 indexes, a list of 10000 items only produces
    about 355 unique hash indexes

Although I initially wanted to experiment with using something like a linked list
to handle collisions, I opted not to.  The idea would be to create a reference to
a linked list and place it at the index value where a collision occured, and then
populate the list with all of the data that collides at that index.  We could then
search the linked list whenever we hit that index.

These kinds of solutions seem common with hashtables.  You could also use arrays,
trees, or any other structure to handle a collision.  I think this is what is being
referred to when people use the term 'chaining'.  One idea I thought about was using
another hashtable!  Maybe one that was designed to create less collisions out of the
data that collides at a specific index.

I opted not to because in my tests I found that I could run lists of 10000 items with
an array of size 1000, and I only got about 355 unique hashes.  As a result I never
resized my table.  Instead I opted to handle collisions very simply (poorly) by just
iterating through the array until an empty spot was reached.  Doing this allows me to
test my resizing functions, and although it's probably slow, I'd think it still averages 
faster than linear (at least with my test data) because when a search is made we still 
probably get closer to the value by initially hashing before we start iterating through
the list linearly.

Honestly, hashing seems to be a HUGE topic with endless potential exploration and when
I think about ways to solve some of these problems I just start coming up with cascades
of things I would like to try.  At the end of the day, before I go down the rabbit hole
of trying to find what I can come with that might be OKAY, I would prefer to read some
material on the approaches that have already been developed so I can form a foundation
upon which to establish my own ideas, that would hopefully allow me to come up with some 
solutions that could actuablly be viable, instead of just trying to hack together
whatever 'creative' ideas I might have.

So, as a result, I am submitting this high collision hash table that handles collisions
with linear searches!

*/

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


template <class T>
class Hashtable
{
    private:
        float loadFactor;
        int spaceUsed;
        int initialCapacity;
        int capacity;
        int rehashThreshold;
        int hashMask;
        
        T *hashTable;

    public:
        Hashtable();
        int hash(T data);
        void clearTable(T table[]);
        void growTable(T oldHashTable[], T addData);
        void addItem(T newData);
        void deleteItem(T deleteData);
        void printList();
};


template <class T>
Hashtable<T>::Hashtable()
{
    loadFactor = 0.75f;
    spaceUsed = 0;
    initialCapacity = 10;
    capacity = initialCapacity;
    rehashThreshold = (int)(capacity * loadFactor);
    hashMask = capacity - 1;

    hashTable = new T[capacity];

    // When the hashtable is created we want to NULL out the values so we can use them utilize the value for future operations.
    // And it's good practice...
    clearTable(hashTable);

}

template <class T>
void Hashtable<T>::clearTable(T table[])
{
    for (int i = 0; i < capacity; i++)
    {
        table[i] = "";
    }
}

template <class T>
void Hashtable<T>::growTable(T oldHashTable[], T addData)
{
    cout << "Threshold reached, growing table..." << endl;

    cout << "Creating temporary table to transfer data..." << endl;

    T *tempTable = new T[spaceUsed];
    int tempCounter = 0;
    for (int i = 0; i < capacity; i++)
    {
        if (oldHashTable[i] != "")
        {
            tempTable[tempCounter] = oldHashTable[i];
            tempCounter++;
        }
    }

    cout << "Temporary table created, deleting old table..." << endl;

    delete[] oldHashTable;

    cout << "Old table deleted, initializing new values..." << endl;

    capacity = capacity * 2;
    rehashThreshold = (int)(capacity * loadFactor);
    hashMask = capacity - 1;

    cout << "Values initialized, creating new table..." << endl;

    hashTable = new T[capacity];

    cout << "New table created, initializing indexes..." << endl;

    // When the hashtable is created we want to NULL out the values so we can use them utilize the value for future operations.
    // And it's good practice...
    clearTable(hashTable);

    cout << "Indexes initialized, rehashing old data..." << endl;

    // Run through old array and rehash all data to new array
    for (int i = 0; i < spaceUsed; i++)
    {
        int newIndex = hash(tempTable[i]);
        hashTable[newIndex] = tempTable[i];
    }

    cout << "Old data rehashed, readding last item..." << endl;

    addItem(addData);

    cout << "Deleting tempTable..." << endl << endl;

    delete[] tempTable;
}

template <class T>
int Hashtable<T>::hash(T data)
{
    int hashAddress = 0;
    for (int counter = 0; data[counter] != '\0'; counter++)
    {
        hashAddress = data[counter] + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
    }
    hashAddress = hashAddress & hashMask;

    return hashAddress; 
}

template <class T>
void Hashtable<T>::addItem(T newData)
{
    int index = hash(newData);
    //cout << "Hashed index: " << index << endl;

    if (spaceUsed + 1 > rehashThreshold)
    {
        growTable(hashTable, newData);
    }
    else
    {
        if (hashTable[index] == "")
        {
            hashTable[index] = newData;
            spaceUsed++;
            //cout << newData << " has been added to the table" << endl << endl;
        }
        else
        {
            while (hashTable[index] != "")
            {
                index++;
                if (index == capacity)
                {
                    index = 0;
                }
            }
            hashTable[index] = newData;
            spaceUsed++;
        }
        /*
        // Doesn't handle collisions
        else
        {
            //cout << "Collision occured, overwriting -> " << hashTable[index] << " with -> " << newData << endl << endl; 
            hashTable[index] = newData;
        }
        */
    }
}

template <class T>
void Hashtable<T>::deleteItem(T deleteData)
{
    int index = hash(deleteData);

    if (hashTable[index] == deleteData)
    {
        hashTable[index] = "";
        cout << "The value " << deleteData << " has been removed from the table" << endl << endl;
        spaceUsed--;
    }
    else
    {
        int lookupIndex = index;
        while (hashTable[index] != deleteData)
        {
            lookupIndex++;
            if (lookupIndex == capacity)
            {
                lookupIndex = 0;
            }
            if (lookupIndex == index)
            {
                cout << "The value " << deleteData << " wasn't found in the table" << endl << endl;
                break;
            }
        }
        if (hashTable[lookupIndex] == deleteData)
        {
            hashTable[lookupIndex] = "";
            cout << "The value " << deleteData << " has been removed from the table" << endl << endl;
            spaceUsed--;
        }
    }
}

template <class T>
void Hashtable<T>::printList() // Total (worst case): O(2n)
{
    for (int i = 0; i < capacity; i++) // O(n)
    {
        if (hashTable[i] != "")
        {
            cout << hashTable[i] << endl; // O(n)
        }
    }
    cout << endl;
}

