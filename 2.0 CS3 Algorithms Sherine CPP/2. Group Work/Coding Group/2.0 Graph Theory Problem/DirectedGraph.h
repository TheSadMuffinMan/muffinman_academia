#pragma once
#include <iostream>
#include <chrono>
#include "MuffinQueue.h"

#pragma once

#include <iostream>
#include "MuffinQueue.h"

const int NULL_EDGE = 0;

/*
Class assumes that the VertexType Class is a type for which the "=", "==", and "<<" operators are defined.
Class utilizes an Adjacency Matrix (_edges).
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

        void addVertex(VertexType);
        void markVertex(VertexType);
        void addEdge(VertexType, VertexType, int); // NEED TO CHECK IF WEIGHT ALREADY EXISTS.
        int getWeight(VertexType, VertexType);
        void getToVertices(VertexType, Queue<VertexType>&);
        bool isMarked(VertexType);
        int indexIs(VertexType);
        void breadthFirstSearch(VertexType, VertexType);
        void depthFirstSearch(VertexType, VertexType);
    
    private:
        int _numVertices;
        int _maxVertices; // Is initialized to 500 in default constructor.
        VertexType* _vertices;
        int _edges[500][500];
        bool* _marks;
};

/*
***Overloaded Constructor saves memory***
Default constructor that sets _maxVertices = 500.
*/
template <class VertexType>
DirectedGraph<VertexType>::DirectedGraph()
{
    _numVertices = 0;
    _maxVertices = 500;
    _vertices = new VertexType[_maxVertices];
    _marks = new bool[_maxVertices];
    for (int i = 0; i < _maxVertices; i++) {_marks[i] = false;}
}

/*
***PREFERRED CONSTRUCTOR*** - Saves memory.
Overloaded constructor that initializes _maxVertices to userMaxVertices.
*/
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
    if (_numVertices == 0) {return true;}
    else {return false;}
}

// Function adds a vertex.
template <class VertexType>
void DirectedGraph<VertexType>::addVertex(VertexType passedVertex)
{
    _vertices[_numVertices] = passedVertex;

    for (int i = 0; i < _numVertices; i++)
    {
        _edges[_numVertices][i] = NULL_EDGE;
        _edges[i][_numVertices] = NULL_EDGE;
    }

    _numVertices++;
}

// Function marks passed vertex.
template <class VertexType>
void DirectedGraph<VertexType>::markVertex(VertexType vertex) {_marks[vertex] = true;}

/*
BE CAREFUL WITH SPELLING when calling this function lol.
This "helper" function returns the index of the passed vertex.
*/
template <class VertexType>
int DirectedGraph<VertexType>::indexIs(VertexType vertex)
{
    int index = 0;
    while (!(vertex == _vertices[index])) {index++;}
    return index;
}

// Function Parameters: VertexType sourceVertex, VertexType destinationVertex, int weight.
template <class VertexType>
void DirectedGraph<VertexType>::addEdge(VertexType sourceVertex, VertexType destinationVertex, int weight)
{
    int row, column;
    row = indexIs(sourceVertex);
    column = indexIs(destinationVertex);
    _edges[row][column] = weight; 
}

// Function Parameters: VertexType sourceVertex, VertexType destinationVertex.
template <class VertexType>
int DirectedGraph<VertexType>::getWeight(VertexType sourceVertex, VertexType destinationVertex)
{
    int row, column;
    row = indexIs(sourceVertex);
    column = indexIs(destinationVertex);
    return _edges[row][column]; 
}

// Function Parameters: VertexType vertex, Queue<VertexType>& adjVertices.
template <class VertexType>
void DirectedGraph<VertexType>::getToVertices(VertexType vertex, Queue<VertexType>& adjVertices)
{
    int fromIndex, toIndex;

    fromIndex = indexIs(vertex);
    for (toIndex = 0; toIndex < _numVertices; toIndex++)
    {
        if (_edges[fromIndex][toIndex] != NULL_EDGE)
        {
            adjVertices.enqueue(_vertices[toIndex]);
        }
    }
}

// Function returns whether or not function parameter "vertex" has been marked.
template <class VertexType>
bool DirectedGraph<VertexType>::isMarked(VertexType vertex)
{
    if (_marks[vertex] == true)
    {
        return true;
    }
    else {return false;}
}

template <class VertexType>
void DirectedGraph<VertexType>::breadthFirstSearch(VertexType sourceVertex, VertexType destinationVertex)
{
    Queue<VertexType> tempQueue;
    Queue<VertexType> vertexQ;

    bool found = false;
    VertexType vertex;
    VertexType item;

    clearMarks();
    tempQueue.enqueue(sourceVertex);

    do
    {
        tempQueue.dequeue(vertex);
        if (vertex == destinationVertex)
        {
            std::cout << vertex << std::endl;
            found = true;
        }
        else
        {
            if (!isMarked(vertex))
            {
                markVertex(vertex);
                std::cout << vertex << std::endl;
                getToVertices(vertex, vertexQ);
                while (!vertexQ.isEmpty())
                {
                    vertexQ.dequeue(item);
                    if (!isMarked(item))
                    {
                        tempQueue.enqueue(item);
                    }
                }
            }
        }
    } while ((tempQueue.isEmpty()) && (!found));

    if (!found)
    {
        std::cerr << "\nPath not found." << std::endl;
    }
}

template <class VertexType>
void DirectedGraph<VertexType>::depthFirstSearch(VertexType sourceVertex, VertexType destinationVertex)
{
    StackType<VertexType> stack;
    Queue<VertexType> vertexQueue;

    bool found = false;
    VertexType vertex;
    VertexType item;

    clearMarks();

    stack.push(sourceVertex);
    do
    {
        vertex = stack.pop();
        if (vertex == destinationVertex)
        {
            std::cout << vertex << std::endl;
            found = true;
        } else
        {
            if (isMarked(vertex))
            {
                markVertex(vertex);
                std::cout << vertex << std::endl;

                getToVertices(vertex, vertexQueue);

                while (!vertexQueue.isEmpty())
                {
                    vertexQueue.dequeue(item);
                    if (isMarked(item)) {stack.push(item);}
                }
            }
        }
    } while ((!stack.isEmtpy()) && (!found));

    if (!found)
    {
        std::cout << "Path not found." << std::endl;
    }
}
