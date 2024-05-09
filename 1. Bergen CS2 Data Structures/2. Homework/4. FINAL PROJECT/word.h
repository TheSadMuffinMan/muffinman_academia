/*
Fully Complete? 5-9-24
Not tested.
*/

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Word
{
private:
    string _word;
    int _counter;

public:
    Word(); // Complete.
    Word(string tmpWord, int tmpCounter); // Complete.

    bool operator==(const Word &otherWord); // Complete.
    bool operator<(const Word &otherWord); // Complete.
    bool operator>(const Word &otherWord); // Complete.
    Word operator++(int); // Complete.

    friend ostream &operator<<(ostream &os, const Word &tmpWord)
    {
        os << tmpWord._word << ":" << tmpWord._counter;
        return os;
    }
};

// Default constructor, set word to "" and counter to 1
Word::Word()
{
    _word = "";
    _counter = 1;
}

// Parameterized constructor
Word::Word(string tmpWord, int tmpCounter)
{
    _word = tmpWord;
    _counter = tmpCounter;
}

/*
Bergen: {
    Return a constructed word with the counter incremented
    You do not need to worry about the counter parameter since this will have its own _counter
    }

The int counter data is more or less useless data.
    It is only included because the ++ operator requires a parameter?
*/
Word Word::operator++(int counter)
{
    Word::_counter = _counter + 1;
    return Word(_word, _counter);
}

// Check if two Words are equal (compare _word)
bool Word::operator==(const Word &otherWord)
{
    if (_word == otherWord._word)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Check if (*this) is less than otherWord
bool Word::operator<(const Word &otherWord)
{
    if (_word < otherWord._word)
    {
        return true;
    }
    
    return false;
/*
WOH THERE cowgirl, the below code is unnecessary because we have access to the <string> library/class.
    The <string> class/library overloads basic strings and does the comparisons for us, meaning that we
        do not need to to break them down into chars and compare them ourselves.
The below code is what you would do if we did not have access to <string>.

    size_t charIndex = 0;
    char originalChar = _word.at(charIndex);
    char compareChar = otherWord._word.at(charIndex);
    
    while (originalChar == compareChar)
    {
        charIndex++;
        originalChar = _word.at(charIndex);
        compareChar = otherWord._word.at(charIndex);
        
        if (originalChar < compareChar)
        {
            return true;
        }
    }
*/
}

// Check if this is greater than otherWord
bool Word::operator>(const Word &otherWord)
{
    if (_word > otherWord._word)
    {
        return true;
    }
    
    return false;
}