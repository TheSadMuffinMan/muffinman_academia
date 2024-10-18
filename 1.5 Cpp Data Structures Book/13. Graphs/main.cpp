#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    DirectedGraph<int> intGraph;

    intGraph.addVertex(7);
    intGraph.addVertex(9);
    intGraph.addEdge(7, 9, 5);
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}