/*
Takes in a string and then displays how many vowels are inside it
Loops through string, incrimenting at every char, and when a vowel is detected, a counter is incrimented
Also uses tolower() to "clean" the user input
IMPORTANT LEARNING LESSON: toupper() and tolower() ONLY work on chars, so you have to loop through a string to "clean" them
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string input, cleanedInput;
    int counter = 0;
    getline(cin, input); // works

    cleanedInput = input; // This "cleans" the input so that the conditional will like it
    cout << "DEBUG cleanedInput: " << cleanedInput << endl;

    for (size_t i = 0; i < cleanedInput.length(); i++) {
        if ((cleanedInput[i] == 'a') || (cleanedInput[i] == 'e') || (cleanedInput[i] == 'i') || (cleanedInput[i] == 'o') || (cleanedInput[i] == 'u')) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}