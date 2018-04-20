#include <cstdlib>

#include "LinkedQueue.h"

using namespace std;


int main(int argc, char** argv)
{
    LinkedQueue myQueue;

    myQueue.add(3);
    myQueue.add(5);
    myQueue.add(7);
    myQueue.add(9);
    myQueue.add(11);

    myQueue.printList();

    myQueue.remove();
    myQueue.printList();

    myQueue.add(20);
    myQueue.printList();

    myQueue.remove();
    myQueue.remove();
    myQueue.remove();
    myQueue.printList();

    return 0;
}