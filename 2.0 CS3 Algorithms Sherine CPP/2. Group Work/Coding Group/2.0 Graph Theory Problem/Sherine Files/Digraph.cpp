/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

#pragma once
#include "Digraph.h"

// Constructor
Digraph::Digraph(int V) : _numVertices(_numVertices), _numEdges(0)
{
    _adj = new SelfResizingArray<int>[V]; // Create an array of SelfResizingArrays
}

// Destructor
Digraph::~Digraph()
{
    delete[] _adj;
}

// Add a directed edge from vertex v to vertex w
void Digraph::addEdge(int v, int w)
{
    _adj[v].add(w);
    _numEdges++;
}

// Return the adjacency list for vertex v
const SelfResizingArray<int>& Digraph::getAdj(int v) const
{
    return _adj[v];
}

// Return the number of vertices
int Digraph::getVertices() const
{
    return _numVertices;
}
