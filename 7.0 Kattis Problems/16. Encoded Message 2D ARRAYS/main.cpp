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
    
    for (std::size_t i = 0; i < numLines; i++)
    {
        decryptString(inputStringArray[i]);
        std::cout << std::endl;
    }

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

    // Long story short.. You gotta use integers here because of size_t's sign properties.
    for (int y = (int(twoDArraySize) - 1); y >= 0; y--)
    {
        for (int x = 0; x < int(twoDArraySize); x++)
        {
            std::cout << charArray[x][y];
        }
    }
}