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
    private:
        struct node{
            T data;
            node *left;
            node *right;
        };

        node *leaf;

    public:
        BinaryTree();
        void setData(T addData);
        int getData();
        //void printData();
};


template <class T>
BinaryTree<T>::BinaryTree()
{
    leaf = new node;
    //leaf = NULL;
}

template <class T>
void BinaryTree<T>::setData(T addData)
{
    leaf->data = addData;
}

template <class T>
int BinaryTree<T>::getData()
{
    return leaf->data;
}

/*
template <class T>
void BinaryTree<T>::printData()
{
    cout << leaf->data << endl;
}
*/

/*
template <class T>
void BinaryTree<T>::setChild()
*/