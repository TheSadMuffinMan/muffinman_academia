#include <iostream>
#include "client.h"
// N is imported from "client.h" and is = 1000.

int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;

    unionClient* workingClient = new unionClient; // Declaring on the heap.
    workingClient->Union(1,2);
    delete workingClient;

    std::cout << "\nEnd of program." << std::endl;
}