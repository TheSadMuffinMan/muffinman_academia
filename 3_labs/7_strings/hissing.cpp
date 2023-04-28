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

string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
        solve();
}

/* Dang, I thought I was being SO clever with this, but it won't work becuase the function increments at every instance of 's'.
   So, for example, the word "octopuses" will still result in a return of "hiss" even though it shouldn't.

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
*/

// I can't seem to get this dumbass function to work, and I don't know why it won't work, so I'm gonna do it differently.
// So I thought that this was a bust, but here I am >:(
// Turns out I'm just a dumbass. The find function does NOT take 3 parameters *sighing emoji*
string answer(const string &line) {
    //                     line.length()
    if (line.find("ss", 0) != string::npos) {
        return "hiss";
    }
    if (line.find("ss", 0) == string::npos) {
        return "no hiss";
    }
}

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

    // This adds modularity to my code
    for (int i = 0; i < line.length(); i++) {
        line[i] = tolower(line[i]);
    }
    // string consists of only lowercase letters (no spaces) up to 30 chars
    // FIXME5
    // read string into line

    cout << answer(line) << endl;
}