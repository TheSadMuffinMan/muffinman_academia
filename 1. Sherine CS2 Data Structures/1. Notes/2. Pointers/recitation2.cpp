#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char* str;
    int strLen;
    int len;
    char ch;

    cout << "Enter a string: ";
    ch = cin.peek(); // Read the newline character
    strLen = 100; // Initial size of the string
    str = new char[strLen + 1];
    cin.getline(str, strLen + 1);
    cout << endl;

    // Calculate the actual length of the entered string
    len = (int)strlen(str);

    // Forward iteration
    cout << "String in upper case letters:" << endl;
    char* ptr = str; // Initialize a pointer to the start of the string

    while (*ptr)
    {
        cout << static_cast<char>(toupper(*ptr)); // Access the current character using the pointer
        ptr++; // Move the pointer to the next character
    }
    cout << endl;

    // Backwards iteration
    cout << "String in upper case letters (backwards):" << endl;

    ptr = str + len - 1; // Initialize a pointer to the last character

    while (ptr >= str)
    {
        cout << static_cast<char>(toupper(*ptr)); // Access the current character using the pointer
        ptr--; // Move the pointer to the previous character
    }

    cout << endl;
    delete[] str; // Clean up the dynamic memory
    
    return 0;
}