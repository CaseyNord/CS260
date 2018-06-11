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

    cout << myGraph.toString() << endl;

    myGraph.dijkstra(0);
    cout << endl;
    myGraph.dijkstra(1);
    cout << endl;
    myGraph.dijkstra(2);
    cout << endl;
    myGraph.dijkstra(3);
    cout << endl;
    myGraph.dijkstra(4);
    cout << endl;
    myGraph.dijkstra(5);
    cout << endl;
    myGraph.dijkstra(6);
    cout << endl;
    myGraph.dijkstra(7);
    cout << endl;
    myGraph.dijkstra(8);  

    return 0;
}

