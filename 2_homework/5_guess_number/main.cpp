/*
Name: Anthony Streich
Date: 3 April 2023
Homework 5: Guess the Number
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>

using namespace std;

void userInput(string&);
void greetUser(string userName);
int randomNumber(int&);
int readNumber(int&);
int checkGuess(int, int);
void game(string);


int main(int argc, char *argv[]) {
    string userName;

    // Introduction stuff
    userInput(userName);
    greetUser(userName);

    char quitChar = 'a';

    do {
    // Where the actual game is played
    game(userName);
    cout << "Would you like to play again? Enter [y/Y] to play again, and anything else to quit. " << endl;
    cin >> quitChar;
    quitChar = tolower(quitChar);
    } while (quitChar == 'y');

    return 0;
}

void userInput(string& userName) {
    cout << "Welcome to --Guess the Number-- Game!" << endl;
    cout << "\nWhat is your name? " << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "\nHello, " << userName << ". I am thinking of a number between 1 and 20. ";
    cout << "You get 6 tries to guess the number.\n";
}

// Generates the random number
int randomNumber(int& actualRandomVar){
    actualRandomVar = (rand() % 20);
    cout << "***DEBUG*** actualRandomVar is: " << actualRandomVar << endl;
    return actualRandomVar;
}

// Takes in user's guess
int readNumber(int& userGuess) {
    cout << "\nTake a guess." << endl;
    cin >> userGuess;

    // Checks to see if input is between 1 and 20
    while (userGuess < 0 || userGuess > 21) {
        cout << "Invalid input. Please enter a number between 1 and 20. \n" << endl;
        cin >> userGuess;
    }
    return userGuess;
}

// Compares two numbers
int checkGuess(int num1, int num2){
    if (num1 == num2) {
        return 0;
    } else if (num1 < num2) {
        // Your guess is too high
        return -1;
    } else if (num1 > num2) {
        // Your guess is too low
        return 2;
    } else {
        cout << "***ERROR***" << endl;
    }
}

// Where the actual game is played
void game(string userName){
    int actualRandomVar;
    int userGuess;
    int numberOfGuesses = 0;
    int maxGuesses = 6;
    int numChecker;
    bool userWin = false;

    // Generates the random number
    actualRandomVar = randomNumber(actualRandomVar);

    for (int i = 0; i < maxGuesses; i++) {
        numberOfGuesses++;
        // Takes in user's guess
        readNumber(userGuess);
        cout << (6 - numberOfGuesses) << " guess(es) remaining." << endl;

        // Compares two numbers
        numChecker = checkGuess(actualRandomVar, userGuess);


        if (numChecker == 0) {
            userWin = true;
            break;
        } else if (numChecker == -1) {
            cout << "Your guess is too high!" << endl;
        } else if (numChecker == 2) {
            cout << "Your guess is too low!" << endl;
        } else {
        cout << "***BUG***";
        }
    }

    if (userWin == true) {
        cout << "Congratulations " << userName << ", YOU WIN! You guessed my number in " << numberOfGuesses  << " guesses.\n" << endl;
    } else {
        cout << "You did not guess the number, which was " << actualRandomVar << ".\n" << endl;
    }
}