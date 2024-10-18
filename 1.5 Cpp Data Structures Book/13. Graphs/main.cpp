/*
Program is the driver client for DirectedGraph Class.
*/
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

    intGraph.addVertex(20);
    intGraph.addEdge(20, 9, 3);
    std::cout << "Weight between 20 & 9: " << intGraph.getWeight(20, 9) << std::endl;

    std::cout << "Vertex 20 has been visited: " << std::boolalpha <<intGraph.isMarked(20);
    std::cout << "\nVisiting Vertex 20..." << std::endl;
    intGraph.markVertex(20);
    std::cout << "Vertex 20 has been visited: " << std::boolalpha << intGraph.isMarked(20);


    std::cout << "\nEnd of program." << std::endl;
    return 0;
}