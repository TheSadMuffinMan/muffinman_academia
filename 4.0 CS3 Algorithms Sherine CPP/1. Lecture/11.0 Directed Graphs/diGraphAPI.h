#pragma once
#include <iostream>
#include <fstream>
#include <vector> // MUST REMOVE FOR RESIZING ARRAYS LATER.

// template <class T>
class DirectedGraph
{
    public:
        DirectedGraph(int);
        DirectedGraph(std::ifstream&);

        // void addEdge(<class T>, <class T>)
        void addEdge(int, int);

        int adjacent(int);
        int numVertices();
        int numEdges();

        DirectedGraph reverse();
        std::string toString();
    
    private:
        //
};

// Function creates an empty directed graph with "numVertices"/V vertices.
DirectedGraph::DirectedGraph(int numVertices)
{
    //
}

// Function creates a directed graph from input stream.
DirectedGraph::DirectedGraph(std::ifstream& inputStream)
{
    //
}

// Function adds a directed edge, v ---> w.
void DirectedGraph::addEdge(int v, int w)
{
    //
}

// Function returns the number of vertices pointing from "vertices"/v.
int DirectedGraph::adjacent(int vertices)
{
    //
}

// Function returns the number of vertices.
int DirectedGraph::numVertices()
{
    //
}

// Function returns the number of edges.
int DirectedGraph::numEdges()
{
    //
}



/*
int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
*/