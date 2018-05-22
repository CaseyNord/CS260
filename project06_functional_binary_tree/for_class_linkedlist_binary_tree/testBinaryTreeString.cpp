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
using std::string;


int main(int argc, char** argv)
{
    BinaryTree<string> myTree;

    myTree.addData("hello");
    cout << "Created root node successful!" << endl << endl;

    myTree.addData("i");
    cout << "Created left leaf node successful!" << endl << endl;

    myTree.addData("hope");
    cout << "Created right leaf node successful!" << endl << endl;

    myTree.addData("this");
    myTree.addData("works");

    myTree.printTree(myTree.root);
    cout << "The tree traverses in order to print successfully!" << endl << endl;

    myTree.deleteData(myTree.root, "so");

    cout << "Attempting to delete value not in tree" << endl << endl;
    myTree.deleteData(myTree.root, "far");
    cout << "Yay, success!" << endl << endl;

    myTree.printTree(myTree.root);
    cout << "The tree traverses in order to print successfully!" << endl << endl;

    myTree.addData("i");
    myTree.addData("havent");
    myTree.addData("been");
    myTree.addData("able");
    myTree.addData("to");
    myTree.addData("get");
    myTree.addData("recursive");
    myTree.addData("methods");
    myTree.addData("to");
    myTree.addData("compile");
    myTree.addData("and");
    myTree.addData("im");
    myTree.addData("getting");
    myTree.addData("tired");

    myTree.printTree(myTree.root);
    cout << "The tree traverses in order to print successfully!" << endl << endl;

    myTree.deleteData(myTree.root, "recursive");
    myTree.deleteData(myTree.root, "havent");
    myTree.deleteData(myTree.root, "compile");
    myTree.deleteData(myTree.root, "i");
    myTree.deleteData(myTree.root, "getting");

    myTree.printTree(myTree.root);
    cout << "The tree is still in order, success!" << endl << endl;


    return 0;
}