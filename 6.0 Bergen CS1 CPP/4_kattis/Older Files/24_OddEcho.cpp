/*
Takes in strings, stores them in and then prints words at odd index values
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    size_t size;
    cin >> size;

    string array[size + 1];

    for (size_t i = 0; i <= size; i++) {
        getline(cin, array[i]);
    }

    for (size_t i = 1; i <= size; i+=2) {
        cout << array[i] << endl;
    }

    return 0;
}