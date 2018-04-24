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
