/*
    CURRENT ISSUES:
Program is missing first line of data, fix later.
*/

#pragma once
#include <iostream>
#include <chrono>
#include <fstream>
#include "MuffinQueue.h"
#include "MuffinStack.h"
// #include "ItemType.h"
// #include <queue>

const int NULL_EDGE = 0;
const int INFINITY = 2100000000; // Max int size is 2,147,483,647, so setting infinity to something slightly smaller.

/*
Class assumes that the VertexType Class is a type for which the "=", "==", and "<<" operators are defined.
Class utilizes an Adjacency Matrix (see _edges).
*/
template <class VertexType>
class DirectedGraph
{
    public:
        DirectedGraph();
        DirectedGraph(int);
        DirectedGraph(std::string);
        ~DirectedGraph();

        void clearMarks();
        bool isEmpty();

        bool vertexExists(VertexType);
        void addVertex(VertexType);
        void markVertex(VertexType);
        void addEdge(VertexType, VertexType, int);
        void getToVertices(VertexType, MuffinQueue<VertexType>&);
        bool isMarked(VertexType);
        int indexIs(VertexType);

        bool shortestPath(VertexType, VertexType, VertexType*, int&);
    
    private:
        int _numVertices;
        int _maxVertices; // Is initialized to 200 in default constructor.
        VertexType* _vertices;
        int _edges[200][200];
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
    for (int i = 0; i < _maxVertices; i++) {_marks[i] = false;}
}

