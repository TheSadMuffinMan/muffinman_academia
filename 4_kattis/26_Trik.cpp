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
    char userMove[size];
    cin >> userMove[size];

    cout << "userMove[0]: " << userMove[0] << endl;
    cout << "userMove[1]: " << userMove[1] << endl;

    for (size_t i = 0; i <= size; i++) {
        if (userMove[i] == 'A') {
            ballPosition = 1;
        } else if (userMove[i] == 'B') {
            ballPosition = 2;
        } else if (userMove[i] == 'C') {
            ballPosition = 0;
        } else {
            cout << "E\n";
        }
    }

    cout << "ballPosition: " << ballPosition << endl;

    return 0;
}