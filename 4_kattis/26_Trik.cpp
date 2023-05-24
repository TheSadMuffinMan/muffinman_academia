/*
Replicates the "Ball Under Cup" game, with three cups
Ball starts under 1

MOVES:
1     2     3
<-----><---->
   A      B
<----------->
      C
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    size_t size;
    int ballPosition = 0;

    cin >> size;
    string dirtyUserInput;
    cin >> dirtyUserInput;

    // Takes everything inside the string, and plops it inside an array made of chars
    // Also "cleans" the input
    char cleanUserInput[size];
    for (size_t i = 0; i < size; i++) {
        cleanUserInput[i] = toupper(dirtyUserInput.at(i));
    }

    // Used for debugging to ensure the above code is populating the array
    for (size_t i = 0; i < size; i++) {
        cout << "***DEBUG***cleanUserInput[" << i << "]: " << cleanUserInput[i] << endl;
    }

    // Tabulates where the ball is, based off cleaned input
    for (size_t i = 0; i < size; i++) {
        if (cleanUserInput[i] == 'A') {
            ballPosition = 1;
        } else if (cleanUserInput[i] == 'B') {
            ballPosition = 2;
        } else if (cleanUserInput[i] == 'C') {
            ballPosition = 0;
        } else {
            cout << "LOOP ERROR\n";
        }
    }

    cout << "ballPosition: " << ballPosition << endl;

    return 0;
}