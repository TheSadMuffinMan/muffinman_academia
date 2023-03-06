/*
Name: Anthony Streich
Date: 6 Feb 2023
Making a multiplication table

*/

#include <iostream>
#include <string>

// Used for printf
#include <cstdio>

// Used for setw()
#include <iomanip>

using namespace std;

void userInput(string&);
void greetUser(string userName);
void printTable(height, width);
void promptSize(int, int);

int main(int argc, char *argv[]) {
    string userName;
    int height, width;

    userInput(userName);
    greetUser(userName);
    printTable(height, width);

    promptSize(height, width);

    return 0;
}

void promptSize(int& height, int& width) {
    cout << "How tall do you want your table to be? ";
    cin >> height;

    cout << "How wide do you want your table? ";
    cin >> width;
}

void printTable(int height, int width) {
    for(int i=1; i<= height; i++) {
        // Can also use (int j=1; j<11; j++), they're functionally the same
        for(int j=1; j<= width; j++) {
            cout << setw(5) << (j*i);
        }
        cout << endl;
    }
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    printf("Welcome %s to my multiplication table printer!\n", userName.c_str());
    // cout << "Welcome " << userName << " to my program!\n" << endl;
}
    