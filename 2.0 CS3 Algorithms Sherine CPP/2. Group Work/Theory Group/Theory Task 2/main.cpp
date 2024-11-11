#include "hashChaining.h" // Not included yet (for confusion's sake).
#include "hashLinearProbe.h"
#include <string>
#include <fstream>

void readWordChain(std::string&, HashChaining&);

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

void readWordChain(std::string &inWord, HashChaining &table)
{
    while ((inWord.size() > 0) && (tolower(inWord.at(0)) < 'a' || tolower(inWord.at(0)) > 'z'))
    {
        inWord.erase(0, 1); // Getting rid of punction, special chars, etc.
    }
    while (inWord.size() > 0 && (tolower(inWord.at(inWord.size() - 1)) < 'a' || tolower(inWord.size() - 1) > 'z'))
    {
        inWord.erase(inWord.size() - 1, 1);
    }

    if (inWord.size() > 0)
    {
        for (std::size_t i = 0; i < inWord.size(); i++)
        {
            inWord.at(i) = tolower(inWord.at(i));
        }
    }
}
