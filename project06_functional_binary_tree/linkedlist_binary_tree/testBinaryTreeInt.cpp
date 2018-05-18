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

    myTree.AddData(10);
    cout << "Created root node successful!" << endl;

    myTree.AddData(5);
    cout << "Created left leaf node successful!" << endl;

    myTree.AddData(12);
    cout << "Created right leaf node successful!" << endl;

    myTree.AddData(14);
    myTree.AddData(32);

    myTree.printTree(myTree.root);

    return 0;
}