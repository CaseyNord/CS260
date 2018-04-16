#include <cstdlib>

#include "LinkedList.h"

using namespace std;


int main(int argc, char** argv)
{
    LinkedList myList;

    myList.addNode(3);
    myList.addNode(5);
    myList.addNode(7);
    myList.addNode(9);
    myList.addNode(11);

    myList.printList();
    
    myList.deleteNode(9);
    myList.printList();

    myList.deleteNode(1);
    myList.printList();

    myList.deleteNode(3);
    myList.printList();

    return 0;
}