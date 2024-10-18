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