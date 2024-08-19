/*
Alternates output based on input
First try
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int input;
    cin >> input;

    if ((input%2) == 1) {
        cout << "first\n";
    } else {
        cout << "second\n";
    }

    return 0;
}