
class ArrayStack
{
    const int MAX_STACK_SIZE = 10;

    int topIndex;
    int myStack[MAX_STACK_SIZE];

    public:
        int peek()
        {
            return myStack[topIndex]; 
        }

        int pop()
        {
            int value = myStack[topIndex];
            myStack[topIndex] = 0;
            topIndex--;
            return value;
        }

        void push(int newValue)
        {
            topIndex++;
            myStack[topIndex] = newValue;
        }
};