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

template <class VertexType>
struct ItemType
{
    bool operator<(ItemType otherItem) const
    {
        if (otherItem.distance > distance) {return true;}
        else {return false;}
    }
    bool operator==(ItemType otherItem) const
    {
        return (otherItem.distance == distance);
    }
    bool operator<=(ItemType otherItem) const
    {
        if ((otherItem.distance == distance) || (otherItem.distance < distance)) {return true;}
        else {return false;}
    }

    VertexType fromVertex;
    VertexType toVertex;
    int distance;
};

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
        DirectedGraph(std::string);
        ~DirectedGraph();

        void clearMarks();
        bool isEmpty();

        bool vertexExists(VertexType);
        void addVertex(VertexType);
        void markVertex(VertexType);
        void addEdge(VertexType, VertexType, int);
        int getWeight(VertexType, VertexType);
        void getToVertices(VertexType, MuffinQueue<VertexType>&);
        bool isMarked(VertexType);
        int indexIs(VertexType);
        void breadthFirstSearch(VertexType, VertexType);

        void shortestPath(VertexType);
        int* gptShortestPath(VertexType startVertex);
    
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
    _maxVertices = 200;
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
    std::cout << "All vertices and connections initialized." << std::endl;
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

/*
Default Breadth First Search Function that prints all nodes connected to sourceVertex.
This program only utilizes breadthFirstSearch as we do not need DFS.
*/
template <class VertexType>
void DirectedGraph<VertexType>::breadthFirstSearch(VertexType sourceVertex, VertexType destinationVertex)
{
    MuffinQueue<VertexType> tempQueue;
    MuffinQueue<VertexType> vertexQueue;

    bool found = false;
    VertexType vertex;
    VertexType item;

    clearMarks();
    tempQueue.enqueue(sourceVertex);

    do
    {
        vertex = tempQueue.dequeue();
        if (vertex == destinationVertex)
        {
            std::cout << vertex << std::endl;
            found = true;
        }
        else
        {
            // If the vertex is not marked...
            if (!isMarked(vertex))
            {
                markVertex(vertex);
                std::cout << vertex << std::endl;

                getToVertices(vertex, vertexQueue);
                while (!vertexQueue.isEmpty())
                {
                    item = vertexQueue.dequeue();
                    if (!isMarked(item))
                    {
                        tempQueue.enqueue(item);
                    }
                }
            }
        }
    } while ((!tempQueue.isEmpty()) && (!found));

    if (!found)
    {
        std::cerr << "\nPath not found." << std::endl;
    }
}


// ***DO NOT USE***: EMPTY FUNCTION.
template <class VertexType>
void DirectedGraph<VertexType>::shortestPath(VertexType sourceVertex)
{
    // ItemType<VertexType> item;
    // int minDistance = 0;
    // std::priority_queue<ItemType<VertexType>> priorityQueue;
    // MuffinQueue<VertexType> vertexQueue;

    // VertexType vertex;
    // clearMarks();

    // item.fromVertex = sourceVertex;
    // item.toVertex = sourceVertex;
    // item.distance = 0;

    // // priorityQueue.enqueue(item);
    // priorityQueue.push(item);
    
    // std::cout << "Last Vertex Destination Weight/Distance: " << std::endl;
    // std::cout << "-------------------------" << std::endl;

    // do
    // {
    //     item = priorityQueue.top(); // Grabbing data from top of PQ.
    //     priorityQueue.pop(); // Removing first element.

    //     if (!isMarked(item.toVertex))
    //     {
    //         markVertex(item.toVertex);
    //         std::cout << item.fromVertex;
    //         std::cout << " ";
    //         std::cout << item.toVertex;
    //         std::cout << " " << item.distance << std::endl;

    //         item.fromVertex = item.toVertex;
    //         minDistance = item.distance;

    //         getToVertices(item.fromVertex, vertexQueue);

    //         while (!vertexQueue.isEmpty())
    //         {
    //             vertex = vertexQueue.dequeue();

    //             if (!isMarked(vertex))
    //             {
    //                 item.toVertex = vertex;
    //                 item.distance = minDistance + getWeight(item.fromVertex, vertex);
    //                 priorityQueue.push(item);
    //             }
    //         }
    //     }
    // } while (!priorityQueue.empty());
}

// Function returns an array with all possible distances from startVertex.
template <class VertexType>
int* DirectedGraph<VertexType>::gptShortestPath(VertexType startVertex)
{
    clearMarks(); // Setting all marks to false.

    MuffinQueue<VertexType> vertexQueue; // Queue holds all vertices that require analyzation.
    int distances[1000]; // Stores distances from startVertex.

    // Initializing distances to 0...
    for (int i = 0; i < _maxVertices; ++i)
    {
        distances[i] = 0;
    }
    distances[indexIs(startVertex)] = 0;

    // Enqueue the start vertex and mark it as visitied.
    vertexQueue.enqueue(startVertex);
    markVertex(indexIs(startVertex));

    while (!vertexQueue.isEmpty())
    {
        VertexType currentVertex = vertexQueue.dequeue();

        // Getting all adjacent/neighbor vertices.
        MuffinQueue<VertexType> neighborQueue;     
        getToVertices(currentVertex, neighborQueue);

        /*
        // Debugging, printing out all neighbors.
        std::cout << "***DEBUG*** Neighbors of " << currentVertex << ": ";
        while (!neighborQueue.isEmpty())
        {
            VertexType neighbor = neighborQueue.dequeue();
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
        */

        // Check if the current vertex has no neighbors (isolated node).
        if (neighborQueue.isEmpty())
        {
            std::cout << "Vertex " << currentVertex << " has no connections. ";
            std::cout << "Skipping further traversal." << std::endl;
            continue;
        }

        while (!neighborQueue.isEmpty())
        {
            VertexType neighbor = neighborQueue.dequeue();
            int neighborIndex = indexIs(neighbor);

            if (!isMarked(neighborIndex))
            {
                markVertex(neighborIndex);

                distances[neighborIndex] = distances[indexIs(currentVertex)] + 1;
                vertexQueue.enqueue(neighbor);
            }
        }
    }

    return distances;
}

/*

// Function returns a queue of all possible nodes that can be traversed.
    template <class VertexType>
    MuffinQueue<VertexType> DirectedGraph<VertexType>::bfs(VertexType sourceVertex, VertexType destinationVertex)
    {
        MuffinQueue<VertexType> tempQueue;
        MuffinQueue<VertexType> vertexQueue;
        MuffinQueue<VertexType> resultQueue;

        bool found = false;
        VertexType vertex;
        VertexType item;

        clearMarks();
        tempQueue.enqueue(sourceVertex);

        do
        {
            vertex = tempQueue.dequeue();
            if (vertex == destinationVertex)
            {
                resultQueue.enqueue(vertex);
                found = true;
            }
            else
            {
                // If the vertex is not marked...
                if (!isMarked(vertex))
                {
                    markVertex(vertex);
                    resultQueue.enqueue(vertex);

                    getToVertices(vertex, vertexQueue);
                    while (!vertexQueue.isEmpty())
                    {
                        item = vertexQueue.dequeue();
                        if (!isMarked(item))
                        {
                            tempQueue.enqueue(item);
                        }
                    }
                }
            }
        } while ((!tempQueue.isEmpty()) && (!found));

        if (!found)
        {
            std::cerr << "\nPath not found." << std::endl;
        }

        return resultQueue;
    }
*/
