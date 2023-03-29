// PLAYGROUND

#include <iostream>
#include <string>

using namespace std;

void printFlippedTriangle(int);

int main(int argc, char *argv[]) {
    printFlippedTriangle(5);
    return 0;
}

void printFlippedTriangle(int height) {
    int row = 1;
    while (row <= height) {
        // column
        for(int col = height; col>=row; col--)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}