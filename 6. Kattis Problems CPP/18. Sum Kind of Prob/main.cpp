#include <iostream>

int64_t calculateFactorial(int64_t*, int);

int main(int argc, char *argv[])
{
    std::size_t numCases = 0;
    std::cin >> numCases;
    int currArray[numCases];
    int junkNum = 0;
    int largestInput = 0;
    for (std::size_t x = 0; x < numCases; x++) {currArray[x] = 0;} // Populating array.

    for (std::size_t i = 0; i < numCases; i++) // Populating currArray.
    {
        int currNum = 0;
        std::cin >> junkNum;
        std::cin >> currNum;
        currArray[i] = currNum;

        if (currNum > largestInput) // largestNum is used later in Factorial Array.
        {
            largestInput = currNum;
        }
    }

    // This array is indexed - array[0] represents 0, array[1] == 1, array[2] == 2, etc.
    int64_t factorialArray[largestInput];
    for (std::size_t x = 0; x < largestInput; x++) {factorialArray[x] = 0;} // Populating.

    for (int i = 1; i < largestInput; i++)
    {
        factorialArray[i] = calculateFactorial(factorialArray, i);
    }

    std::cout << std::endl;
    for (std::size_t i = 0; i < largestInput; i++)
    {
        std::cout << "***DEBUG*** fibArray[" << i << "]: " << factorialArray[i] << std::endl;
    }
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

// Must be used sequentially (meant for a for loop).
// Returns the result as an int64_t.
int64_t calculateFactorial(int64_t* factorialArray, int targetInt)
{
    return (factorialArray[(targetInt - 1)] + targetInt);
}