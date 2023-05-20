/*
Determines where to "route" a call based off first three nums of input
Barney style conditionals
First use of size_t
IMPORTANT LEARNING LESSON: size_t cannot be 0, so trying to compare a function to it will not work
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    cin >> input;

    size_t pos = input.find("555"); // size_t is needed because that is what the find() function returns
    // cout << "DEBUG pos: " << pos << endl;

    // Checks to see if position is not returning noPosition, (checks if sequence "555" chars is in string at all)
    // Then checks to see if "5" is at the start of string,
    // Then checks if position is at 0 (the first chacter)
    // So, it ONLY returns 1 if all of these conditions are true
    if ((pos != string::npos) && (input.find("5", 0, 1) != string::npos) && (pos == 0)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

/*
    // if (pos == '0') { // THIS is the learning lesson the top is speaking of
        // cout << "1\n"; // This comparison will never be true becuase size_t will never be 0
*/
    
    return 0;
}