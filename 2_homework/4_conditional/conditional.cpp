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

void getNums(int, int, int, int, int);
int totalSum(int, int, int, int, int);

int main(int argc, char *argv[]) {
    string userName;
    userInput(userName);
    greetUser(userName);

    int n1, n2, n3, n4, n5;
    getNums(n1, n2, n3, n4, n5);

    return 0;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // Choose between the two
    // printf("Welcome %s to my program!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}

void getNums(int n1, int n2, int n3, int n4, int n5){
    cout << "Please enter 5 numbers, seperated by hitting enter: " << endl;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
}

int totalSum(int num1, int num2, int num3, int num4, int num5){
    return num1 + num2 + num3 + num4 + num5;
}