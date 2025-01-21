/*
Program takes in names seperated by hyphens, and then returns the first chars of their names combined together
Uses a loop to search a string for hyphens, then adds the char following it to the output
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    getline(cin, input);

    string output = input.substr(0, 1);
    size_t loopLength = input.length();

    for (size_t i = 0; i < loopLength; i++) {
        if (input[i] == '-') {
            output = (output + (input[i +1]));
        }
    }
    
    cout << output << endl;

    return 0;
}