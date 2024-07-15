#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    const std::size_t maxSize = 100;

    std::string inputString = "y";
    getline(std::cin, inputString);

    std::string wordArray[maxSize];
    for (std::size_t x = 0; x < maxSize; x++)
    {
        wordArray[x] = "x";
    }

    std::size_t stringStartPos = 0;
    std::size_t stringEndPos = 0;
    for (std::size_t i = 0; i < maxSize; i++)
    {
        stringEndPos = inputString.find(' ', stringStartPos);
        std::string indivWord = inputString.substr(stringStartPos, ());
    }

    return 0;
}