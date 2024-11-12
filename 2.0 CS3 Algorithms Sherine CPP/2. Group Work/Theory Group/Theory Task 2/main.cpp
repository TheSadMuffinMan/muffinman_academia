#include "hashChaining.h"
#include "hashLinearProbe.h"
#include <string>
#include <fstream>

void readWordChain(std::string&, HashTableChaining&);

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    HashTableChaining chainTable;
    chainTable.insertItem(3762, "the");
    chainTable.insertItem(521, "word");
    chainTable.insertItem(6113, "other");
    chainTable.insertItem(1971, "chain");
    chainTable.insertItem(22, "Orion");
    std::cout << "\nInserting repeat element..." << std::endl;
    chainTable.insertItem(3762, "the");

    std::cout << "\nPrinting table..." << std::endl;
    chainTable.printTable();

    std::cout << "\nSearching for 22..." << std::endl;
    chainTable.searchTable(22);

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

void readWordChain(std::string &inWord, HashTableChaining &table)
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

/*
    if ((argc != 3) || ((std::string)argv[1] == "A Scandal in Bohemia.txt"))
    {
        std::cerr << "[DEBUG1] Invalid input file. Program aborting." << std::endl;
        return 0;
    }

    std::ifstream inputStream;
    inputStream.open("A Scandal In Bohemia.txt");
    if (!inputStream.is_open())
    {
        std::cerr << "[DEBUG2] File failed to open. Program aborting." << std::endl;
        return 0;
    }

    std::string tempWord;
*/

/*
    while (inputStream >> tempWord)
    {
        readWordChain(tempWord, chainTable);
    }

    inputStream.close();
*/


