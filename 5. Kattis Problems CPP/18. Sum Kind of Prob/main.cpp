#include <iostream>

int main(int argc, char *argv[])
{
    std::size_t numCases = 0;
    std::cin >> numCases;
    int currArray[numCases];
    int junkNum = 0;
    for (std::size_t x = 0; x < numCases; x++) {currArray[x] = 0;} // Populating array.

    double factorialIterator = 0; // Need a double because factorials get large very quickly.
    for (std::size_t i = 0; i < numCases; i++) // Populating currArray.
    {
        int currNum = 0;
        std::cin >> junkNum;
        std::cin >> currNum;

        currArray[i] = currNum;
    }

    for (std::size_t j = 0; j < numCases; j++)
    {
        std::cout << "***DEBUG*** currArray[" << j << "]: " << currArray[j] << std::endl;
    }
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}