#include <iostream>
#include "StackType.h" // COMPLETE AND WORKING.

const int NULL_EDGE = 0;

/*
This class assumes that VertexType is a type for which the "=", "==", and "<<" operators are defined.
*/
template <class VertexType>
class GraphType
{
    public:
        GraphType();
        GraphType(int); // GraphType(int maxVertices);
        ~GraphType();

        void makeEmpty();
        bool isEmpty() const;
        bool isFull() const;
        void addVertex(VertexType);
        void addEdge(VertexType, VertexType, int);
        int getWeight(VertexType, VertexType);
        void getToVertices(VertexType, QueType<VertexType>&);
        void clearMarks();
        void markVisited(VertexType);
        bool isMarked(VertexType);
    
    private:
        int _numVertices;
        int _maxVertices;
        VertexType* _vertices;
        int _edges[50][50];
        bool* _marks; // marks[i] is the mark for _vertices[i];
};

/*
Arrays of size 50 are dynamically allocated for marks and vertices. _numVertices is set to 0,
    and _maxVertices is set to 50.
*/
template <class VertexType>
GraphType<VertexType>::GraphType()
{
    _numVertices = 0;
    _maxVertices = 0;
    _vertices = new VertexType[50];
    _marks = new bool[50];
}

/*
Arrays of size userMaxVertices are dynamically allocated for _marks and _vertices.
_numVertices is set to 0; _maxVertices is set to userMaxVertices.
*/
template <class VertexType>
GraphType<VertexType>::GraphType(int userMaxVertices)
{
    _numVertices = 0;
    _maxVertices = userMaxVertices;
    _vertices = new VertexType[userMaxVertices];
    _marks = new bool[userMaxVertices];
}

// Properly deallocating memory.
template <class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete[] _vertices;
    delete[] _marks;
}

// Function initializes he graph to an empty state.
template <class VertexType>
void GraphType<VertexType>::makeEmpty()
{
    //
}

// Function tests whether the graph is empty.
template <class VertexType>
bool GraphType<VertexType>::isEmpty() const
{
    //
}

// Function tests whether the graph is full.
template <class VertexType>
bool GraphType<VertexType>::isFull() const
{
    //
}

// Function adds a vertex to the graph.
template <class VertexType>
void GraphType<VertexType>::addVertex(VertexType userVertex)
{
    _vertices[_numVertices] = userVertex;
    for (int i = 0; i < _numVertices; i++)
    {
        _edges[_numVertices][i] = NULL_EDGE;
        _edges[i][_numVertices] = NULL_EDGE;
    }

    _numVertices++;
}

// Function adds an edge with the specified weight from sourceVertex to destinationVertex.
template <class VertexType>
void GraphType<VertexType>::addEdge(VertexType sourceVertex, VertexType destinationVertex, int weight)
{
    //
}

// Function returns the weight of the edge from sourceVertex to destinationVertex.
template <class VertexType>
int GraphType<VertexType>::getWeight(VertexType sourceVertex, VertexType destinationVertex)
{
    //
}

// Function returns a queue of the vertices that are adjacent from vertex.
template <class VertexType>
void GraphType<VertexType>::getToVertices(VertexType userVertex, QueType<VertexType>& returnQueue)
{
    //
}

// Function sets marks to all vertices to false.
template <class VertexType>
void GraphType<VertexType>::clearMarks()
{
    //
}

// Function marks _mark for _vertex to true.
template <class VertexType>
void GraphType<VertexType>::markVisited(VertexType passedVertex)
{
    //
}

// Function determines if the vertex has been marked/visited.
template <class VertexType>
bool GraphType<VertexType>::isMarked(VertexType passedVertex)
{
    //
}
