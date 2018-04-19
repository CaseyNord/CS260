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
