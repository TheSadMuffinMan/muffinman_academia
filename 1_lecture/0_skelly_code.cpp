/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
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
    // printf("Welcome %s to my program!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}