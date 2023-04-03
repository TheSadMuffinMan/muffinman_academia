/*
Name: Anthony Streich
Date: 3 April 2023
Homework 5: Guess the Number
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;

void userInput(string&);
void greetUser(string userName);

int main(int argc, char *argv[]) {
    string userName;
    userInput(userName);
    greetUser(userName);

    return 0;
}

void userInput(string& userName) {
    cout << "Welcome to --Guess the Number-- Game!" << endl;
    cout << "\nWhat is your name? " << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "\nHello, " << userName << ". I am thinking of a number between 1 and 20." << endl;
    cout << "You get 6 tries to guess the number. Take a guess.\n" << endl;
}