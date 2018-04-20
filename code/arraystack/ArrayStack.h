/*

Trying to include an const int or int value
for MAX causes strange issues with the compilation
and output of this program.

*/

class ArrayStack
{
    private:
        int myStack[10];
        int topIndex;

    public:
        ArrayStack();
        void push(int newValue);
        int pop();
        int peek();
        void printList();
};