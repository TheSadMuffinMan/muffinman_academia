// PLAYGROUND

#include <iostream>
#include <string>

using namespace std; 

int main() {
    string testString;
    cin >> testString;

    bool hissTrue = false;
    if (testString.find("ss")) {
        hissTrue = true;
        cout << "hissTrue: " << hissTrue;
    } else {
        cout << "hissTrue: " << hissTrue;
    }
}