/*
Name: Anthony Streich
Date: 21 April 23
Falling Apart Kattis
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;

void arrayCreation(int, int[]);
void printArray(int, int[]);
// void sortArray();
void picker(int& alice, int& bob, int& numPieces);
// void totals();

int main(int argc, char *argv[]) {
    int numPieces;
    cout << "**DEBUG** number of pieces: ";
    cin >> numPieces;

    int userArray[numPieces];

    arrayCreation(numPieces, userArray);
    printArray(numPieces, userArray);

    // sortArray();

    int alice, bob;
    alice = 0;
    bob = 0;

    picker(alice, bob, numPieces);

    // totals();

    return 0;
}

void arrayCreation(int numPieces, int userArray[]){
    for (int i=0; i < numPieces; i++){
        cin >> userArray[i];
    }
}

void printArray(int numPieces, int userArray[]){
    for (int i = 0; i < numPieces; i++){
        cout << userArray[i];
    }
}

// void sortArray();

void picker(int& alice, int& bob, int& numPieces){
    for (int i=0; i < numPieces, i+2) {
        alice += userArray[i];
        bob += userArray[i+1];

    }

}

// void totals();
