/*
Name: Anthony Streich
Date: 6 Feb 2023
Making a multiplication table

*/

#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

using namespace std;

void userInput(string&);
void greetUser(string userName);

int main(int argc, char *argv[]) {
    string userName;
    userInput(userName);
    greetUser(userName);

    // Starting at 0, up to ten, updating the function by 1
    for(int i=1; i<=10; i++) {
        // Can also use (int j=1; j<11; j++), they're functionally the same
        for(int j=1; j<=10; j++) {
            cout << setw(5) << (j*i);
        }
        cout << endl;
    }

    return 0;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    printf("Welcome %s to my multiplication table printer!\n", userName.c_str());
    // cout << "Welcome " << userName << " to my program!\n" << endl;
}
    