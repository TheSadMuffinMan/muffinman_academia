/*
Determines what quadrant an x,y point is in
This one took me too long lol
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int x, y;
    cin >> x >> y;

    if ((x > 0) && (y > 0)) {
        cout << "1\n";
    } else if ((x < 0) && (y > 0)) {
        cout << "2\n";
    } else if ((x < 0) && (y < 0)) {
        cout << "3\n";
    } else if ((x > 0) && (y < 0)) {
        cout << "4\n";
    } else {
        cout << "ERROR\n";
    }

    return 0;
}