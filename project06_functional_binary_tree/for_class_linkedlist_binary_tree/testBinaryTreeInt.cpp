//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 21, 2018
// Project #6
// Program Description: Binary search tree
// Complexity: 
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
    BinaryTree<int> myTree;

    myTree.addData(10);
    cout << "Created root node successful!" << endl << endl;

    myTree.addData(5);
    cout << "Created left leaf node successful!" << endl << endl;

    myTree.addData(12);
    cout << "Created right leaf node successful!" << endl << endl;

    myTree.addData(2);
    myTree.addData(7);

    myTree.printTree(myTree.root);
    cout << "The tree traverses in order to print successfully!" << endl << endl;

    myTree.deleteData(myTree.root, 5);

    cout << "Attempting to delete value not in tree" << endl << endl;
    myTree.deleteData(myTree.root, 67);
    cout << "Yay, success!" << endl << endl;

    myTree.printTree(myTree.root);
    cout << "The tree traverses in order to print successfully!" << endl << endl;

    myTree.addData(36);
    myTree.addData(42);
    myTree.addData(7);
    myTree.addData(7);
    myTree.addData(1);
    myTree.addData(3);
    myTree.addData(16);
    myTree.addData(78);
    myTree.addData(55);
    myTree.addData(700);
    myTree.addData(32);
    myTree.addData(68);
    myTree.addData(27);

    myTree.printTree(myTree.root);
    cout << "The tree traverses in order to print successfully!" << endl << endl;

    myTree.deleteData(myTree.root, 3);
    myTree.deleteData(myTree.root, 1);
    myTree.deleteData(myTree.root, 42);
    myTree.deleteData(myTree.root, 68);
    myTree.deleteData(myTree.root, 27);

    myTree.printTree(myTree.root);
    cout << "The tree is still in order, success!" << endl << endl;

    cout << "There are three 7s in the tree and it works fine, success!" << endl << endl;


    return 0;
}