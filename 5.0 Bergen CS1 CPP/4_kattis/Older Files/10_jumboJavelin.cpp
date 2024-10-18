/*
Takes in amount x, adds up x amount of ints and then adds one.
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int size, total, temp;
    
    cin >> size;
    temp = 0;
    total = 0;

    for (int i = 0; i < size; i++) {
        cin >> temp;
        total = (total + temp);
    }

    total = (total - size + 1);
    cout << total;

    return 0;
}