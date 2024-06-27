// https://open.kattis.com/problems/oddities
/*
COMPLETE 6/27/24

INPUT:
    Input begins with an integer (1 <= n <= 20) on a line by itself, indicating the number of test cases
        that follow. Each of the following n lines contain a test case consisting of a single
        integer -10 <= x <= 10.

OUTPUT:
    For each x, print either ‘x is odd’ or ‘x is even’ depending on whether x is odd or even.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::size_t loopSize = 0;
    std::cin >> loopSize;

    int userVar, compareVar;

    for (std::size_t i = 0; i < loopSize; i++)
    {
        std::cin >> userVar;
        compareVar = userVar % 2;

        if ((compareVar == 1) or (compareVar == -1))
        {
            std::cout << userVar << " is odd" << std::endl;
        }
        else
        {
            std::cout << userVar << " is even" << std::endl;
        }
    }

    return 0;
}