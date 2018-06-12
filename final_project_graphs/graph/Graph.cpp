//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: June 12, 2018
// Final Project
// Program Description: Graph
// Complexity: O(n^2)
//*****************************************************************

/*

Ideally, the complexity of a graph using an algorithn like dijkstra
can achieve O(xlogn), where x is dependent on the number of graph
connections for each node.

A true O(n^2) complexity assumes that each node contains a full list
of potential adjacent nodes where the size of the list is the total
number of items in the graph.

A graph represented as a multidimensional array (like the one in the
example I used for this project
https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/)
would have this complexity.

Our implementation using dynamic vector arrays that are sized only to
the number of actual adjacent nodes drasitcally reduces this complexity.

Because the graph in this example with the most adjacent connections is
4, I believe that the most expensive operation would be closer to 
O(4logn), if I understand this correctly.

This works because as each shortest connection is found, the subsequent
searches through each node only have to look at the actual adjacent
connections to that node, and in this example there is no node that
would require more than 4 searches to find its shortest path.

At the end of the day, however, I've been under the impression that
we rate our algorithms based on the worst case scenario.  Although this
specific example works pretty well, there is still the posiblity with
the overall design of this data structure to degrade to a complexity of
O(n^2). That being said, it seems to work well enough that a situation
like that would actually be fairly rare and that in general we can expect
a pretty good runtime!

Maybe I should have updated the complexity of this specific example to O(4logn).

Please let me know if I'm undertanding this well or if there is something I am missing!

*/

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

void Graph::printMinimumDistance(int *distance, int node)
{
    cout << "Vertex     Distance from node " << node << endl;
    for (unsigned int i = 0; i < nodeList.size(); i++)
    {
        cout << i << "          " << distance[i] << endl;
    }
    cout << endl;
}

void Graph::printShortestPath(int *distance, int startNode, int endNode)
{
    int shortestDistance = distance[endNode];
    cout << "Shortest path from " << startNode << " to " << endNode << " is " << shortestDistance << endl << endl;
}

int *Graph::dijkstra(int source)
{
    /*

    The distance array references each node based on its index
    The value contained in the index representa the distance from the source

    The shortestPathTreeSet array is used to keep track of what vertexes have
    been added to the graph

    */

    static int distance[9]; // <-- I HAVE A MAGIC NUMBER HERE! IS THERE A WAY TO ALLOCATE THIS SO
                            //     THAT IT CAN BE PASSED TO ANOTHER FUNCTION WITHOUT SEG FAULTING?
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
    return distance;
}

void Graph::minSpanningTree(int source)
{
    int *tree = new int[nodeList.size()];
    tree = dijkstra(source);
    printMinimumDistance(tree, source);
}

void Graph::shortestPath(int source, int destination)
{
    int *tree = new int[nodeList.size()];
    tree = dijkstra(source);
    printShortestPath(tree, source, destination);
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