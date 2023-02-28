/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
*/

#include <iostream>
#include <string>

using namespace std;

void userInput(string&);
void greetUser(string userName);

int main() {
    string userName;

    userInput(userName);
    greetUser(userName);

    return 0;
}

void userInput(string &userName) {
    cout << "Please enter your name, and then press enter.\n" << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "Welcome " << userName << " to my program!" << endl;
}
    