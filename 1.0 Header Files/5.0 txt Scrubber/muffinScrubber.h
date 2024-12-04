#pragma once
#include <iostream>
#include <fstream>
#include <vector>

// strtok();

/*
Pairs are as follows:
<(std::string)Word, (int)WordCount>

PLANNED FUNCTIONALITY:
• Class should print out words in alphabetical order in an output file.
• (next)
*/
class MuffinTXTscrubber
{
    public:
        MuffinTXTscrubber();
        ~MuffinTXTscrubber();

        void debugFunction();
        void readData(std::string, std::string);
        void logData();
        void addWord(std::string);
    
    private:
        std::vector<std::pair<std::string, int>> *_masterData;

        bool _allowedPeriod(std::string);
        void _scrubWord(std::string&);
        // std::map<std::string,int> *_masterData;
};

MuffinTXTscrubber::MuffinTXTscrubber()
{
    _masterData = new std::vector<std::pair<std::string, int>>;
}

MuffinTXTscrubber::~MuffinTXTscrubber()
{
    // Vector automatically cleans up memory for you.
}

// Function is used to debug stuff throughout development process.
void MuffinTXTscrubber::debugFunction()
{
    std::cout << "\n[DEBUG] ";

    std::cout << "4th word is: ";
    std::cout << _masterData->at(3).first;
}

/* *****NOT FINISHED*****
• Want an overloaded function that can read in all data (w/o stopString).

Function assumes document name has been scrubbed.
*/
void MuffinTXTscrubber::readData(std::string documentName, std::string stopString)
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
            _scrubWord(word);
            addWord(word);

            // Deleting word from workingString.
            workingString = workingString.substr(spaceIndex + 1);
            // std::cout << "[INFO] Remaining string: " << workingString << std::endl;
        }
    }

}

// [WORKING] Function adds a word to _masterData.
void MuffinTXTscrubber::addWord(std::string word)
{
    bool wordExists = false;
    for (auto& pair : *_masterData)
    {
        if (pair.first == word)
        {
            pair.second++;
            wordExists = true;
            break;
        }
    }

    if (!wordExists)
    {
        _masterData->emplace_back(word, 1);
    }
}

// Function returns whether or not a period is allowed. Is used in sentence counter.
bool MuffinTXTscrubber::_allowedPeriod(std::string word)
{
    if ((word == "dr.") || (word == "mr.") || (word == "ms.") || (word == "mrs."))
    {
        return true;
    } else
    {
        return false;
    }
}

/*
Function takes in a word and scrubs it based off of assignment parameters.
PARAMETERS:
• Capitolization does not matter.
    std::toLower() everything
• Hypens DO matter, but double hypens can be shortened to single hypens.
*/
void MuffinTXTscrubber::_scrubWord(std::string &word)
{

    // Removing leading and trailing non-alphabetic characters.
    while (!word.empty() && !isalpha(word.front()))
    {
        word.erase(0, 1); // Remove the leading non-alphabetic character.
    }
    while (!word.empty() && !isalpha(word.back()))
    {
        word.pop_back(); // Remove trailing non-alphabetic character.
    }

    // Convert the word to lowercase.
    for (int i = 0; i < word.size(); i++)
    {
        word.at(i) = std::tolower(word.at(i));
    }

    size_t pos = 0;

    // Replace double hyphens with single hyphens.
    while ((pos = word.find("--", pos)) != std::string::npos)
    {
        word.replace(pos, 2, "-");
    }
/*
    while ((word.size() > 0) && (tolower(word.at(0)) < 'a' || tolower(word.at(0)) > 'z'))
    {
        word.erase(0, 1); // Getting rid of punction, special chars, etc.
    }
    while (word.size() > 0 && (tolower(word.at(word.size() - 1)) < 'a' || tolower(word.size() - 1) > 'z'))
    {
        word.erase(word.size() - 1, 1);
    }

    if (word.size() > 0)
    {
        for (std::size_t i = 0; i < word.size(); i++)
        {
            word.at(i) = tolower(word.at(i));
        }
    }
*/
}
