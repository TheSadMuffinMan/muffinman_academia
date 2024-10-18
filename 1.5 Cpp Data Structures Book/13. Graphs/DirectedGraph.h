#pragma once

#include <iostream>
#include "Queue.h"

/*
This class assumes that the VertexType Class is a type for which the "=", "==", and "<<" operators
are defined.
*/
template <class VertexType>
class DirectedGraph
{
    public:
        DirectedGraph();
        DirectedGraph(int userMaxVertices);
        ~DirectedGraph();

        void makeEmpty();
        void clearMarks();
        bool isEmpty();

        void addVertex(VertexType);
        void markVertex(VertexType);
        void addEdge(VertexType, VertexType, int);
        int getWeight(VertexType, VertexType);
        void getToVertices(VertexType, Queue<VertexType>&);
        bool isMarked(VertexType);
    
    private:
        int _numVertices;
        int _maxVertices; // Is initialized to 50 in default constructor.
        VertexType* _vertices;
        int _edges[50][50];
        bool* _marks;
};

// Default constructor that sets _maxVertices = 50.
template <class VertexType>
DirectedGraph<VertexType>::DirectedGraph()
{
    _numVertices = 0;
    _maxVertices = 50;
    _vertices = new VertexType[50];
    _marks = new bool[50];
}

// Non-Default constructor that initializes _maxVertices to userMaxVertices.
template <class VertexType>
DirectedGraph<VertexType>::DirectedGraph(int userMaxVertices)
{
    _numVertices = 0;
    _maxVertices = userMaxVertices;
    _vertices = new VertexType[userMaxVertices];
    _marks = new bool[userMaxVertices];
}

template <class VertexType>
DirectedGraph<VertexType>::~DirectedGraph()
{
    delete[] _vertices;
    delete[] _marks;
}
