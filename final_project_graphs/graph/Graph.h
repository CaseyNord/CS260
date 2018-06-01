//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: June 12, 2018
// Final Project
// Program Description: Graph
//*****************************************************************
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


template <class T>
class Graph
{
    private:
        struct graphNode {
            T data;
            graphNode *adjacency[];
        };

    public:
        Graph();
        void printGraph();
};


template <class T>
Graph<T>::Graph()
{

}

template <class T>
void Graph<T>::printGraph()
{
    for (int i = 0; i < capacity; i++)
    {
        if (hashTable[i] != "")
        {
            cout << hashTable[i] << endl;
        }
    }
    cout << endl;
}

