/*
Program outputs a string based off numerical input
https://open.kattis.com/problems/twostones
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int input;
    cin >> input;

    if ((input % 2) == 1) {
        cout << "Alice" << endl;
    } else if ((input % 2) == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    return 0;
}