/*
Creates an array, populates the array, and then find the average of all values (more or less)
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

    for (int i = 0; i < arraySize; i++) {
        cin >> inputs[i];
        runningNum = (runningNum + inputs[i]);
    }
    cout << "DEBGUG runningNum: " << runningNum << endl;

    float displayNum = runningNum/arraySize;
    cout << displayNum << endl; 

    return 0;
}