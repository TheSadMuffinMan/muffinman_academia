/*
https://open.kattis.com/problems/stopwatch
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int buttonPresses, temp;
    cin >> buttonPresses;

    int runningTime = 0;
    size_t size = buttonPresses;
    int userArray[size];
    
    for (size_t i = 0; i < size; i+2) {
        cin >> userArray[i] >> userArray[i+1];
        temp = (userArray[i] + userArray[i+1]);
    }
    return 0;
}