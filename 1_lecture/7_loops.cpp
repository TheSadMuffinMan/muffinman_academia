/*
Name: Anthony Streich
Date: 1 March 23
Loops!
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

// First exposure to for loops
/*
    for (int something = 0; something < 10; something++) {
        cout << "i: " << something << endl;
    }
    */

// The i++ is signifying that each number will go up by one
// Can be shown as... Also works with "-"
// i++;
// i = 1 + 1;
// i += 1;
// ++i;
   for (int i = 0; i < 10; i++) {
        cout << "i: " << i << endl;
    }

    return 0;
}

void userInput(string &userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "\nWelcome " << userName << " to my program!\n" << endl;
}
    