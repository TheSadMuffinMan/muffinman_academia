#pragma once
#include <iostream>
#include <fstream>
#include <vector>

// template <class T>
class Graph
{
    public:
        Graph(int);
        Graph(std::ifstream&);

        void addEdge(int, int);
        std::vector<int>& getAdjacent(int);

        int numAdjacent(int);
        int numVertices();
        int numEdges();
        int degree(const Graph&, int);
    
    private:
        int _V; // Number of vertices.
        std::vector<std::vector<int>> _adjacent; // Using a "bag" data type.
};

// Function creates an empty graph with V vertices.
Graph::Graph(int numV)
{
    _V = numV;
    // _adjacent = numV;

    // Creating an empty Graph with V vertices.
    for (int i = 0; i < _V; i++)
    {
        _adjacent[i] = std::vector<int>();
    }
}

// Function creates a directed graph from input stream.
Graph::Graph(std::ifstream& inputStream)
{
    //
}

// Function adds an edge, v --- w.
// NOTE: Parallel edges and self-loops allowed!
void Graph::addEdge(int v, int w)
{
    _adjacent[v].push_back(w);
    _adjacent[w].push_back(v);
}

std::vector<int>& Graph::getAdjacent(int v)
{
    return _adjacent[v];
}


// Function returns the number of vertices pointing from "vertices"/v.
int Graph::numAdjacent(int vertice)
{
    int
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

// Function returns the degree of vertex v inside Graph G.
int Graph::degree(const Graph& G, int v)
{
    int degree = 0;
    for (int w : G.adjacent(v))
    {
        degree++;
    }

    return degree;
}