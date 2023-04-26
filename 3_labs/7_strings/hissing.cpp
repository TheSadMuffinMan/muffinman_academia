/*
Kattis - Hissing Microphone Problem
By: Anthony Streich
Date: 25 April 23
Hissing Microphone Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read string
2. find "ss" substring in the string
    - if found, print "hiss"
    - otherwise, print "no hiss"
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
        solve();
}

string answer(const string &line) {
    // FIXME3
    // implment algorithm step 2
    // return "hiss" if ss is found in line
    // otherwise, return "no hiss"
    int counter = 0;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == 's') {
            counter++;
        }
    }

    if (counter >= 2) {
        return "hiss";
    } else {
        return "no hiss";
    }
}

/* I can't seem to get this dumbass function to work, and I don't know why it won't work, so I'm gonna do it differently.
string answer(const string &line) {
    // FIXME3
    // implment algorithm step 2
    // return "hiss" if ss is found in line
    // otherwise, return "no hiss"

    if (line.find("ss", 0, line.length()) == string::npos) {
        return "no hiss";
    } else {
        return "hiss";
    }
}
*/

// unit testing answer()
void testAnswer() {
    // FIXME4 #fixed#
    // write at least two test cases to test answer()
    assert(answer("mississippi") == "hiss");
    assert(answer("ireland") == "no hiss");

    cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
    string line;
    cin >> line;
    for (int i = 0; i < line.length(); i++) {
        line[i] = tolower(line[i]);
    }
    // string consists of only lowercase letters (no spaces) up to 30 chars
    // FIXME5
    // read string into line

    cout << answer(line) << endl;
}