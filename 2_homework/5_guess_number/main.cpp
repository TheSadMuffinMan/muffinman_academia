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
void randomNumber(int&);
int readNumber(int&);


int main(int argc, char *argv[]) {
    string userName;
    int temp = 0;
    int actualRandomVar;
    int userGuess;

    // Introduction stuff
    userInput(userName);
    greetUser(userName);

    // Generates the random number
    randomNumber(actualRandomVar);

    // Takes in user's guess
    readNumber(temp);

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
void randomNumber(int& actualRandomVar){
    actualRandomVar = (rand() % 20);
    cout << "***DEBUG*** rand num is: " << actualRandomVar << endl;
}

// Takes in user's guess
int readNumber(int& userGuess) {
    cout << "\nTake a guess.\n" << endl;
    cin >> userGuess;
    cout << "You guessed: " << userGuess << endl;
    return userGuess;
}