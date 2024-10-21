/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start.\n" << std::endl;

    DirectedGraph<int> workingGraph;

    workingGraph.addVertex(1);
    workingGraph.addVertex(2);
    workingGraph.addVertex(4);

    workingGraph.addEdge(1, 2, 5);
    workingGraph.addEdge(2, 1, 5);

    std::cout << "\nWeight between nodes 1 & 2: " << workingGraph.getWeight(1, 2) << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}