#include <iostream>
#include <cmath>

std::size_t twoDSize(std::string);
void decryptString(std::string);

int main(int argc, char *argv[])
{
    std::size_t numLines = 0;
    std::cin >> numLines;

    std::string inputStringArray[numLines];
    for (std::size_t x = 0; x < numLines; x++) {inputStringArray[x] = "x";} // Populating inputStringArray.

    std::cin.ignore(1);
    for (std::size_t i = 0; i < numLines; i++)
    {
        getline(std::cin, inputStringArray[i]);
    }
    // WORKING AS INTENDED TO THIS POINT.

    decryptString(inputStringArray[0]);


    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

// Function determines the appropriate size for a 2D array for the passed string.
std::size_t twoDSize(std::string inputString)
{
    std::size_t returnNum = std::ceil(sqrt(inputString.size()));
    return returnNum;
}

void decryptString(std::string inputString)
{
    // Determine array "square size".
    // Split input string into equal substrings.
    // Populate 2D array with each substring.
    // Walk backwards through 2D array and print ea. char.

    std::size_t twoDArraySize = twoDSize(inputString);

    char charArray[twoDArraySize][twoDArraySize];
    std::size_t arrayIndex = 0;
    for (std::size_t x = 0; x < twoDArraySize; x++)
    {
        for (std::size_t y = 0; y < twoDArraySize; y++)
        {
            charArray[x][y] = inputString.at(arrayIndex);
            arrayIndex++;
        }
    }
    // FUNCTION WORKING AS INTENDED TO THIS POINT.

    // DEBUGGING
    for (std::size_t x = 0; x < twoDArraySize; x++)
    {
        for (std::size_t y = 0; y < twoDArraySize; y++)
        {
            std::cout << charArray[x][y] << " ";
        }

        std::cout << std::endl;
    }

    for (std::size_t x = twoDArraySize; x > 0; x--)
    {
        for (std::size_t y = 0; y < twoDArraySize; y++) // (std::size_t y = twoDArraySize; y > 0; y--)
        {
            std::cout << charArray[x][y] << " ";
        }

        std::cout << std::endl;
    }

}