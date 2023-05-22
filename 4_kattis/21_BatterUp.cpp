/*
Creates an array, populates the array, and then find the average of all values (more or less)
https://open.kattis.com/problems/batterup
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int arraySize;
    cin >> arraySize;

    float inputs[arraySize];
    float runningNum = 0;

    for (int i = 0; i < arraySize; i++) {
        cin >> inputs[i];
        runningNum = (runningNum + inputs[i]);
    }

    float displayNum = runningNum/arraySize;
    cout << displayNum; 

    return 0;
}