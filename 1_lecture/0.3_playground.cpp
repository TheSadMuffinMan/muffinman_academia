// PLAYGROUND

#include <iostream>
#include <string>

using namespace std; 

void sortArray(int[], int);
void printArray(int[], int);

int main () {
  int numPieces;
  cout << "Num of pieces: \n";
  cin >> numPieces;

  int userArray[numPieces];

  sortArray(userArray, numPieces);

  printArray(userArray, numPieces);

  return 0;
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
        cout << userArray[i] << endl;
    }
}