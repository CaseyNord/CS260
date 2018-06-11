#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits.h>

#include "Graph.h"

#define INFINITY INT_MAX

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

int Graph::nextVertex(int distance[], bool shortestPathTreeSet[])
{
    /*
    
     This may seem confusing, but minimum gets set to INT_MAX as a
     sort of placeholder for what we would consider INFINITY as
     part of the algorithm

     It makes sense if you trace what the algorithm is actually doing :)

     */
    int minimum = INFINITY;
    int nextIndex;

    for (unsigned int i = 0; i < nodeList.size(); i++)
    {
        if (shortestPathTreeSet[i] == false && distance[i] <= minimum)
        {
            minimum = distance[i];
            nextIndex = i;
        }
    }

    return nextIndex;
}

void Graph::printMinimumDistance(int distance[], int node)
{
    cout << "Vertex     Distance from node " << node << endl;
    for (unsigned int i = 0; i < nodeList.size(); i++)
    {
        cout << i << "          " << distance[i] << endl;
    }
}

void Graph::dijkstra(int source)
{
    /*

    The distance array references each node based on its index
    The value contained in the index representa the distance from the source

    The shortestPathTreeSet array is used to keep track of what vertexes have
    been added to the graph

    */

    int distance[nodeList.size()];
    bool shortestPathTreeSet[nodeList.size()];
    
    // Initialize distances as "infinite" and shortestPathTreeSet to false
    for (unsigned int i = 0; i < nodeList.size(); i++)
    {
        distance[i] = INFINITY;
        shortestPathTreeSet[i] = false;
    }

    // We know the distance from source to itself is always 0
    distance[source] = 0;

    graphNode *currentNode;
    // Find all shortest paths from source to other nodes
    for (unsigned int i = 0; i < nodeList.size() - 1; i++)
    {
        // Find next vertex with minimum distance
        int currentVertex = nextVertex(distance, shortestPathTreeSet);
        currentNode = nodeList[currentVertex];

        // Mark it as included
        shortestPathTreeSet[currentVertex] = true;

        // Update distance values of adjacent vertices
        for(unsigned int j = 0; j < currentNode->adjacency.size(); j++)
        {
            // Pointercentric way of locating the node name (value) that corresponds to our array indexes
            int adjacentNode = currentNode->adjacency[j]->destination->data;
            if(!shortestPathTreeSet[adjacentNode] && // Has the adjacent node been assigned a shortest path?
                distance[currentVertex] != INFINITY && // If not then does the current vertex have a shortest path?
                distance[currentVertex] + currentNode->adjacency[j]->weight < distance[adjacentNode]) // Is the new proposed path shorter than the current one?
            {
                // If so then update it!
                distance[adjacentNode] = distance[currentVertex] + currentNode->adjacency[j]->weight;
            }
        }
    }

    printMinimumDistance(distance, source);
}

std::string Graph::toString()
{
    std::string result = "";
    std::stringstream ss;
    graphNode *currentNode;

    for(unsigned int i = 0; i < nodeList.size(); i++)
    {
        currentNode = nodeList[i];
        ss << currentNode->data;
        result += ss.str();
        ss.str(std::string());
        result += " -> ";
        
        for(unsigned int j = 0; j < currentNode->adjacency.size(); j++)
        {
            result += "(";
            ss << currentNode->adjacency[j]->destination->data;
            result += ss.str();
            ss.str(std::string());
            result += ", ";
            ss << currentNode->adjacency[j]->weight;
            result += ss.str();
            ss.str(std::string());
            result += ")";
            result += ",";
        }
        result += "\n";
    }

    return result;
}