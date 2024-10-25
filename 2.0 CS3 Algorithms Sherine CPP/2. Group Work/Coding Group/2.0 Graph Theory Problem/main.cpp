/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    int source1, source2, source3, destination1, destination2, destination3;
    int path[50];
    int pathWeight = 0;
    std::string fileName;

    std::cout << "\nProgram start.\n" << std::endl;
    std::cin >> fileName;

    DirectedGraph<int> workingGraph(fileName);

    std::cout << "\nProvide 3 sources (seperated by a space): ";
    std::cin >> source1 >> source2 >> source3;

    std::cout << "\n\tDestination 1?: ";
    std::cin >> destination1;
    std::cout << "Shortest Path 1 from vertex \"" << source1 << "\":" << std::endl;
    if (workingGraph.shortestPath(source1, destination1, path, pathWeight))
    {
        for (int i = 0; i < (pathWeight - 1); i++)
        {
            std::cout << path[i] << " --> ";
        }
        std::cout << destination1 << std::endl;
    }
    else
    {
        std::cout << "Path not found." << std::endl;
    }



    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/* TESTING CODE

    DirectedGraph<int> testGraph("inputFile.txt");

    // std::cout << "\nCalling testGraph.gptShortestPath(5)..." << std::endl;
    // testGraph.gptShortestPath(5);

    int path[30]; // Assume a maximum path length of 30.
    int pathLength;

    std::cout << "\nCalling testGraph.shortestPath(21, 22,...):" << std::endl;
    if (testGraph.shortestPath(21, 22, path, pathLength))
    {
        std::cout << "Shortest path from 21 to 22: ";
        for (int i = 0; i < pathLength; ++i)
        {
            std::cout << path[i] << " --> ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No path found." << std::endl;
    }

    int path2[50];
    int pathLength2;
    std::cout << "\nCalling testGraph.shortestPath(20, 27,...):" << std::endl;
    if (testGraph.shortestPath(20, 27, path2, pathLength2))
    {
        std::cout << "Shortest path from 20 to 27: ";
        for (int i = 0; i < pathLength; ++i)
        {
            std::cout << path[i] << " --> ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No path found." << std::endl;
    }

    std::cout << "\nWeight 0 & 8 = 3?: " << std::boolalpha << (testGraph.getWeight(0, 8) == 3) << std::endl;
    std::cout << "Weight 1 & 13 = 7?: " << std::boolalpha << (testGraph.getWeight(1, 3) == 7) << std::endl;
    std::cout << "Weight 13 & 11 = 4?: " << std::boolalpha << (testGraph.getWeight(13, 11) == 4) << std::endl;
    std::cout << "Weight 32 & 31 = 5?: " << std::boolalpha << (testGraph.getWeight(32, 31) == 5) << std::endl;

    std::cout << "\nUsing DFS, shortest path between 1 & 3: ";
    testGraph.depthFirstSearch(1, 3);
    std::cout << std::endl;

    std::cout << "\nBFS function for 1 & 3 returns: ";
    testGraph.breadthFirstSearch(1, 3);
    std::cout << std::endl;

    std::cout << "\nBFS function for 5 & 7 returns: ";
    testGraph.breadthFirstSearch(5, 7);
    std::cout << std::endl;

    std::cout << "\nBFS function for 20 & 26 returns: ";
    testGraph.breadthFirstSearch(20, 26);
    std::cout << std::endl;

    DirectedGraph<int> testGraph(5);
    testGraph.addVertex(0);
    testGraph.addVertex(8);
    testGraph.addEdge(0,8,3);

    std::cout << "Vertex 0 exists: " << std::boolalpha << testGraph.vertexExists(0) << std::endl;

*/