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
#include <fstream>

#include "Graph.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::string;


int main(int argc, char** argv)
{
    Graph myGraph;

    // Create the nine nodes of our graph
    myGraph.addNode(0);
    myGraph.addNode(1);
    myGraph.addNode(2);
    myGraph.addNode(3);
    myGraph.addNode(4);
    myGraph.addNode(5);
    myGraph.addNode(6);
    myGraph.addNode(7);
    myGraph.addNode(8);

    // Create edges:
    // Node 0
    myGraph.addEdge(0, 1, 4);
    myGraph.addEdge(0, 7, 8);
    // Node 1
    myGraph.addEdge(1, 0, 4);
    myGraph.addEdge(1, 2, 8);
    myGraph.addEdge(1, 7, 11);
    // Node 2
    myGraph.addEdge(2, 1, 8);
    myGraph.addEdge(2, 3, 7);
    myGraph.addEdge(2, 5, 4);
    myGraph.addEdge(2, 8, 2);
    // Node 3
    myGraph.addEdge(3, 2, 7);
    myGraph.addEdge(3, 4, 9);
    myGraph.addEdge(3, 5, 14);
    // Node 4
    myGraph.addEdge(4, 3, 9);
    myGraph.addEdge(4, 5, 10);
    // Node 5
    myGraph.addEdge(5, 2, 4);
    myGraph.addEdge(5, 3, 14);
    myGraph.addEdge(5, 4, 10);
    myGraph.addEdge(5, 6, 2);
    // Node 6
    myGraph.addEdge(6, 5, 2);
    myGraph.addEdge(6, 7, 1);
    myGraph.addEdge(6, 8, 6);
    // Node 7
    myGraph.addEdge(7, 0, 8);
    myGraph.addEdge(7, 1, 11);
    myGraph.addEdge(7, 6, 1);
    myGraph.addEdge(7, 8, 7);
    // Node 8
    myGraph.addEdge(8, 2, 2);
    myGraph.addEdge(8, 6, 6);
    myGraph.addEdge(8, 7, 7);

    cout << "Here is the layout of our graph, please refer to the" << endl;
    cout << "picture included with submission for a more detailed view:" << endl << endl;
    cout << myGraph.toString() << endl;

    cout << "Minimum spanning tree starting from vertex 0:" << endl << endl;
    myGraph.minSpanningTree(0);

    myGraph.shortestPath(0, 1);
    myGraph.shortestPath(0, 4);
    myGraph.shortestPath(0, 8);

    /*
    myGraph.minSpanningTree(1);
    myGraph.minSpanningTree(2);
    myGraph.minSpanningTree(3);
    myGraph.minSpanningTree(4);
    myGraph.minSpanningTree(5);
    myGraph.minSpanningTree(6);
    myGraph.minSpanningTree(7);
    myGraph.minSpanningTree(8);
    */

    return 0;
}

