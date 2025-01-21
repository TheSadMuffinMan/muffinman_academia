/*
Creates an array, populates the array, and then find the average of all values (with a conditional)
Program uses floating numbers inside an array
https://open.kattis.com/problems/batterup
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int arraySize;
    cin >> arraySize;

    float inputs[arraySize];
    float runningNum = 0;
    float runningSize = 0;

    for (int i = 0; i < arraySize; i++) {
        cin >> inputs[i];
        if (inputs[i] >= 0) {
            runningNum = (runningNum + inputs[i]);
            runningSize++;
        }
    }
    // cout << "DEBGUG runningNum: " << runningNum << endl;

    // cout << "DEBUG runningNum: " << runningNum << endl;
    // cout << "DEBUG runningSize: " << runningSize << endl;
    float displayNum = runningNum/runningSize;
    cout << displayNum << endl; 

    return 0;
}