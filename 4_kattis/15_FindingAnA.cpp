/*
Searches a string up until a char, then takes away anything preceeding it.
IMPORTANT LEARNING LESSON: This is how to use the substr() function appropriately
string.substr(startIndex, length)
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    char findChar = 'a'; // Determines which char will be found
    cin >> input;

    size_t pos = input.find(findChar);
    unsigned long temp = (input.length() - pos); // This matches the data type that pos is so that the compiler doesn't bitch
    cout << input.substr(pos, temp) << endl;

    return 0;
}