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
        void deleteNode(int deleteData);
        void sort();
        void printList();
};
