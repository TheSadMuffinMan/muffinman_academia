//
//  Digraph.hpp
//  ShortestPaths
//
//  Created by Antoun, Sherine on 10/25/24.
//

#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "SelfResizingArray.h"

class Digraph {
private:
    int V; // Number of vertices
    int E; // Number of edges
    SelfResizingArray<int>* adj; // Array of adjacency lists

public:
    Digraph(int V);
    ~Digraph();
    void addEdge(int v, int w);
    const SelfResizingArray<int>& getAdj(int v) const;
    int getVertices() const;
};

#endif // DIGRAPH_H
