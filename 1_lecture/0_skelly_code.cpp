/*
Name: Anthony Streich
Functions pass-by-reference/pass-by-value
*/

#include <iostream>
#include <string>

using namespace std;

void greetUser(string name);

int main() {
    return 0;
}

void greetUser(string name) {
    cout << "Welcome " << name << " to my program!" << endl;
}
    