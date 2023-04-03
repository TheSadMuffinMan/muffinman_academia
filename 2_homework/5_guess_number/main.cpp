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
void game();


int main(int argc, char *argv[]) {
    string userName;
    int actualRandomVar;
    int userGuess;

    // Introduction stuff
    userInput(userName);
    greetUser(userName);

    game();

    return 0;
}

void userInput(string& userName) {
    cout << "Welcome to --Guess the Number-- Game!" << endl;
    cout << "\nWhat is your name? " << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "\nHello, " << userName << ". I am thinking of a number between 1 and 20." << endl;
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
    return userGuess;
}

// Compares two numbers
int checkGuess(int num1, int num2){
    if (num1 == num2) {
        cout << "Your nums are equal\n";
        return 0;
    } else if (num1 < num2) {
        cout << "The random value is smaller\n";
        return -1;
    } else if (num1 > num2) {
        cout << "The random value is larger\n";
        return 2;
    } else {
        cout << "***ERROR***" << endl;
    }
}

void game(){
    int actualRandomVar;
    int userGuess;
    int numberOfGuesses = 0;
    int maxGuesses = 6;
    int numChecker;

    // Generates the random number
    actualRandomVar = randomNumber(actualRandomVar);

    for (int i = 0; i < maxGuesses; i++) {
        numberOfGuesses++;
        // Takes in user's guess
        readNumber(userGuess);
        cout << "You have guessed " << numberOfGuesses << " times. " << (6 - numberOfGuesses) << " guess(es) remaining." << endl;

        // Compares two numbers
        numChecker = checkGuess(actualRandomVar, userGuess);
        if (numChecker == 0) {
            break;
        }
    }
}