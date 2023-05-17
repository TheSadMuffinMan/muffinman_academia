/*
Takes in array, mults two elements, adds em up
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int arraySize;
    float qol, numYears, qaly, temp;
    cin >> arraySize;

    qaly = 0;
    for (int i = 0; i < arraySize; i++) {
        // cout << "qol[" << i << "]: " << endl;
        // cout << "numYears[" << i << "]: " << endl;
        cin >> qol >> numYears;
        temp = (qol * numYears);
        qaly = (qaly + temp);
    }

    cout << qaly;

    return 0;
}