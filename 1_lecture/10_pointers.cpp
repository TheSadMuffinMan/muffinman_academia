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

int addNums(int*, int*);

int main(int argc, char *argv[]) {
    // string userName;
    // userInput(userName);
    // greetUser(userName);

    int n1, n2;
    int *ptr1, *ptr2;

    n1 = 42;
    n2 = 15;
    ptr1 = &n1;
    ptr2 = &n2;

    cout << n1 << " + " << n2 << " = " << addNums(&n1, &n2) << endl;

    // This allows you to make conditionals with pointers
    // int *somePointer1 = NULL;

    /*
    // If you're looking for the actual value, you can also have *(&num1)
    // If you look inside the pointer, you will only see random numbers
    cout << "&num1: " << &num1 << endl;
    // &somePointer1 will output the memory address of the pointer itself
    // *somePointer1 will output the value of the dereferenced variable
    cout << "somePointer1: " << *somePointer1 << endl;
    */

    /*
    // This is where the NULL portion is applicabale
    if (somePointer1 == NULL) {
       somePointer1 = &num1;
    } */

    // int num1 = 0;
    // float fnum1;
    // string snum1;
    // char cnum1;

    // This is the C++ way of doing things for null pointers
    // int *ptr1 = nullptr;
    // This is the old C way of doing things, case sensitive
    // ptr1 = NULL;
    // This will also work
    // ptr1 = __null;

    // cout << "&num1: " << &num1 << endl;
    // cout << "ptr1: " << ptr1 << endl;

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

    return 0;
}

int addNums(int *num1, int *num2) {
    return *num1 + *num2;
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
    