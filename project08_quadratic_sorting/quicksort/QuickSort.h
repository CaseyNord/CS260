//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based quick sort
// Complexity: O(n^2)
//*****************************************************************

/*
*   There are many different variations of quick sorts
*   but they all revolve around one idea. A pivot is
*   created (maybe the lowest array index, maybe the
*   middle, or in this case, the highest index (not 
*   value)) and it is placed into its correct position 
*   by placing all values higher than it to the right 
*   of it, and all values lower than it to the left.
*
*   Not only does this place the given element in the
*   correct position, but it begins to sort the rest of
*   the list by dividing the remaining values up into
*   respective piles.
*
*   This can then be run recusrively until the entire
*   array is completely sorted!
*
*/

class QuickSort
{
    private:

    public:
        QuickSort();
        int partition(int array[], int low, int high);
        void sort(int array[], int low, int high);
        void printList(int array[], int arraySize);
};