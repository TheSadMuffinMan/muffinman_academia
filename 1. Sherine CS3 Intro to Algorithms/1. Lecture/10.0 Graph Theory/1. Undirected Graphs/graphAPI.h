#pragma once
#include <iostream>
#include <fstream>

// template <class T>
class Graph
{
    public:
        Graph(int);
        Graph(std::ifstream&);

        void addEdge(int, int);

        int adjacent(int);
        int numVertices();
        int numEdges();
    
    private:
        //
};

// Function creates an empty graph with V vertices.
Graph::Graph(int numV)
{
    //
}

// Function creates a directed graph from input stream.
Graph::Graph(std::ifstream& inputStream)
{
    //
}

// Function adds an edge, v --- w.
void Graph::addEdge(int v, int w)
{
    //
}

// Function returns the number of vertices pointing from "vertices"/v.
int Graph::adjacent(int vertices)
{
    //
}

// Function returns the number of vertices.
int Graph::numVertices()
{
    //
}

// Function returns the number of edges.
int Graph::numEdges()
{
    //
}