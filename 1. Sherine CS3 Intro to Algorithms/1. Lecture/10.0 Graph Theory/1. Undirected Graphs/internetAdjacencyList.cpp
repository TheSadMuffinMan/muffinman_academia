#include <iostream>

class Graph
{
    public:
        Graph(int);
        void addEdge(int, int);

        void printGraph();
    
    private:
        int _numVertices;
        int** _adjacencyMatrix; // Stores the actual matrix.
};

Graph::Graph(int vertices)
{
    _numVertices = vertices;
    // WORKING TO THIS POINT.

    // Loop initializes all vertices to 0.
    for (int i = 0; i < _numVertices; i++)
    {
        for (int j = 0; j < _numVertices; i++)
        {
            std::cout << "DEBUG Working1" << std::endl;
            _adjacencyMatrix[i][j] = 0;
        }
    }

    std::cout << "DEBUG Working2" << std::endl;
}

/*
Function adds an edge (v --- w).
v == "source", w == "destination".
*/
void Graph::addEdge(int v, int w)
{
    std::cout << "Adding edge between " << v << " & " << w << std::endl;
    _adjacencyMatrix[v][w] = 1;
    // _adjacencyMatrix[w][v] = 1;
}

void Graph::printGraph()
{
    // For each vertex...
    for (int i = 0; i < _numVertices; i++)
    {
        // Print the vertex.
        std::cout << i << ": ";

        // Iterate through the adjacency list of the vertex.
        for (int j = 0; j < _numVertices; j++)
        {
            std::cout << _adjacencyMatrix[i][j] << " -> ";
        }

        std::cout << "NULL" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
        
    int vertices = 0;
    std::cin >> vertices;

    Graph workingGraph(vertices); // BREAKING INSIDE OF HERE.

    workingGraph.addEdge(0, 1);
    workingGraph.addEdge(1, 0);
    workingGraph.addEdge(2, 0);

    std::cout << "Undirected Graph Adjacency List:" << std::endl;
    workingGraph.printGraph();


    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
