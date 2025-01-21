/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

#pragma once

#include "SelfResizingArray.h"

class Digraph
{
    public:
        Digraph(int _numVertices);
        ~Digraph();

        void addEdge(int, int);
        const SelfResizingArray<int>& getAdj(int v) const;
        int getVertices() const;

    private:
        int _numVertices;
        int _numEdges;
        SelfResizingArray<int>* _adj; // Array of adjacency lists.
};
