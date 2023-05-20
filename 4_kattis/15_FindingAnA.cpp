/*
Searches a string up until a char, then takes away anything preceeding it.
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    char findChar = 'a'; // Determines which char will be found
    cin >> input;

    size_t pos = input.find(findChar);
    for (auto i = pos; i < input.length(); i++) {
        cout << i;
    }
    
    cout << endl;
    return 0;
}