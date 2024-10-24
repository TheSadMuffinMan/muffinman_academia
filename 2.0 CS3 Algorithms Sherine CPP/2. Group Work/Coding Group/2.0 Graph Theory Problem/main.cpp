/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start.\n" << std::endl;

    DirectedGraph<int> testGraph("inputFile.txt");

    std::cout << "\nCalling testGraph.gptShortestPath(5)..." << std::endl;
    int* distances = testGraph.gptShortestPath(5);

    for (int i = 0; i < sizeof(distances); i++)
    {
        std::cout << "Distance from " << i << ": " << distances[i] << std::endl;
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/* TESTING CODE

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