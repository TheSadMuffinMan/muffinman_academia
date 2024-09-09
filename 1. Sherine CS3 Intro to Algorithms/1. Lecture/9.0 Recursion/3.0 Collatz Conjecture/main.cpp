/*
The Collatz Conjecture states that if you pick a number, and if it is even divide it by 2, and if it is odd,
    multiply it by 3 and add 1.

This program is a visualization of that. Just wanted to code up the conjecture for fun lol.

OBSERVATIONS:
    Once the startingNum == a perfect square, the program enters a "recursive" loop that consists of:
        "(previous perfect squares)... -> 4 -> 2 -> 1 -> 4 -> 2 -> 1 etc";
*/

u_int32_t iterativeCollatz(u_int32_t numIterations, u_int32_t startingNum)
{
    //
}

u_int32_t recursiveCollatz(u_int32_t numIterations, u_int32_t startingNum)
{
    //
}

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    std::string dumpVar = " ";
    u_int32_t numIterations = 0; // Can store VERY large positive ints.

    std::cout << "\nHow many iterations would you like to compute?: ";
    std::cin >> numIterations;

    u_int32_t startingNum = 0;
    std::cout << "\nWhat u_int32_t would you like to start at?: ";
    std::cin >> startingNum;

    std::cout << startingNum << " -> ";
    for (u_int32_t i = 0; i < numIterations; i++)
    {
        if ((startingNum % 2) == 0) // If startingNum is even.
        {
            startingNum = (startingNum / 2);
            std::cout << startingNum << " -> ";
        } else {
            startingNum = ((3 * startingNum) + 1);
            std::cout << startingNum << " -> ";
        }
    }

    std::cout << "\nEnd of program." << std::endl;
}