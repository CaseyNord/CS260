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

        node *root;

        int nodes; // Amount of individual nodes in the tree - (n)
        int depth; // Number of levels in the tree - (k)

    public:
        BinaryTree();
        void addNode(T addData);
        void deleteNode(T deleteData);
        void printList();

        /*

        methods:
        insert()
        delete()
        search()
        deleteSubtree() 

        */
};


template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template <class T>
void BinaryTree<T>::addNode(T addData)
{
    node *newNode = new node;
    newNode->data = addData;
    newNode->next = NULL;
    node *currentNode = root;
    node *previousNode = root;

    if(root != NULL)
    {
        // Is current root larger than the value I am trying to add?
        if(root->data > newNode->data)
        {
            // If so newValue becomes root
            newNode->next = root;
            root = newNode;
        }
        else
        {
            // Travel through the list
            while (currentNode != NULL)
            {
                // Is the value I am trying to add less then the value we are looking at?
                if(newNode->data < currentNode->data)
                {
                    // If so place it before that value
                    newNode->next = previousNode->next;
                    previousNode->next = newNode;
                    return;
                }
                else
                {
                    // If not keep travelling through the list
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }
            }
            // If we reach the end this new item must be bigger than any other
            // It becomes the new tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    else
    {
        root = newNode;
        tail = newNode;
    }
}

/*

while (testNode != NULL)
{
    if (currentNode >= newNode)
    {
        if (currentNode->left != NULL)
        {
            currentNode = currentNode->left;
            PREVIOUS NODE STUFF?
        }
        else
        {
            newNode = currentNode->left;
        }
    }
    else if (currentNode <= newNode)
    {
        if (currentNode->right != NULL)
        {
            currentNode = currentNode->right;
            PREVIOUS NODE STUFF?
        }
        else
        {
            newNode = currentNode->right;
        }
    }
}

*/

template <class T>
void BinaryTree<T>::deleteNode(T deleteData)
{
    node *deletePtr = NULL;
    node *currentNode = root;
    node *previousNode = root;

    // Travel through the list and check for the data we want to delete
    while(currentNode != NULL && currentNode->data != deleteData)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    // If we reach the end the item must not exist in the list
    if(currentNode == NULL)
    {
        cout << deleteData << " was not in the list" << endl;
    }
    else
    {
        // The item is found and deleted
        deletePtr = currentNode;
        currentNode = currentNode->next;
        previousNode->next = currentNode;
        if(deletePtr == root)
        {
            root = root->next;
            previousNode = NULL;
        }
        delete deletePtr;   <-- garbage collection
        cout << "The value " << deleteData << " was deleted" << endl;
    }
}

template <class T>
void BinaryTree<T>::printList()
{
    node *printNode = new node;
    printNode = root;
    while(printNode != NULL)
    {
        cout << printNode->data << endl;
        printNode = printNode->next;
    }
}