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

//#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::string;

/*
struct graphNode {
    int data;
    std::vector<graphNode> adjacency;
};
*/


int main(int argc, char** argv)
{
    Graph myGraph;

    myGraph.addNode(65);

    myGraph.addNode(66);
    myGraph.addEdge(0, 1, 1);

    myGraph.addNode(67);
    myGraph.addEdge(0, 2, 5);

    myGraph.addEdge(1, 2, 10);

    cout << myGraph.toString() << endl;

/*
    graphNode node1;
    node1.data = 46;

    graphNode node2;
    node2.data = 97;
*/

/*
    graphNode root;
    for(int i = 0; i < 10; i++)
    {
        graphNode temp;
        temp.data = i;
        root.adjacency.push_back(temp);
    }

    for(int i = 0; i < root.adjacency.size(); i++)
    {
        cout << "root.adjacency[" << i << "].data: " << root.adjacency[i].data << endl;
    }

*/

/*
    node1.adjacency.push_back(node2);

    cout << "node1.data: " << node1.data << endl;
    cout << "node2.data: "<< node2.data << endl;

    cout << "node1.adjacency[0].data: " << node1.adjacency[0].data << endl; 
*/

/*
    // Using input stream to add a massive amount of entries to the table
    // First we declare an input file stream variable
    ifstream inFile;
    // Then we open the stream
    inFile.open("table_entries.txt");
    // Check is file was opened successfully
    if (!inFile)
    {
        cerr << "Unable to open file table_entries.txt" << endl << endl;
        exit(1); // Stop program
    }

    // Read the stream
    string x;
    while (inFile >> x)
    {
        myHash.addItem(x);
    }

    //close the stream
    inFile.close();
*/

    return 0;
}