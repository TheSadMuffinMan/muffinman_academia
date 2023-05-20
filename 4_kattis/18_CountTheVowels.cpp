/*
Takes in a string and then displays how many vowels are inside it
Loops through string, incrimenting at every char, and when a vowel is detected, a counter is incrimented
Also uses tolower() to "clean" the user input
IMPORTANT LEARNING LESSON: toupper() and tolower() ONLY work on chars, so you have to loop through a string to "clean" them
*/

#include <iostream>
#include <string>

using namespace std;

void cleanInput(string&);

int main(int argc, char *argv[]) {
    string input;
    int counter = 0;
    getline(cin, input);

    cleanInput(input); // cleans the input for the upcoming conditional

    for (size_t i = 0; i < input.length(); i++) { // Performs the logic to "detect" vowels
        if ((input[i] == 'a') || (input[i] == 'e') || (input[i] == 'i') || (input[i] == 'o') || (input[i] == 'u')) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}

void cleanInput(string& input) {  // This "cleans" the input so that the conditional will like it
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
}