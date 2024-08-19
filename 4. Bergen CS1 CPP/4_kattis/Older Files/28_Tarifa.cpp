/*
Program takes in ints and manipulates them (nothing crazy)
https://open.kattis.com/problems/tarifa
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int rate, timePeriod, total;
    int temp1 = 0;
    int temp2 = 0;

    cin >> rate >> timePeriod;

    total = (rate * (timePeriod + 1));

    size_t size = timePeriod;
    for (size_t i = 0; i < size; i++) {
        cin >> temp1;
        temp2 = (temp2 + temp1);
    }

    cout << (total - temp2) << endl;

    return 0;
}