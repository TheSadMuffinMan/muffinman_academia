#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    const std::size_t maxSize = 100;

    std::string inputString = "y";
    getline(std::cin, inputString);

    std::string wordArray[maxSize];
    for (std::size_t x = 0; x < maxSize; x++) // Populating array.
    {
        wordArray[x] = "x";
    }

    std::size_t stringStartPos = 0;
    std::size_t stringEndPos = 0;
    std::size_t numWords = 0;
    for (std::size_t i = 0; i < maxSize; i++)
    {
        stringEndPos = inputString.find(' ', stringStartPos);
        std::string indivWord = inputString.substr(stringStartPos, (stringEndPos - stringStartPos));
        
        for (std::size_t j = 0; j < indivWord.size(); j++) // Sanitizing string to ALL CAPS.
        {
            indivWord.at(j) = toupper(indivWord.at(j));
        }
        
        stringStartPos = (stringEndPos + 1);

        wordArray[i] = indivWord;
        numWords++;

        if (stringEndPos >= inputString.size())
        {
            break;
        }
    }

    bool hasRepeat = false;
    // Comparing ea word to every other word inside wordArray.
    for (std::size_t i = 0; i < numWords; i++) // First loop pulls indiv word.
    {
        std::string compareWord = wordArray[i];

        for (std::size_t j = 0; j < numWords; j++) // Second loop compares indiv word to every other word.
        {
            if (j == i) // Skipping the indiv word itself inside wordArray.
            {
                continue;
            }

            if (compareWord == wordArray[j])
            {
                hasRepeat = true;
                break;
            }
        }
    }

    if (hasRepeat == true) {std::cout << "no" << std::endl;}
    else {std::cout << "yes" << std::endl;}

    return 0;
}