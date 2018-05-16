//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 14, 2018
// Project #5
// Program Description: Hand-built binary tree
// Complexity: Linear - O(n)
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
    BinaryTree<int> root;//, branchLeft, branchRight, LbranchLeft, LbranchRight, RbranchLeft, RbranchRight, LLbranchLeft;

    root.setData(42);
    //root.left = &branchLeft;
    //root.right = &branchRight;

    /*
    branchLeft = 21;
    branchLeft.left = &LbranchLeft;
    branchLeft.right = &LbranchRight;

    branchRight = 89;
    branchRight.left = &RbranchLeft;
    branchRight.right = &RbranchRight;

    LbranchLeft = 10;
    LbranchLeft.left = &LLbranchLeft;

    LbranchRight = 30;

    RbranchLeft = 60;
    
    RbranchRight = 100;

    LLbranchLeft = 5;\
    */

    cout << "Root: " << root.getData() << endl;
    //root.printData();

    return 0;
}