//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: May 14, 2018
// Project #5
// Program Description: Hand-built binary tree
// Complexity: Constant :) - O(1)
//*****************************************************************
#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
    BinaryTree<int> root, branchLeft, branchRight, LbranchLeft, LbranchRight, RbranchLeft, RbranchRight, LLbranchLeft;

    root.data = 42;
    root.left = &branchLeft;
    root.right = &branchRight;

    branchLeft.data = 21;
    branchLeft.left = &LbranchLeft;
    branchLeft.right = &LbranchRight;

    branchRight.data = 89;
    branchRight.left = &RbranchLeft;
    branchRight.right = &RbranchRight;

    LbranchLeft.data = 10;
    LbranchLeft.left = &LLbranchLeft;

    LbranchRight.data = 30;

    RbranchLeft.data = 60;
    
    RbranchRight.data = 100;

    LLbranchLeft.data = 5;
    
    cout << "\t    --------" << root.data << "--------" << endl;
    cout << "\t----" << branchLeft.data << "----\t----" << branchRight.data << "----" <<endl;
    cout << "    ----" << LbranchLeft.data << "\t" << LbranchRight.data << "\t" << RbranchLeft.data << "\t" << RbranchRight.data << endl;
    cout << "    " << LLbranchLeft.data << endl;



    return 0;
}