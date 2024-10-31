/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

#include <iostream>
#include <fstream>
#include <chrono>

#include "Digraph.h"
#include "BreadthFirstSearch.h"

Digraph* buildGraphFromFile(std::string);

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    Digraph* tempGraph = new Digraph(29);
    tempGraph = buildGraphFromFile("noWInputFile.txt");

    // ***DEBUG*** Change function parameter to real fileName when complete.
    Digraph* currGraph = buildGraphFromFile("noWInputFile.txt");
    BreadthFirstSearch bfs(currGraph, 0);

    delete currGraph;
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

// Function builds and returns a Directed Graph from fileName.
Digraph* buildGraphFromFile(std::string fileName)
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

    Digraph* graph = new Digraph(tempNumVertices);

    while (!inputStream.eof())
    {
        std::getline(inputStream, fullString);
        // std::cout << "***DEBUG*** fullString = [" << fullString << "]" << std::endl;

        int spaceIndex = 0;
        // int secondSpaceIndex = 0; // Not needed with no weights.
        int sourceVertex, destinationVertex;

        // If there is only a vertex and no connections...
        // In this implementation, this only happens for Node #29.
        if (fullString.find(" ") == std::string::npos)
        {
            // sourceVertex = std::stoi(fullString);
            std::cout << "Adding Vertex " << fullString << " with no connections." << std::endl;
            continue;
        }

        spaceIndex = fullString.find(" ");        
        tempString = fullString.substr(0, (fullString.size() - (fullString.size() - spaceIndex)));

        sourceVertex = std::stoi(tempString);
        destinationVertex = std::stoi(fullString.substr((spaceIndex + 1)));
        
        destinationVertex = std::stoi(tempString);

        // Un-comment below to see each edge being added.
        std::cout << "Adding Edge between " << sourceVertex << " and " << destinationVertex << "." << std::endl;

        graph->addEdge(sourceVertex, destinationVertex);
    }

    inputStream.close();

    // graph->addEdge(0,8); // ***DEBUG*** Input is not setting edge between 0 & 8... Fix later.
    std::cout << "All vertices and connections initialized from " << fileName << "." << std::endl;
    return graph;
}

/* OLD CODE:

    int V = 6; // Number of vertices
    Digraph G(V);

    // Add directed edges (example graph)
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(4, 5);

    // Perform BFS starting from vertex 0
    BreadthFirstSearch bfs(G, 0);
    bfs.printShortestPaths(0);
*/
