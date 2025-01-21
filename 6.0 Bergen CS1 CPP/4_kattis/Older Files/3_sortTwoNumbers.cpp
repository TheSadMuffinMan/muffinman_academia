/*
Sorts two ints and displays the smaller int first
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a, b;
    cin >> a >> b;

    if (a < b ) {
        cout << a << " " << b << endl;
    } else {
        cout << b << " " << a << endl;
    }

    return 0;
}