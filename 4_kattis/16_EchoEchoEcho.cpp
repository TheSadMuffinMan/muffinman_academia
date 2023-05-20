/*
Takes in user string and then replicates it three times
Demonstrates use of getline() function
First try
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    getline(cin, input);

    cout << input << " " << input << " " << input << endl;
    return 0;
}