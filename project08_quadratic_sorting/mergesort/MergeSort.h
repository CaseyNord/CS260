//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 28, 2018
// Project #8
// Program Description: Array based merge sort
// Complexity: O(nLogn)
//*****************************************************************

/*
*   A special note about this merge sort...
*   I'd argue that bounds checking on our original
*   array isn't necessary because if our program
*   operates correctly, the split arrays will take
*   the values from the original array and then
*   merge them back in.  If the code is correct
*   we should merge without issues.
*
*   Bounds checking here could be dangerous because
*   it could hide issues if our sort is operating
*   incorrectly.  I'd think that it would be better
*   to see a crash or strange values than have the
*   program execute seemingly correctly but not
*   do what it is supposed to.
*/

class MergeSort
{
    private:

    public:
        MergeSort();
        void merge(int array[], int left, int middle, int right);
        void sort(int array[], int left, int right);
        void printList(int array[], int arraySize);
};
