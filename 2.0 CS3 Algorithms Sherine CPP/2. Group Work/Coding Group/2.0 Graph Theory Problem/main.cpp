/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start.\n" << std::endl;

    DirectedGraph<int> testGraph = DirectedGraph<int>("inputFile.txt");

    std::cout << "\nWeight between 0 & 8: " << testGraph.getWeight(0, 8) << std::endl;
    std::cout << "Weight between 1 & 3: " << testGraph.getWeight(1, 3) << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/* TESTING CODE

    DirectedGraph<int> testGraph(5);
    testGraph.addVertex(0);
    testGraph.addVertex(8);
    testGraph.addEdge(0,8,3);

    std::cout << "Vertex 0 exists: " << std::boolalpha << testGraph.vertexExists(0) << std::endl;

*/