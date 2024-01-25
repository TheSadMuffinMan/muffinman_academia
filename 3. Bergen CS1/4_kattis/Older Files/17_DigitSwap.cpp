/*
Swaps two numbers
First try
Demonstrates use of string.at() function
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string input, n1, n2;
    cin >> input;

    n1 = input.at(0);
    n2 = input.at(1);

    cout << n2 << n1 << endl;
    return 0;
}