/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

void mainShortestPath(DirectedGraph<int>&, int*);

int main(int argc, char *argv[])
{
    int sourceArray[2];

    std::string fileName = "inputFile.txt"; // ***DEBUG WHEN COMPLETE***

    std::cout << "\nProgram start.\n" << std::endl;
    // std::cin >> fileName; // ***DEBUG WHEN COMPLETE***

    DirectedGraph<int> workingGraph(fileName);

    std::cout << "\nProvide 3 sources (seperated by a space): ";

    for (int i = 0; i < 3; i++)
    {
        std::cin >> sourceArray[i];
    }

    mainShortestPath(workingGraph, sourceArray);
    mainShortestPath(workingGraph, sourceArray);
    mainShortestPath(workingGraph, sourceArray);

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

void mainShortestPath(DirectedGraph<int>& currentGraph, int* sourceArray)
{
    int destination;
    int path[50];
    int pathWeight = 0;

    std::cout << "\n\tDestination 1?: ";
    std::cin >> destination;

    std::cout << "Shortest Path 1 from vertex \"" << sourceArray[0] << "\":" << std::endl;
    if (currentGraph.shortestPath(sourceArray[0], destination, path, pathWeight))
    {
        for (int i = 0; i < (pathWeight - 1); i++)
        {
            std::cout << path[i] << " --> ";
        }
        std::cout << destination << std::endl;
    }
    else
    {
        std::cout << "Path not found." << std::endl;
    }

    pathWeight = 0;
    for (int i = 0; i < 50; i++)
    {
        path[i] = -1;
    }
    std::cout << "Shortest Path 2 from vertex \"" << sourceArray[1] << "\":" << std::endl;
    if (currentGraph.shortestPath(sourceArray[1], destination, path, pathWeight))
    {
        for (int i = 0; i < (pathWeight - 1); i++)
        {
            std::cout << path[i] << " --> ";
        }
        std::cout << destination << std::endl;
    }
    else
    {
        std::cout << "Path not found." << std::endl;
    }

    pathWeight = 0;
    for (int i = 0; i < 50; i++)
    {
        path[i] = -1;
    }
    std::cout << "Shortest Path 3 from vertex \"" << sourceArray[2] << "\":" << std::endl;
    if (currentGraph.shortestPath(sourceArray[2], destination, path, pathWeight))
    {
        for (int i = 0; i < (pathWeight - 1); i++)
        {
            std::cout << path[i] << " --> ";
        }
        std::cout << destination << std::endl;
    }
    else
    {
        std::cout << "Path not found." << std::endl;
    }
}