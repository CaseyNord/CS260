//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based heap sort
// Complexity: O(nLogn)
//*****************************************************************

/*
*
* A heap is defined as a Complete Binary Tree where all the values are sorted
* in either ascending or descending order.
* 
* A Complete Binary Tree is a tree that is full, aside from maybe one node at
* the far bottom right corner of the tree.
* 
* To achieve a heap for a heap sort we first take the data we want to sort and
* order it using a 'heapify' function that recursively sorts our data into either
* ascending or (in this example) descending order.
* 
* The HeapSort itself works by systematically heaping the data
* so that the largest value is moved to the top of the tree, and then places that
* value at the end of the array, and reduces the index that it looks at by one,
* effectively reducing the maximum size of the heapify data while backwards
* sorting the array itself.
* 
*/

class HeapSort
{
    private:

    public:
        HeapSort();
        void heapify(int array[], int heapSize, int index);
        void sort(int array[], int heapSize);
        void printList(int array[], int arraySize);
};