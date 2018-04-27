//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 30, 2018
// Project #3
// Driver Name: testList.cpp
// Program Description: Linked list with arbitrary insert/remove operations
// Complexity: Linear - O(n)
//*****************************************************************
class LinkedList 
{
    private:
        struct node{
            int data;
            node *next;
        };

        node *head;
        node *tail;

    public:
        LinkedList();
        void addNode(int addData);
        void insertNode(int addData, int listIndex);
        void deleteNode(int deleteData);
        void printList();
};
