#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    DirectedGraph<int> intGraph;

    intGraph.addVertex(7);
    intGraph.addVertex(9);
    intGraph.addEdge(7, 9, 100);

    std::cout << "Weight between 7 & 9: " << intGraph.getWeight(7, 9) << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}