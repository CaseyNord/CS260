#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Graph.h"

using std::cout;
using std::endl;


Graph::Graph()
{

}

void Graph::addNode(int newData)
{
    // Create new node
    graphNode *newNode = new graphNode;
    newNode->data = newData;

    //Place node
    nodeList.push_back(newNode);
}

void Graph::addEdge(int sourceLabel, int destinationLabel, int weight)
{
    graphNode *sourceNode = nodeList[sourceLabel];
    graphNode *destinationNode = nodeList[destinationLabel];
    graphEdge *newGraphEdge = new graphEdge;
    newGraphEdge->destination = destinationNode;
    newGraphEdge->weight = weight;
    sourceNode->adjacency.push_back(newGraphEdge);
}

std::string Graph::toString()
{
    std::string result = "";
    graphNode *currentNode;

    for(unsigned int i = 0; i < nodeList.size(); i++)
    {
        currentNode = nodeList[i];
        result += currentNode->data;
        result += " -> ";
        
        for(unsigned int j = 0; j < currentNode->adjacency.size(); j++)
        {
            result += "(";
            result += currentNode->adjacency[j]->destination->data;
            result += ", ";
            std::stringstream ss;
            ss << currentNode->adjacency[j]->weight;
            result += ss.str();
            result += ")";
            result += ",";
        }
        result += "\n";
    }

    return result;
}

/*
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
*/