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
