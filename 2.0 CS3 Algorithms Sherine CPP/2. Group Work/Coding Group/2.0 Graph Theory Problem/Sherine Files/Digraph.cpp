//
//  Digraph.cpp
//  ShortestPaths
//
//  Created by Antoun, Sherine on 10/25/24.
//

#include "Digraph.h"

// Constructor
Digraph::Digraph(int V) : V(V), E(0) {
    adj = new SelfResizingArray<int>[V]; // Create an array of SelfResizingArrays
}

// Destructor
Digraph::~Digraph() {
    delete[] adj;
}

// Add a directed edge from vertex v to vertex w
void Digraph::addEdge(int v, int w) {
    adj[v].add(w);
    E++;
}

// Return the adjacency list for vertex v
const SelfResizingArray<int>& Digraph::getAdj(int v) const {
    return adj[v];
}

// Return the number of vertices
int Digraph::getVertices() const {
    return V;
}
