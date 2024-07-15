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
        std::string indivWord = inputString.substr(stringStartPos, (stringEndPos - stringStartPos));
        
        for (std::size_t j = 0; j < indivWord.size(); j++) // Sanitizing string.
        {
            indivWord.at(j) = toupper(indivWord.at(j));
        }

        wordArray[i] = indivWord;
        stringStartPos = stringEndPos + 1;
        // WORKING AS INTENDED TO THIS POINT.
    }

    for (std::size_t i = 0; i < maxSize; i++)
    {
        if (wordArray[i] == "x")
        {
            std::cout << "\nEND OF ARRAY." << std::endl;
            break;
        }
        else
        {
            std::cout << wordArray[i] << std::endl;
        }
    }

    return 0;
}