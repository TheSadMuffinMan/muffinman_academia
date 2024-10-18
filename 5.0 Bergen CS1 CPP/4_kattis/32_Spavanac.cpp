/*
Subtracts 45 minutes from any 24 hour time denomination
https://open.kattis.com/problems/spavanac
*/

#include <iostream>

using namespace std;

void cleanSecond(int, int&, bool&);
void cleanFirst(bool, int, int&);

int main(int argc, char *argv[]) {
    int usern1, usern2, uUsern1, uUsern2;
    bool flipped = false;
    cin >> usern1 >> usern2; // Takes in user input

    cleanSecond(usern2, uUsern2, flipped); // "cleans" the minutes portion
    cleanFirst(flipped, usern1, uUsern1); // "cleans" the hours portion

    cout << uUsern1 << " " << uUsern2 << endl;

    return 0;
}

void cleanSecond(int usern2, int &uUsern2, bool &flipped) {
    int temp = 0;
    temp = (usern2 - 45);
    if (temp < 0) {
        flipped = true;
        uUsern2 = (60 + temp);
    } else {
        uUsern2 = temp;
    }
}

void cleanFirst(bool flipped, int usern1, int &uUsern1) {
    if (flipped == false) {
        uUsern1 = usern1;
    } else if ((flipped == true) && (usern1 > 1)) {
        uUsern1 = (usern1 - 1);
    } else if ((flipped == true) && (usern1 == 0)) {
        uUsern1 = 23;
    } else {
        uUsern1 = 10000000;
    }
}