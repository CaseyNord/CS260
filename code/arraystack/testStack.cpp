#include <cstdlib>
#include <iostream>
#include "ArrayStack.h"

using namespace std;


int main()
{
    ArrayStack myStack;

    // empty stack test
    myStack.pop();

    myStack.push(3);
    myStack.push(5);
    myStack.push(7);
    myStack.push(9);
    myStack.push(11);
    myStack.printList();

    cout << myStack.peek() << endl;

    myStack.push(13);
    myStack.printList();

    myStack.pop();
    myStack.printList();

    myStack.pop();
    cout << myStack.peek() << endl;

    myStack.push(15);
    cout << myStack.peek() << endl;

    myStack.push(20);
    myStack.printList();

    // full stack test
    myStack.push(2);
    myStack.push(140);
    myStack.push(24);
    myStack.push(87);
    myStack.push(21);
    myStack.printList();  

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.printList();    

    return 0;
}