/*
Name: Anthony Streich
Date: 24 April 23
Falling Apart Kattis
CURRENT ISSUES: None!
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void arrayCreation(int, int[]);
void sortArray(int[], int);
void printArray(int[], int);
void picker(int&, int&, int&, int[]);
void test(int, int, int);

int main(int argc, char *argv[]) {
    int numPieces;
    // cout << "Number of pieces: ";
    cin >> numPieces;

    int userArray[numPieces];

    arrayCreation(numPieces, userArray);
    sortArray(userArray, numPieces);
    // printArray(userArray, numPieces);

    int alice, bob;
    alice = 0;
    bob = 0;

    picker(alice, bob, numPieces, userArray);
    // Kattis specific return type
    cout << alice << " " << bob << endl;
    // cout << "\nAlice: " << alice << endl;
    // cout << "Bob: " << bob << endl;
    
    int tempAlice, tempBob;
    test(tempAlice, tempBob, numPieces);

    return 0;
}

void arrayCreation(int numPieces, int userArray[]){
    for (int i=0; i < numPieces; i++){
        cin >> userArray[i];
    }
}

void sortArray(int userArray[], int numPieces) {
    for(int j = 0; j < numPieces; j++) {
        bool swapped = false;
        for(int i = 0; i < numPieces-1-j; i++) {
            if(userArray[i] <= userArray[i+1]) {
                swapped = true;
                //swap values
                int tmpNum = userArray[i];
                userArray[i] = userArray[i+1];
                userArray[i+1] = tmpNum;
            }
        }
        // if we are done, break
        if(!swapped) {
            break;
        }
    }
}

void printArray(int userArray[], int numPieces){
    for (int i = 0; i < numPieces; i++){
        cout << userArray[i];
    }
}

void picker(int& alice, int& bob, int& numPieces, int userArray[]){
    // The incrementation was taught to me by my tutor
    // REMEMBER, i is the same thing as counter
    // Every instance of counter can be replaced with i
    for (int counter = 0; counter < numPieces; counter+=2) {
        alice += userArray[counter];
        if ((counter+1) < numPieces) {
            bob += userArray[counter+1];
        } 
        // i++; // This is the case when you are incrementing the loop by 1 (i++)
    }
}

void test(int tempAlice, int tempBob, int tempNumPieces){
    tempAlice = 0;
    tempBob = 0;

    tempNumPieces = 5;
    int tempUserArray[tempNumPieces] = {5, 4, 3, 2, 1};
    picker(tempAlice, tempBob, tempNumPieces, tempUserArray);
    assert(tempAlice == 9);
    assert(tempBob == 6);

    // Mr Bergen help
    picker(tempAlice, tempBob, 3, {7, 6, 2});
    assert(tempAlice == 9);
    assert(tempBob == 6);
    // tempNumPieces = 3;
    // int secondTempUserArray[tempNumPieces] = {7, 6, 2};
    // picker(tempAlice, tempBob, tempNumPieces, secondTempUserArray);
    // assert(tempAlice == 9);
    // assert(tempBob == 6);
}