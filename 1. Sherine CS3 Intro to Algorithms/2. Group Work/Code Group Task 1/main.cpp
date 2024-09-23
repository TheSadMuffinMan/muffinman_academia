#include "client.h"
#include <chrono>
#include <cmath>

typedef std::chrono::steady_clock Time;

int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;
    int numElements = 999; // N.
    int numOperations = 1000; // M.

    int numIterations;
    std::cout << "How many iterations would you like?: ";
    std::cin >> numIterations;

    // Array that holds the time of each iteration.
    int64_t* timeArray = new int64_t[numIterations];

    for (int i = 0; i < numIterations; i++)
    {
        UnionClient workingUserClient;
        timeArray[i] = workingUserClient.randomMandN(numElements, numOperations);
    }

    auto totalRunTime = 0;
    for (int i = 0; i < numIterations; i++) // Tallying up total runtime.
    {
        totalRunTime += timeArray[i];
    }
    delete[] timeArray;

    int averageRunTime = (totalRunTime / numIterations);

    std::cout << "\nWith..." << std::endl;
    std::cout << "\tNumber of Elements (AKA \"N\") = " << numElements << std::endl;
    std::cout << "\tNumber of Union Operations (AKA \"M\") = " << numOperations << std::endl;

    std::cout << "\nEstimated run-time (N + M*ln(N)): " << (numElements + 
        (numOperations * std::log10(numElements))) << std::endl;
    std::cout << "Average run-time: " << averageRunTime << std::endl;

    std::cout << "\nEnd of program." << std::endl;
}