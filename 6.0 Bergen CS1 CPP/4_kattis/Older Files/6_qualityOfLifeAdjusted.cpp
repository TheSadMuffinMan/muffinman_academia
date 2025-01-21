/*
Takes in array, mults two elements, adds em up
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int loopSize;
    float qol, numYears, qaly, temp;
    cin >> loopSize;

    qaly = 0;
    for (int i = 0; i < loopSize; i++) {
        // cout << "qol[" << i << "]: " << endl;
        // cout << "numYears[" << i << "]: " << endl;
        cin >> qol >> numYears;
        temp = (qol * numYears);
        qaly = (qaly + temp);
    }

    cout << qaly;

    return 0;
}