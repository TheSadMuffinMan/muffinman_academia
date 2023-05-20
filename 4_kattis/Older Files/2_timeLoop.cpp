/*
Output the entire wizard’s spell by counting 0 from to X, giving one number and “Abracadabra” per line.
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    
    int numCadabras;
    cin >> numCadabras;

    for (int i = 0; i < numCadabras; i++) {
        cout << i + 1 << " Abracadabra" << endl;
    }

    return 0;
}