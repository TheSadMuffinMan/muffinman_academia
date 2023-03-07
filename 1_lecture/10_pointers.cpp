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
    // string userName;
    // userInput(userName);
    // greetUser(userName);

    int num1 = 0;
    // float fnum1;
    // string snum1;
    // char cnum1;

    // This is the C++ way of doing things for null pointers
    int *ptr1 = nullptr;
    // This is the old C way of doing things, case sensitive
    ptr1 = NULL;
    // This will also work
    ptr1 = __null;

    if (ptr1 == NULL) {
        ptr1 = &num1;
    }

    cout << "&num1: " << &num1 << endl;
    cout << "ptr1: " << ptr1 << endl;

    /*
    // If you are creating a pointer, the pointer type has to match what it is pointing to
    // For example, if you are pointing to an int, your pointer must be int *ptr1;
    int num1;
    int *ptr1;

    num1 = 42;
    ptr1 = &num1;

    cout << "num1: " << num1 << endl;
    cout << "*ptr1: " << *ptr1 << endl;
    */

    // These two are functionally the same:
    /* num1 = 15;
    *ptr1 = 15;
    */

    // cout << "&num1: " << &num1 << endl;
    // cout << "&num2: " << &num2 << endl;
    // cout << "&num3: " << &num3 << endl;
    // cout << "ptr1: " << ptr1 << endl;
    // cout << "&ptr1: " << &ptr1 << endl;
    // cout << "&ptr2: " << &ptr2 << endl;
    // cout << "&ptr3: " << &ptr3 << endl;

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
    