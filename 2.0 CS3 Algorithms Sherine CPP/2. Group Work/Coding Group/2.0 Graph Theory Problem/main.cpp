/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start.\n" << std::endl;

    DirectedGraph<int> workingGraph = DirectedGraph<int>("inputFile.txt");
    std::cout << "Completing \"constructor\"?" << std::endl;

    std::cout << "Weight between 0 & 8: " << workingGraph.getWeight(0, 8);

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}