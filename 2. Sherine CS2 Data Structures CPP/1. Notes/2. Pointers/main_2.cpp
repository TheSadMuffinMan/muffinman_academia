// Write C++ code for pattern matching using cstring using dynamic memory and remember to clean up the
// memory before terminating. Assume null terminated cstrings.

/*
pattern: "abcdefg.hijk"
text:    "abcdefgzhijk"
*/

#include <cstring>
#include <iostream>
using namespace std;

// Function to perform pattern matching using dynamic programming
bool matchPattern(const char *text, const char *pattern)
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    if (textLength != patternLength)
    {
        return false;
    }

    bool *charIsAMatch = new bool[textLength];

    int i = 0;
    while (i < textLength)
    {
        // Do check here
        if (text[i] == pattern[i])
        {
            charIsAMatch[i] = true;
        }
        else if (pattern[i] == '.')
        {
            charIsAMatch[i] = true;
        }
        else
        {
            charIsAMatch[i] = false;
        }

        i += 1;
    }

    bool match = true;
    for (i = 0; i < textLength; i++)
    {
        if (!charIsAMatch[i])
        {
            match = false;
        }
    }
    delete[] charIsAMatch;
    return match;
}

int main()
{
    int patternMaxSize = 128;
    int textMaxSize = 128;

    char *pattern;
    char *text;

    pattern = new char[patternMaxSize];
    text = new char[textMaxSize];

    if (pattern == nullptr || text == nullptr)
    {
        cout << "Failed to allocate memory.\n";
        return 1;
    }

    // Prompt the user for a pattern
    cout << "Please enter a pattern:" << endl;
    cin.getline(pattern, patternMaxSize);

    // Prompt the user for a string
    cout << "Please enter a string to match against the pattern:" << endl;
    cin.getline(text, textMaxSize);

    // Call matchPattern with the received info
    bool output;
    output = matchPattern(text, pattern);

    // Output whether it was a match or not
    if (output)
    {
        cout << "The pattern matched the text!" << endl;
    }
    else
    {
        cout << "The pattern did not match the text." << endl;
    }

    // Clean up any dynamically allocated memory
    delete[] pattern;
    delete[] text;

    return 0;
}
