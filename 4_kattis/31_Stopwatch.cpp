/*
https://open.kattis.com/problems/stopwatch
*/

#include <iostream>

using namespace std;

void fillInput(int&[], size_t);
void calcTime(int[], size_t, int&);

int main(int argc, char *argv[]) {
    int buttonPresses;
    cin >> buttonPresses;
    size_t size = buttonPresses;

    int runningTime = 0;
    int userArray[size];

    if ((buttonPresses % 2) == 1) {
        fillInput(userArray, size);
        calcTime(userArray, size, runningTime);
        cout << runningTime << endl;
    } else {
        cout << "still running" << endl;
    }

    return 0;
}

void fillInput(int &userArray[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> userArray[i];
    }
}

void calcTime(int userArray[], size_t size, int &runningTime) {
    int temp;
}