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
void sortArray(int[], int);
void printArray(int[], int);
void picker(int&, int&, int&, int[]);

int main(int argc, char *argv[]) {
    int numPieces;
    cout << "Number of pieces: ";
    cin >> numPieces;

    int userArray[numPieces];

    arrayCreation(numPieces, userArray);
    
    sortArray(userArray, numPieces);

    printArray(userArray, numPieces);


    int alice, bob;
    alice = 0;
    bob = 0;

    picker(alice, bob, numPieces, userArray);
    cout << "\nAlice: " << alice << endl;
    cout << "Bob: " << bob << endl;

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

void printArray( int userArray[], int numPieces){
    for (int i = 0; i < numPieces; i++){
        cout << "DEBUG " << userArray[i];
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