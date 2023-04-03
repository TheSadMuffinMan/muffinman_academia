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

    // Generates the random number
    actualRandomVar = randomNumber(actualRandomVar);

    // Takes in user's guess
    readNumber(userGuess);

    // Compares two numbers
    checkGuess(actualRandomVar, userGuess);

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
    cout << "\nTake a guess.\n" << endl;
    cin >> userGuess;
    cout << "You guessed: " << userGuess << endl;
    return userGuess;
}

// Compares two numbers
int checkGuess(int num1, int num2){
    cout << "num1: " << num1 << " and num2: " << num2 << endl;
    if (num1 == num2) {
        cout << "Your nums are equal\n";
        return 0;
    } else if (num1 < num2) {
        cout << "actualRandomVar is smaller\n";
        return -1;
    } else if (num1 > num2) {
        cout << "actualRandomVar is larger\n";
        return 2;
    } else {
        cout << "***ERROR***" << endl;
    }
}

void game(){
    cout << "."
}