/*
Takes in a phrase and doubles the number of 'e's inside it.
Explores the string.insert() function and loop functionality
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    string input;
    cin >> input;

    int length = input.length(); // This eliminates warning messages
    for (int i = 0; i < length; i++) {
        if(input[i] == 'e') {
            input.insert(i, "e"); // It is important to note that the insert() function uses ", even when only searching for a char
            i++;
        }
    }

    cout << input << endl;

    return 0;
}