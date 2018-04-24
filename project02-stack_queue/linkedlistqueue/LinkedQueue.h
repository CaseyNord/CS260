//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: April 23, 2018
// Project #2
// Driver Name: testQueue.cpp
// Program Description: Queue implementation with linked list
//*****************************************************************
class LinkedQueue
{
    private:
        struct node{
            int data;
            node *next;
        };

        node *head;
        node *tail;

    public:
        LinkedQueue();
        void add(int addData);
        void remove();
        void printList();
};
