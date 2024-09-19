/* OBJECTIVES:
Complete objectives:
    - Implement a data structure that supports Union(p,q); COMPLETE.
    - Implement Find(p); COMPLETE.
    - Implement Connected(p,q); COMPLETE.

Incomplete objectives:
    - Provide a graph that demonstrates >= 11 Union Operations;
    - Given a set of N individual elements/Nodes, have the capability to utilize M operations, where each operation
        is either Union(a,b) or find(a).
    - Algorithm Analysis: Analyze the time complexity of your solution in terms of N (the number of elemens/Nodes)
        and M (the number of operations). Discuss the efficiency of your algorithm and any potential optimizations.
Extra Credit Tasks:
    - Implement a stack and a queue data structure using self-resizing arrays.
    - Demonstrate how you can use these stack and queue data structures to solve simple problems, such as...
        - Reversing a non-trivial string using a stack.
        - Simulating a queue using two stacks.
*/

/* DELIVERABLES:
The code used to complete the project. Classes should be broken up into their respective header and cpp files.
A LaTeX document explaining your algorithm's time complexity analysis and any optional features you implemented.
*/

#include <iostream>
#include "client.h"

// N = 1000; Have tested up to 1,000,000 so far

int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;

    UnionClient* workingClient = new UnionClient; // Declaring on the heap.
    workingClient->Union(1,2);
    std::cout << std::boolalpha << "Nodes 1 & 2 are connected: " << workingClient->connected(1,2) << std::endl;
    std::cout << "Nodes 2 & 3 are connected: " << workingClient->connected(2,3) << std::endl;


    delete workingClient;
    std::cout << "\nEnd of program." << std::endl;
}