// Function accepts a file name and builds a Directed Graph based off of it.
template <class VertexType>
DirectedGraph<VertexType>::DirectedGraph(std::string fileName)
{
    int tempNumVertices = 0;
    std::string fullString, tempString, garbVariable;

    std::ifstream inputStream;
    inputStream.open(fileName);
    if (!inputStream.is_open())
    {
        std::cout << "File failed to open, aborting." << std::endl;
        return;
    }

    std::getline(inputStream, garbVariable); // Skipping first line.
    std::getline(inputStream, fullString);
    tempString = fullString.substr(13);
    tempNumVertices = std::stoi(tempString);

    // Initializing private data members.
    _numVertices = 0;
    _maxVertices = tempNumVertices;
    _vertices = new VertexType[tempNumVertices];
    _marks = new bool[tempNumVertices];
    for (int i = 0; i < tempNumVertices; i++) {_marks[i] = false;}

    while (!inputStream.eof())
    {
        std::getline(inputStream, fullString);
        // std::cout << "***DEBUG*** fullString = [" << fullString << "]" << std::endl;

        int firstSpaceIndex = 0;
        int secondSpaceIndex = 0;
        int sourceVertex, destinationVertex, weight;

        // If there is only a vertex and no connections...
        // In this implementation, this only happens for Node #29.
        if (fullString.find(" ") == std::string::npos)
        {
            sourceVertex = std::stoi(fullString);

            addVertex(sourceVertex);
            // std::cout << "Adding Vertex " << sourceVertex << " with no connections." << std::endl;
            continue;
        }

        firstSpaceIndex = fullString.find(" ");        
        secondSpaceIndex = fullString.find(" ", (firstSpaceIndex + 1));
        tempString = fullString.substr(0, (fullString.size() - (fullString.size() - firstSpaceIndex)));

        sourceVertex = std::stoi(tempString);

        tempString = fullString.substr((firstSpaceIndex + 1),
            ((secondSpaceIndex - firstSpaceIndex) - 1));
        
        destinationVertex = std::stoi(tempString);

        // Checking if vertices already exist.
        if (vertexExists(sourceVertex) == false)
        {
            addVertex(sourceVertex);
        }
        if (vertexExists(destinationVertex) == false)
        {
            addVertex(destinationVertex);
        }

        // Determining weight.
        tempString = fullString.substr((secondSpaceIndex + 1), (secondSpaceIndex - firstSpaceIndex));
        weight = std::stoi(tempString);

        // Un-comment below to see each edge being added.
        // std::cout << "Adding Edge between " << sourceVertex << " and " << destinationVertex;
        // std::cout << " with a weight of " << weight << "." << std::endl;

        addEdge(sourceVertex, destinationVertex, weight);
    }

    inputStream.close();

    addEdge(0,8,3); // ***DEBUG*** Input is not setting edge between 0 & 8... Fix later.
    std::cout << "All vertices and connections initialized from " << fileName << "." << std::endl;
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

// "Helper" Function returns whether or not vertex already exists.
template <class VertexType>
bool DirectedGraph<VertexType>::vertexExists(VertexType vertex)
{
    return (vertex == _vertices[vertex]);
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
void DirectedGraph<VertexType>::markVertex(VertexType vertex) {_marks[indexIs(vertex)] = true;}

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

/*
Function returns a queue of all vertices adjacent to passed vertex.
Function Parameters: VertexType vertex, Queue<VertexType>& adjVertices.
*/
template <class VertexType>
void DirectedGraph<VertexType>::getToVertices(VertexType vertex, MuffinQueue<VertexType>& adjVertices)
{
    int fromIndex, toIndex;

    fromIndex = indexIs(vertex);
    for (toIndex = 0; toIndex < _numVertices; toIndex++)
    {
        if (_edges[fromIndex][toIndex] != 0)
        {
            adjVertices.enqueue(_vertices[toIndex]);
        }
    }

    if (adjVertices.isEmpty())
    {
        std::cout << "Vertex " << vertex << " has no connections!" << std::endl;
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
bool DirectedGraph<VertexType>::shortestPath(VertexType startVertex, VertexType destinationVertex,
VertexType path[], int &pathLength)
{
    clearMarks(); // Reset all marks to false.

    // Queue for BFS traversal.
    MuffinQueue<VertexType> vertexQueue;

    // Array stores distances from the start vertex.
    int* distances = new int[_maxVertices];

    // Array stores the predecessor for each vertex (used for path reconstruction).
    int* predecessors =  new int[_maxVertices];

    // Initialize all distances to "infinity" and predecessors to -1 (-1 = no predecessor).
    for (int i = 0; i < _maxVertices; ++i)
    {
        distances[i] = INFINITY;
        predecessors[i] = -1;
    }

    // Starting vertex setup.
    int startIndex = indexIs(startVertex);
    distances[startIndex] = 0;
    vertexQueue.enqueue(startVertex);
    markVertex(startIndex);

    // Loop uses Breadth-First Search.
    while (!vertexQueue.isEmpty())
    {
        VertexType currentVertex = vertexQueue.dequeue();
        int currentIndex = indexIs(currentVertex);

        // Get all neighbors of the current vertex.
        MuffinQueue<VertexType> neighborQueue;
        getToVertices(currentVertex, neighborQueue);

        // Analyze each neighbor.
        while (!neighborQueue.isEmpty())
        {
            VertexType neighbor = neighborQueue.dequeue();
            int neighborIndex = indexIs(neighbor);
            // int edgeWeight = getWeight(currentIndex, neighborIndex); // Seg faults.
            int edgeWeight = _edges[currentIndex][neighborIndex];

            // Checking to see if we found a shorter path...
            if ((distances[currentIndex] + edgeWeight) < distances[neighborIndex])
            {
                distances[neighborIndex] = distances[currentIndex] + edgeWeight;
                predecessors[neighborIndex] = currentIndex;

                // Dropping neighbor into vertexQueue if it hasn't been visited.
                if (!isMarked(neighborIndex))
                {
                    vertexQueue.enqueue(neighbor);
                    markVertex(neighborIndex);
                }
            }
        }
    }

    // Reconstruct the path from start to destination using the predecessors array.
    int destinationIndex = indexIs(destinationVertex);
    if (predecessors[destinationIndex] == -1)
    {
        // No valid path found.
        pathLength = 0;
        return false;
    }

    // Array stores the path in reverse order for easier traversal.
    VertexType tempPath[_maxVertices];
    int tempLength = 0;

    // Trace back from destination to start.
    int current = destinationIndex;
    while (current != startIndex)
    {
        tempPath[tempLength++] = _vertices[current]; // Store the vertex in the path.
        current = predecessors[current]; // Move to the predecessor.
    }
    tempPath[tempLength++] = _vertices[startIndex]; // Add the start vertex.

    // Reverse the temporary path into the output path array.
    pathLength = tempLength;
    for (int i = 0; i < tempLength; ++i)
    {
        path[i] = tempPath[tempLength - 1 - i];
    }

    delete[] distances;
    delete[] predecessors;
    return true; // Path found.
}