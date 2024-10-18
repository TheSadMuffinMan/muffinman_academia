/*
Simple array reading/writing with loops
Counts however many ints are negative
N (num of ints; in this case, N = 3)
X -Y Z (ints)

This would return 1
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int numInts;
    int counter = 0;
    cin >> numInts;

    int array[numInts]; // Creates the array we'll be interacting with
    for (int i = 0; i < numInts; i++) {
        // cout << "array[" << i << "]: ";
        cin >> array[i];
    }

    // for (int i = 0; i < numInts; i++) { // This just prints out the array to ensure everything's in there
    //     cout << "array[" << i << "]: " << array[i];
    // }

    for (int i = 0; i < numInts; i++) {
        if (array[i] < 0) { // This incriments the counter if a negative number is detected
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}