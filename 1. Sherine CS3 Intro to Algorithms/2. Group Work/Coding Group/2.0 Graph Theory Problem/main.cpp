/*
Program must be dynamically allocated.

Program must start by accepting a single command line argument.
    That command will be the name of the file to be opened (example.txt).
    Once file has been read into memory, the file must be closed and cannot be opened again.

The program will then prompt the user for three source vertices and destinations.
    See example below.


    EXAMPLE:
terminal@user: ../../$ Provide 3 sources: "7 19 26"

terminal@user: ../../$ Destination 1?: "32"
terminal@user: ../../$ Shortest Path 1 from vertex 7: *result*
terminal@user: ../../$ Shortest Path 2 from vertex 19: *result*
terminal@user: ../../$ Shortest Path 3 from vertex 26: *result*

terminal@user: ../../$ Destination 2?: "22"
terminal@user: ../../$ Shortest Path 1 from vertex 7: *result*
terminal@user: ../../$ Shortest Path 2 from vertex 19: *result*
terminal@user: ../../$ Shortest Path 3 from vertex 26: *result*


*/

#include "diGraph.h"
#include "node.h"
#include <iostream>
#include <fstream>
#include <chrono>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    DiGraph<int> workingGraph;
    
    std::cout << workingGraph.getIndivNode(0);
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}