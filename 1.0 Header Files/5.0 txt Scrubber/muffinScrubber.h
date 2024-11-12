#pragma once
#include <iostream>
#include <map>

/*
Class stores data in a std::map.
• The map data structure is a Red-Black BST.

Pairs are as follows:
<(std::string)Word, (int)WordCount>

PLANNED FUNCTIONALITY:
• Class should print out words in alphabetical order in an output file.
• (next)
*/
class muffinTXTscrubber
{
    public:
        muffinTXTscrubber();
        ~muffinTXTscrubber();

        void readData(std::string);
        void logData();
        void addWord(std::string);
    
    private:
        std::map<std::string,int> *_masterData;
};

muffinTXTscrubber::muffinTXTscrubber()
{
    _masterData = new std::map<std::string, int>;
}

muffinTXTscrubber::~muffinTXTscrubber()
{
    delete _masterData;
}

void muffinTXTscrubber::readData(std::string documentName)
{
    // Scrubbing screen.
    
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


