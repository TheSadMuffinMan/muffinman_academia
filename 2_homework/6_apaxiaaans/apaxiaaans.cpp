/*
Name: Anthony Streich
Date: 20 March 23
Kattis Apaxiaaans!
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    char activeComparisonChar;
    string userString;
    // cout << "Program start, welcome to my Apaxiaaans Program.\n";
    // cout << "Please enter the string you'd like shortened: ";
    getline(cin,userString);

    // cout << "**DEBUG** userString: " << userString << endl;

    for (int i = 0; i < userString.size(); i++) {
        // cout << "**DEBUG** userString[" << i << "]: " << userString << endl;
        activeComparisonChar = userString[i];
        if (activeComparisonChar == userString[i+1]) {
            userString.erase(i,1);
            i--;
            // cout << userString << endl;
        }
    }

    cout << userString << endl;
    
    return 0;
}