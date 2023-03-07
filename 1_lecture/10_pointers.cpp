/*
Name: Anthony Streich
Date: 7 March 23
First intro to pointers
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
    // If you are creating a pointer, the pointer type has to match what it is pointing to
    // For example, if you are pointing to an int, your pointer must be int *ptr1
    int num1;
    int *ptr1;

    num1 = 42;
    ptr1 = &num1;

    cout << "&num1: " << &num1 << endl;
    cout << "ptr1: " << ptr1 << endl;
    cout << "&ptr1: " << &ptr1 << endl;

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
    