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


/*
    // You can run into issues becuase this program does NOT have to run
    // You have to have a do loop, see below
    char inputChar = " ";
    while (inputChar == "y") {
        cout << "Please enter y to quit: ";
        cint >> inputChar;
    }
*/

/*
    // This is saying that while this is true, it will incriment by one up to 10
    // We use for loops when we know how many times we need to loop things
    // We use while loops when we don't know how many times we need to run things
    // Most purposeful infinite loops are while loops
    int counter = 0;
    while(counter < 10) {
        cout << counter << ": Hello world" << endl;
        counter++;
    }
    // This is the exact same as this for loop:
    for (int i = 0; i < 10; i++) {
        cout << i << ": Hello world" << endl;
    }
*/

/*
// First exposure to for loops
// The first part is called the initialization/declaration
// The middle part is called the conditional
// The last part is called the incriment/updatation
    for (int something = 0; something < 10; something++) {
        cout << "i: " << something << endl;
    }
*/

/*
// The i++ is signifying that each number will go up by one
// The i's are temporary variables, and the initial part (int i = 0) is intializing the variable
// Typically use i, j, k, m, or n as temp variables in the for loops
// Can be shown as... Also works with "-"
// i++;
// i = 1 + 1;
// i += 1;
// ++i;
    for (int i = 0; i > 0; i--) {
        j = j + 1;
        cout << i << ": Hello world" << endl;
        cout << "j: " << j << endl;
    }
*/

/*
// This will create an infinite loop
// It has no initialization/declaration (the beginning part)
// It has no conditional (the middle part)
// It has no incriment (the last part)/updatation
    for ( ; ; ) {
        cout << i << ": Hello world" << endl;
    }
*/

/*
This prints out..
0: Hello world!
1: Hello world!
2: Hello world! etc

   for (int i = 0; i < 10; i++) {
        cout << i << ": Hello world!" << endl;
    }
*/

/*
    for (int i = 0, j = 0; i < 10 || j > 0; i++, j--) {
        cout << i << ": Hello world!" << endl;
        cout << j << ": Goodbye world!" << endl;
    }
*/

/*
    // This is called nesting a for loop (including a loop inside a loop)
    for (int i = 0; i < 10; i++) {
        for (int j = 9; j > 0; j--) {
            cout << "i: " << i << " j: " << j << endl;
        }
    }
*/

    return 0;
}

void userInput(string &userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "\nWelcome " << userName << " to my program!\n" << endl;
}
    