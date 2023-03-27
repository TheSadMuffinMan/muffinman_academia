/*
Name: Anthony Streich
Date: 27 March 23
Homework 4
CURRENT ISSUES:
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void userInput(string&);
void greetUser(string userName);
int totalSum(int, int, int, int, int);

int main(int argc, char *argv[]) {
    string userName;
    userInput(userName);
    greetUser(userName);

    cout << "Press enter to quit: ";
    cin.get();
    return 0;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // Choose between the two
    // printf("Welcome %s to our multiplication table printer!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}

int totalSum(int num1, int num2, int num3, int num4, int num5){
    
}