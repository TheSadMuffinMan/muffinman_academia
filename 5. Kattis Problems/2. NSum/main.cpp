// https://open.kattis.com/problems/nsum
/*
COMPLETE 6/27/24, first try.

INPUT:
    The first line of the input contains an integer N(2 < N < 10), the number of integers your program should add.
    The next line contains the N integers to add, each between 0 and 1000.

OUTPUT:
    Output a single integer – the sum of the N integers from the input.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::size_t loopSize = 0;
    std::cin >> loopSize;

    while ((loopSize <= 1) || (loopSize >= 21))
    {
        std::cout << "Invalid loop size, try again: ";
        std::cin >> loopSize;
    }

    std::size_t result = 0;
    std::size_t tempVar = 0;
    for (std::size_t i = 0; i < loopSize; i++)
    {
        std::cin >> tempVar;
        result = result + tempVar;
    }

    std::cout << result;

    return 0;
}