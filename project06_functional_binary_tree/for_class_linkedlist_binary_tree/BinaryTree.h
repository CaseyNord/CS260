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

//class node; <-- I get a "not a valid data type" error when trying to compile the recursive functions with node* return values without this...

// Doesn't really seem to matter though, because I can't figure out the error I get when the data type error is corrected...

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
        //node* deleteData(node *branch, T value);
        void deleteData(node *branch, T value);
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

    if (root != NULL)
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


// Why can I not complile this recursive (and much simpler) delete!
/*
template <class T>
node* BinaryTree<T>::deleteData(node *branch, T value)
{
    // If tree is empty there is nothing to delete!
    if (branch != NULL)
    {
        // Is data to be deleted less than the current node's value?
        if (value < branch->data)
        {
            branch->left = deleteData(branch->left, value);
        }
        // Is data to be deleted greater than the current node's value?
        else if (value > branch->data)
        {
            branch->right = deleteData(branch->right, value);
        }
        // Is the value to be deleted equal to the current node?
        else
        {
            // Does this node have two children?
            if (branch->left && branch->right != NULL)
            {
                // Find successor
                node *currentNode = branch->right;
                while(currentNode->left != NULL)
                {
                    currentNode = currentNode->left;
                }
                node *tempNode = currentNode;
        
                // Copy the inorder successor's content to this node
                branch->data = tempNode->data;
        
                // Delete the inorder successor
                branch->right = deleteNode(branch->right, tempNode->data);
                return tempNode;
            }
            // Is there only a value in the left child?
            else if (branch->left == NULL)
            {
                node *tempNode = branch->right;
                free(branch);
                return tempNode;
            }
            // Is there only a value in the right child?
            else
            {
                node *tempNode = branch->left;
                free(branch);
                return tempNode;
            }
        }
    }
}
*/

template <class T>
void BinaryTree<T>::deleteData(node *branch, T value)
{ 
	node *previousNode = root;
	node *currentNode = root;

    // Search through the tree to find if the desired data is
    while (currentNode != NULL && currentNode->data != value)
	{
        previousNode = currentNode;
        if (value < currentNode->data)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    if (currentNode != NULL)
    {
        // Does the node to delete have no children?
        if(currentNode->left == NULL && currentNode->right == NULL)
        {
            // Is the node to delete a left child?
            if(previousNode->left == currentNode)
            {
                previousNode->left = NULL;
            }
            // Is the node to delete a right child?
            else
            {
                previousNode->right = NULL;
            }
            delete currentNode;
            cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
        }
        // Does the node to delete only have one child?
        else if ((currentNode->left == NULL && currentNode->right != NULL) || (currentNode->left != NULL && currentNode->right == NULL))
        {
            // Is that child on the right?
            if (currentNode->left == NULL && currentNode->right != NULL)
            {
                // Is this node a left child?
                if (previousNode->left == currentNode)
                {
                    // If so than this node's sole right child becomes the new parent to this node
                    // And this node gets deleted
                    previousNode->left = currentNode->right;
                    delete currentNode;
                    currentNode = NULL;
                    cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
                }
                // Is this node a right child?
                else
                {
                    // If so than this node's sole right child becomes the new parent to this node
                    // And this node gets deleted
                    previousNode->right = currentNode->right;
                    delete currentNode;
                    currentNode = NULL;
                    cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
                }
            }
            else // Is that child on the left?
            {
                if(previousNode->left == currentNode)
                {
                    // If so than this node's sole left child becomes the new parent to this node
                    // And this node gets deleted
                    previousNode->left = currentNode->left;
                    delete currentNode;
                    currentNode = NULL;
                    cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
                }
                else
                {
                    // If so than this node's sole left child becomes the new parent to this node
                    // And this node gets deleted
                    previousNode->right = currentNode->left;
                    delete currentNode;
                    currentNode = NULL;
                    cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
                }
            }
        }
        // The node to delete must have two children
        // We must replace deleted node with smallest value in right subtree
        else
        {
            // Does the node to delete's right child have no children?
            node* tempNode = currentNode->right;
            if((currentNode->left == NULL) && (currentNode->right == NULL))
            {
                currentNode = tempNode;
                delete tempNode;
                cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
            }
            // The node to delete's right node has children...
            else
            {
                // Does the node to delete's right child have a left child?
                if(currentNode->right->left != NULL)
                {
                    node* subCurrentNode;
                    node* subPreviousNode;
                    subPreviousNode = currentNode->right;
                    subCurrentNode = currentNode->right->left;

                    // Keep moving down until smalled element is found
                    while(subCurrentNode->left != NULL)
                    {
                        subPreviousNode = subCurrentNode;
                        subCurrentNode = subCurrentNode->left;
                    }
                    currentNode->data = subCurrentNode->data;
                    delete subCurrentNode;
                    subPreviousNode->left = NULL;
                    cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
                }
                else
                {
                    tempNode = currentNode->right;
                    currentNode->data = tempNode->data;
                    currentNode->right = tempNode->right;
                    delete tempNode;
                    cout << "The value " << value << " has been removed from the Tree!" << endl << endl;
                }
            }
		}
	}
    else
    {
        cout << "The value " << value << " is not in the tree!" << endl << endl;
    }
}

template <class T>
void BinaryTree<T>::printTree(node *branch)
{
    // Don't print if there is no tree!
    if (branch != NULL)
    {
        printTree(branch->left);
        cout << branch->data << endl;
        printTree(branch->right);
    }
}