// PLAYGROUND

#include <iostream>
#include <string>

using namespace std;

void printTriangle(int);

int main(int argc, char *argv[]) {
    printTriangle(10);
    return 0;
}

void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}