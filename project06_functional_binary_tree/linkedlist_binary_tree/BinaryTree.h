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

    public:
         node *root;

        BinaryTree();
        void AddData(T addData);
        void printTree(node *branch);
        //void setData(T addData);
        //int getData();
};


template <class T>
BinaryTree<T>::BinaryTree()
{
    root = new node;
    root = NULL;
}

template <class T>
void BinaryTree<T>::AddData(T addData)
{
    node *newNode = new node;
    newNode->data = addData;
    newNode->left = NULL;
    newNode->right = NULL;
    node *currentNode = root;
    bool loop = true;

    if(root != NULL)
    {
        while (loop == true)
        {
            // Is the value I am trying to add bigger or smaller than the current value?
            if(newNode->data < currentNode->data) // O(1)
            {
                if(currentNode->left != NULL)
                {
                    // Search left half of tree
                    currentNode = currentNode->left;
                }
                else
                {
                    currentNode->left = newNode;
                    loop = false;
                }
            }
            else
            {
                if(currentNode->right != NULL)
                {
                    // Search right half of tree
                    currentNode = currentNode->right;
                }
                else
                {
                    currentNode->right = newNode;
                    loop = false;
                }
            }
        }
    }
    else // Root must be empty!
    {
        root = newNode;
    }
}

template <class T>
void BinaryTree<T>::printTree(node *branch)
{
    // Don't print if there is no tree!
    if (!branch) return;

    cout << branch->data << endl;

    printTree(branch->left);
    printTree(branch->right);
}

/*
template <class T>
void BinaryTree<T>::setData(T addData)
{
    leaf->data = addData;
}
*/

/*
template <class T>
int BinaryTree<T>::getData()
{
    return leaf->data;
}
*/

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