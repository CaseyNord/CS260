//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 7, 2018
// Project #4
// Driver Name: testList.cpp
// Program Description: Array based that auto sorts (using a binary search) when items are added
// Complexity: Linear - O(n)
//*****************************************************************
class ArrayList
{
    private:
        int myList[10];
        int topIndex;

    public:
        ArrayList();
        int binarySearch(int data, int start, int end);
        void addItem(int newValue);
        void deleteItem(int deleteData);
        void printList();
};