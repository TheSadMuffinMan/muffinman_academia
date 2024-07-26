#include <iostream>

int64_t* buildFibonacci(int64_t*, int);

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

        if (currNum > largestInput) // largestNum is used later in Fibonacci Array.
        {
            largestInput = currNum;
        }
    }

    // This array is indexed - array[0] represents 0, array[1] == 1, array[2] == 2, etc.
    int64_t fibonacciArray[largestInput];
    for (std::size_t x = 0; x < largestInput; x++) {fibonacciArray[x] = 0;} // Populating.
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

// Input largest num to populate Fibonacci Array to largest num.
int64_t* buildFibonacci(int64_t* intArray, int largestInt)
{
    // Array starts at 0, which allows for initial edge case to be avoided.
    for (std::size_t i = 0; i < largestInt; i++)
    {
        intArray[i] = intArray[i - 1] + intArray[i]; 
    }

    return intArray;
}