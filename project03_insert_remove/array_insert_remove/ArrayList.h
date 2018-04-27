//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 30, 2018
// Project #3
// Driver Name: testList.cpp
// Program Description: Array based list with arbitrary insert/remove operations
// Complexity: Linear - O(n)
//*****************************************************************
class ArrayList
{
    private:
        int myList[10];
        int topIndex;

    public:
        ArrayList();
        void addItem(int newValue);
        void insertItem(int addData, int listIndex);
        void deleteItem(int deleteData);
        void printList();
};