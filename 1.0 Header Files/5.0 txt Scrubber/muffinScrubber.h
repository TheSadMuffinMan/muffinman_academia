#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>

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
    std::cout << "\n[DEBUG FUNCTION] Attempting to call logData()." << std::endl;
    logData();
}

/*
Function reads data from a source std::string documentName.
The variable std::stopString is used when we only want to stop reading in data at a certain point
    within documentName.
Function assumes that documentName is a valid document.

• Want an overloaded function that can read in all data (w/o stopString, is more useful general case).
*/
void MuffinTXTscrubber::readData(std::string documentName, std::string stopString)
{
    int lineCounter = 0;

    // ***DEBUG***
    documentName = "Testing.txt";
    std::cout << "[DEBUG] readData() documentName = \"Testing.txt\"." << std::endl;

    std::ifstream inputStream;
    inputStream.open(documentName);
    if (!inputStream.is_open())
    {
        std::cout << "[ERROR] " << documentName << " failed to open. Program aborting." << std::endl;
        return;
    }

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

// Function logs general data in log.txt.
void MuffinTXTscrubber::logData()
{
    std::ofstream logStream;
    logStream.open("log.txt", std::ios::app);
    if (!logStream.is_open())
    {
        std::cerr << "Log stream failed to open, aborting." << std::endl;
        return;
    }

    // Getting the current time from Chrono Library.
    auto now = std::chrono::system_clock::now();

    // Casting "now" to time_t type.
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Converting "now_time_t" to a tm struct.
    std::tm now_tm = *std::localtime(&now_time_t);

    logStream << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "]";

    logStream << " Logging second general event." << std::endl;
    logStream.close();

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

// Helper function that returns whether or not a period is allowed.
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
[WORKING] Function takes in a word and scrubs it based off of assignment parameters.
    PARAMETERS:
• Capitolization does not matter -- std::toLower() everything.
• Hypens DO matter, but double hypens can be shortened to single hypens.
*/
void MuffinTXTscrubber::_scrubWord(std::string &word)
{
    // Removing leading and trailing non-alphabetic characters.
    while ((!word.empty()) && (!isalpha(word.front())))
    {
        word.erase(0, 1); // Remove the leading non-alphabetic character.
    }
    while ((!word.empty()) && (!isalpha(word.back())))
    {
        word.pop_back();
    }

    // Converting the word to lowercase.
    for (int i = 0; i < word.size(); i++)
    {
        word.at(i) = std::tolower(word.at(i));
    }

    size_t pos = 0;
    // Replacing double hyphens with single hyphens.
    while ((pos = word.find("--", pos)) != std::string::npos)
    {
        word.replace(pos, 2, "-");
    }
}
