/*
Uses function S = ((R1 + R2) / 2), but is missing R2.
R2 = (2S - R1)
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int r1, r2, s;
    cin >> r1 >> s;

    r2 = ((2*s) - r1);
    cout << r2 << endl;

    return 0;
}