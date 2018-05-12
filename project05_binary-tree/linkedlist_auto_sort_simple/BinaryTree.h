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

using std::cout;
using std::endl;


template <class T>
class BinaryTree 
{
    public:
        T data;
        BinaryTree <T> *left;
        BinaryTree <T> *right;

        BinaryTree();
};


template <class T>
BinaryTree<T>::BinaryTree()
{

}
