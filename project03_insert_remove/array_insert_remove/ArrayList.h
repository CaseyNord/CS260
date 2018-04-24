class ArrayList
{
    private:
        int myStack[10];
        int topIndex;

    public:
        ArrayList();
        void addItem(int newValue);
        void insertItem(int addData, int listIndex);
        void deleteItem(int deleteData);
        void printList();
};