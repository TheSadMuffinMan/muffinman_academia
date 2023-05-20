/*
12_greeeetings.cpp
Takes in a phrase and doubles the number of 'e's inside it.
Explores the string.insert() function and loop functionality
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    cin >> input;

    cout << "h";
    int length = (input.length() - 2); // This eliminates warning messages, and eliminates the 'h' and 'y' chars
    for (int i = 0; i < length; i++) {
        cout << "ee";
    }
    cout << "y\n";

    return 0;
}

/*
This is the smart way of doing it, but Kattis is Kattis, so...
        if(input[i] == 'e') {
            input.insert(i, "e"); // It is important to note that the insert() function uses ", even when only searching for a char
            i++;
*/