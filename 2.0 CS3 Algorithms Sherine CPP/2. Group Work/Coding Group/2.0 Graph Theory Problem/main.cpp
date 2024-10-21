/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start.\n" << std::endl;

    DirectedGraph<int> workingGraph = DirectedGraph<int>("inputFile.txt");


    std::cout << "\nEnd of program." << std::endl;
    return 0;
}