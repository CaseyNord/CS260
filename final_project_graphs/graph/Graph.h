//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: June 12, 2018
// Final Project
// Program Description: Graph
//*****************************************************************
#include <vector>

/*

 These structs need to be declared outside of the class in order 
 for the program to compile correctly. This essentially works
 the same as declaring these in seperate cpp files.

 What is the best practice?

 */

struct graphEdge {
    struct graphNode *destination;
    int weight;
};

struct graphNode {
    int data;
    std::vector<graphEdge *> adjacency;
};


class Graph
{
        graphNode current;
        std::vector<graphNode *> nodeList; // Master list

    public:
        Graph();
        void addNode(int newData);
        void addEdge(int sourceLabel, int destinationLabel, int weight);
        int nextVertex(int distance[], bool shortestPathTreeSet[]);
        void printMinimumDistance(int distance[], int node);
        void dijkstra(int source);
        std::string toString();
};
