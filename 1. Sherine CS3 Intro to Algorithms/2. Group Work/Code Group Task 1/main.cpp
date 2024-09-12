#include <iostream>
#include "client.h"
// N = 1000; Have tested up to 1,000,000 so far

int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;

    unionClient* workingClient = new unionClient; // Declaring on the heap.
    workingClient->Union(1,2);
    std::cout << std::boolalpha << "Nodes 1 & 2 are connected: " << workingClient->connected(1,2) << std::endl;
    std::cout << "Nodes 2 & 3 are connected: " << workingClient->connected(2,3) << std::endl;


    delete workingClient;
    std::cout << "\nEnd of program." << std::endl;
}