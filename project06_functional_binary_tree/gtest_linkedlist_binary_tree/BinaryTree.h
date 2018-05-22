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
        void addData(T value);
        void deleteData(T value);
        void printTree(node *branch);
};


template <class T>
BinaryTree<T>::BinaryTree()
{
    root = new node;
    root = NULL;
}

template <class T>
void BinaryTree<T>::addData(T value)
{
    node *newNode = new node;
    newNode->data = value;
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
void BinaryTree<T>::deleteData(T value)
{
    node *deletePtr = NULL; // O(1)
    node *currentNode = root; // O(1)
    node *previousNode = root; // O(1)

    // Travel through the list and check for the data we want to delete
    while(currentNode != NULL && currentNode->data != value) // O(n)
    {
        if (value < currentNode->data)
        {
            // Search left side of tree
            if(currentNode->left != NULL)
            {
                currentNode = currentNode->left;
            }
        }
        else
        {
            // Search right side of tree
            if(currentNode->right != NULL)
            {
                currentNode = currentNode->right;
            }
        }
    }
    
    // If we reach the end the item must not exist in the list
    if(currentNode == NULL) // O(1)
    {
        cout << value << " was not in the list" << endl; // O(1)
    }
    else
    {
        // The item is found and deleted
        deletePtr = currentNode; // O(1)
        /*
        currentNode = currentNode->next; // O(1)
        previousNode->next = currentNode; // O(1)
        if(deletePtr == root) // O(1)
        {
            // Delete root node
        }
        */
        delete deletePtr; // O(1)  <-- garbage collection
        deletePtr->left = NULL;
        deletePtr->right = NULL;
        cout << "The value " << value << " was deleted" << endl; // O(1)
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