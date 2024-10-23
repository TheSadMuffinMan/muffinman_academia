/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start.\n" << std::endl;

    DirectedGraph<int> testGraph = DirectedGraph<int>("inputFile.txt");

    std::cout << "\nWeight 0 & 8 = 3?: " << std::boolalpha << (testGraph.getWeight(0, 8) == 3) << std::endl;
    std::cout << "Weight 1 & 13 = 7?: " << std::boolalpha << (testGraph.getWeight(1, 3) == 7) << std::endl;
    std::cout << "Weight 13 & 11 = 4?: " << std::boolalpha << (testGraph.getWeight(13, 11) == 4) << std::endl;
    std::cout << "Weight 32 & 31 = 5?: " << std::boolalpha << (testGraph.getWeight(32, 31) == 5) << std::endl;

    std::cout << "\nUsing DFS, shortest path between 1 & 3: ";
    testGraph.depthFirstSearch(1, 3);
    std::cout << std::endl;

    std::cout << "\nUsing BFS, shortest path between 1 & 3: ";
    testGraph.breadthFirstSearch(1, 3);
    std::cout << std::endl;


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