#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

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

        void readData(std::string, std::string);
        void logData();
        void addWord(std::string);
    
    private:
        std::vector<std::string> *_masterData;
        // std::map<std::string,int> *_masterData;
};

muffinTXTscrubber::muffinTXTscrubber()
{
    _masterData = new std::vector<std::string>;
}

muffinTXTscrubber::~muffinTXTscrubber()
{
    delete _masterData;
}

/* *****NOT FINISHED*****
• Want an overloaded function that can read in all data (w/o stopString).

Function assumes document name has been scrubbed.
*/
void muffinTXTscrubber::readData(std::string documentName, std::string stopString)
{
    int lineCounter = 0;

    // ***DEBUG***
    documentName = "Testing.txt";
    std::cout << "[DEBUG] readData() documentName = \"Testing.txt\"." << std::endl;

    std::ifstream inputStream;
    inputStream.open(documentName);

    std::string workingString;
    /*
    While we are able to pull lines of input...
    The reason why we can't just stream in every word is because our program needs to load different
        data structures at different points.
    */
    while (!inputStream.eof())
    {
        std::getline(inputStream, workingString);
        ++lineCounter;

        if (workingString == stopString)
        {
            std::cout << "[INFO] readData() halted, stopString located at line " << lineCounter << "." << std::endl;
            return;
        }

        while (workingString.size() > 0)
        {
            std::string word = " ";
            int spaceIndex = 0;

            // If there is no space found in string...
            if (workingString.find(" ") == std::string::npos)
            {
                break;
            }

            spaceIndex = workingString.find(" ");

            word = workingString.substr(0, spaceIndex);
            // std::cout << "[INFO] word = " << word << std::endl;
            _masterData->push_back(word);

            // Deleting word from workingString.
            workingString = workingString.substr(spaceIndex + 1);
            // std::cout << "[INFO] Remaining string: " << workingString << std::endl;
        }
    }

/*
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
*/
}

void muffinTXTscrubber::addWord(std::string word)
{
    bool wordExists = false;

    //
}
