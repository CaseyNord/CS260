//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 7, 2018
// Project #4
// Driver Name: testAutoSort.cpp
// Program Description: Linked list that auto sorts when items are added
// Complexity: Linear - O(n)
//*****************************************************************
class LinkedAutoSort 
{
    private:
        struct node{
            int data;
            node *next;
        };

        node *head;
        node *tail;

    public:
        LinkedAutoSort();
        void addNode(int addData);
        void deleteNode(int deleteData);
        void printList();
};
