// https://open.kattis.com/problems/modulo
/*
6/28/24 COMPLETE

INPUT:
    The input will contain 10 non-negative integers, each smaller than 1000, one per line.

OUTPUT:
    Output the number of distinct values when considered modulo 42 on a single line.

    Program wants you to perform Modulus (%) on each of the 10 input ints, and then return
        the number of unique ints from each Modulus operation.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    int resultArray[10];
    for (std::size_t k = 0; k < 10; k++) // Filling array with -1's.
    {
        resultArray[k] = -1;
    }

    int comparisonInt, resultInt;
    std::size_t numUniqueInts = 0;

    for (std::size_t i = 0; i < 10; i++)
    {
        std::cin >> comparisonInt;
        resultInt = comparisonInt % 42;

        for (std::size_t j = 0; j < 10; j++) // Dropping resultInt into resultArray[].
        {
            if (resultArray[j] == resultInt)
            { // If an int is a duplicate.
                break;
            }
            else if ((resultArray[j] >= 0) && (resultArray[j] < 1000))
            { // If an int is already inside resultArray[].
                continue;
            }
            else
            {
                resultArray[j] = resultInt;
                numUniqueInts++;
                break;
            }
        }
    }

    std::cout << numUniqueInts << std::endl;

    return 0;
}