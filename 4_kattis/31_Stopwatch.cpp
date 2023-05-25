/*
Fun use of loops!
https://open.kattis.com/problems/stopwatch
*/

#include <iostream>

using namespace std;

void fillInput(int[], size_t); // Function fills an array with user input
void calcTime(int[], size_t, int&); // Function calculates the running time spent between button presses

int main(int argc, char *argv[]) {
    int buttonPresses, temp;
    cin >> buttonPresses;
    size_t size = buttonPresses;

    int runningTime = 0;
    int userArray[size];

    if ((buttonPresses % 2) == 0) {
        fillInput(userArray, size);
        calcTime(userArray, size, runningTime);
        cout << runningTime << endl;
    } else {
        for (size_t i = 0; i < size; i++) { // This loop is only here so that Kattis can input nums, the input doesn't do anything
            cin >> temp;
        }
        cout << "still running" << endl;
    }

    return 0;
}

void fillInput(int userArray[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> userArray[i];
    }

    // for (size_t i = 0; i < size; i++) { // This is the debug loop
    //     cout << "***DEBUG*** userArray[" << i << "]: " << userArray[i] << endl;
    // }
}

void calcTime(int userArray[], size_t size, int &runningTime) {
    for (size_t i = 0; i < size; i+=2) {
        runningTime = (runningTime + (userArray[i+1] - userArray[i]));
    }
}