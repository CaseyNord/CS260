//*****************************************************************
// Name: Casey Nord
// Class: CS260 Spring 2018
// Class Time: Mon/Wed/Fri 8:00am
// Date: June 12, 2018
// Final Project
// Program Description: Graph
//*****************************************************************
#include <vector>

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
    /*
        struct graphNode {
            int data;
            std::vector<graphEdge *> adjacency;
        };

        struct graphEdge {
            struct graphNode *destination;
            int weight;
        };
    */

        graphNode current;
        std::vector<graphNode *> nodeList; // Master list

    public:
        Graph();
        void addNode(int newData);
        void addEdge(int sourceLabel, int destinationLabel, int weight);
        std::string toString();
};
