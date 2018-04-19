#include <cstdlib>

#include "LinkedStack.h"

using namespace std;


int main(int argc, char** argv)
{
    LinkedStack myStack;

    myStack.push(3);
    myStack.push(5);
    myStack.push(7);
    myStack.push(9);
    myStack.push(11);

    //myStack.peek();

    myStack.push(13);
    myStack.printList();

    myStack.pop();
    myStack.printList();

    myStack.pop();
    myStack.peek();

    myStack.push(15);
    myStack.peek();

    myStack.push(20);
    myStack.printList();

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.printList();

    return 0;
}