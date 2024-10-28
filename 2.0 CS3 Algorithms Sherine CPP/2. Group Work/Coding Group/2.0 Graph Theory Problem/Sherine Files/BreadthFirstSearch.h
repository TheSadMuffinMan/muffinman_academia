//
//  BreadthFirstSearch.hpp
//  ShortestPaths
//
//  Created by Antoun, Sherine on 10/25/24.
//
#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "Digraph.h"
#include "SelfResizingArray.h"

class BreadthFirstSearch {
private:
    bool* marked; // Mark visited vertices
    int* edgeTo; // Store paths
    int* distTo; // Store shortest distance from source vertex
    int numVertices; // Store the number of vertices in the graph

public:
    BreadthFirstSearch(const Digraph& G, int s);
    ~BreadthFirstSearch();
    void bfs(const Digraph& G, int s);
    void printShortestPaths(int s) const;
};

#endif // BREADTH_FIRST_SEARCH_H
