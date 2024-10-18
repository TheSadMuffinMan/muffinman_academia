#pragma once

#include <iostream>
#include "Queue.h"

const int NULL_EDGE = 0;

/*
This class assumes that the VertexType Class is a type for which the "=", "==", and "<<" operators
are defined.
*/
template <class VertexType>
class DirectedGraph
{
    public:
        DirectedGraph();
        DirectedGraph(int);
        ~DirectedGraph();

        void clearMarks();
        bool isEmpty();
        int getNumVertices();

        void addVertex(VertexType);
        void markVertex(VertexType);
        void addEdge(VertexType, VertexType, int);
        int getWeight(VertexType, VertexType);
        void getToVertices(VertexType, Queue<VertexType>&);
        bool isMarked(VertexType);
        int indexIs(VertexType*, VertexType)
    
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
    _vertices = new VertexType[_maxVertices];
    _marks = new bool[_maxVertices];
    for (int i = 0; i < _maxVertices; i++) {_marks[i] = false;}
}

// Non-Default constructor that initializes _maxVertices to userMaxVertices.
template <class VertexType>
DirectedGraph<VertexType>::DirectedGraph(int userMaxVertices)
{
    _numVertices = 0;
    _maxVertices = userMaxVertices;
    _vertices = new VertexType[_maxVertices];
    _marks = new bool[_maxVertices];
}

template <class VertexType>
DirectedGraph<VertexType>::~DirectedGraph()
{
    delete[] _vertices;
    delete[] _marks;
}

// Function sets all _marks to false.
template <class VertexType>
void DirectedGraph<VertexType>::clearMarks()
{
    for (int i = 0; i < _maxVertices; i++)
    {
        _marks[i] = false;
    }
}

// Function checks whether DirectedGraph is empty or not.
template <class VertexType>
bool DirectedGraph<VertexType>::isEmpty()
{
    if (getNumVertices() == 0) {return true}
    else {return false;}
}

// Function returns number of vertices inside DirectedGraph.
template <class VertexType>
int DirectedGraph<VertexType>::getNumVertices() {return _numVertices;}

// Function adds a vertex.
template <class VertexType>
void DirectedGraph<VertexType>::addVertex(VertexType passedVertex)
{
    _vertices[getNumVertices()] = passedVertex;

    for (int i = 0; i < getNumVertices(); i++)
    {
        _edges[_numVertices][i] = NULL_EDGE;
        _edges[i][_numVertices] = NULL_EDGE;
    }

    _numVertices++;
}

// Function marks passed vertex.
template <class VertexType>
void DirectedGraph<VertexType>::markVertex(VertexType vertex) {_marked[vertex] = true;}

// Function returns the index of the passed vertex.
template <class VertexType>
int DirectedGraph<VertexType>::indexIs(VertexType* vertices, VertexType vertex)
{
    int index = 0;
    while (!(vertex == vertices[index])) {index++;}
    return index;
}

// Function Parameters: VertexType sourceVertex, VertexType destinationVertex, int weight.
template <class VertexType>
void DirectedGraph<VertexType>::addEdge(VertexType sourceVertex, VertexType destinationVertex, int weight)
{
    int row, column;
    row = indexIs(_vertices, sourceVertex);
    column = idexIs(_vertices, destinationVertex);
    _edges[row][column] = weight; 
}

// Function Parameters: VertexType sourceVertex, VertexType destinationVertex.
template <class VertexType>
int DirectedGraph<VertexType>::getWeight(VertexType sourceVertex, VertexType destinationVertex)
{
    int row, column;
    row = indexIs(_vertices, sourceVertex);
    column = idexIs(_vertices, destinationVertex);
    return _edges[row][column]; 
}

// Function Parameters: VertexType vertex, Queue<VertexType>& adjVertices.
template <class VertexType>
void DirectedGraph<VertexType>::getToVertices(VertexType vertex, Queue<VertexType>& adjVertices)
{
    int fromIndex, toIndex;

    fromIndex = indexIs(_vertices, vertex);
    for (toIndex = 0; toIndex < getNumVertices(); toIndex++)
    {
        if (_edges[fromIndex][toIndex] != NULL_EDGE)
        {
            adjVertices.enqueue(_vertices[toIndex]);
        }
    }
}

// Function returns whether or not "vertex" has been marked.
template <class VertexType>
bool DirectedGraph<VertexType>::isMarked(VertexType vertex)
{
    if (_marks[vertex] == true)
    {
        return true;
    }
    else {return false;}
}
