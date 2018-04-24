//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 23, 2018
// Project #2
// Driver Name: testList.cpp
// Program Description: Stack implementation using linked list
//*****************************************************************
class LinkedStack 
{
    private:
        struct node{
            int data;
            node *next;
        };

        node *head;
        node *tail;

    public:
        LinkedStack();
        void push(int addData);
        void pop();
        void peek();
        void printList();
};
