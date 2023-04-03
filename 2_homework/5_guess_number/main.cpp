/*
Name: Anthony Streich
Date: 3 April 2023
Homework 5: Guess the Number
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void userInput(string&);
void greetUser(string userName);
void randomNumber(int);


int main(int argc, char *argv[]) {
    string userName;
    int actualRandomVar;
    int tempVar = actualRandomVar;
    userInput(userName);
    greetUser(userName);

    randomNumber(actualRandomVar);

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

void randomNumber(int tempVar){
    int randomNumber = (rand() % 20);
    cout << "DEBUG rand num is: " << randomNumber << endl;
}
