/* OBJECTIVES:
Complete objectives:
    - Implement a data structure that supports Union(p,q); COMPLETE.
    - Implement Find(p); COMPLETE.
    - Implement Connected(p,q); COMPLETE.
    - PART 2; COMPLETE.

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

TO DO LIST FOR ME:
    - Finish PART 3.
    - Assemble information into an educational/Sherine format.
    - Send all info to Dawson for parts 2 & 3.
*/

/* DELIVERABLES:
The code used to complete the project. Classes should be broken up into their respective header and cpp files.
A LaTeX document explaining your algorithm's time complexity analysis and any optional features you implemented.
*/

#include "client.h"
#include <chrono>
#include <cmath>

typedef std::chrono::steady_clock Time;// Makes it to where we don't have to type this bs every time.

int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;
    int numElements = 800; // N.
    int numOperations = 400; // M.

    int numIterations = 0;
    std::cout << "How many iterations would you like?: ";
    std::cin >> numIterations;

    auto timeStart = Time::now();
    for (int i = 0; i < numIterations; i++)
    {
        UnionClient workingUserClient;
        workingUserClient.randomMandN(numElements, numOperations);
    }
    auto timeStop = Time::now();
    auto duration = Time::duration(timeStop - timeStart);

    std::cout << "\nWith..." << std::endl;
    std::cout << "\tN = " << numElements << std::endl;
    std::cout << "\tM = " << numOperations << std::endl;
    std::cout << "\tNum Iterations: " << numIterations << std::endl;

    std::cout << "\nEstimated run-time (Mlog(N)): " << (numOperations * std::log10(numElements)) <<
        " microseconds." << std::endl;
    std::cout << "Average run-time: " << (duration.count() / numIterations) << " nanoseconds." << std::endl;
    std::cout << "(1 microsecond = 1000 nanoseconds)" << std::endl;

    std::cout << "\nEnd of program." << std::endl;
}