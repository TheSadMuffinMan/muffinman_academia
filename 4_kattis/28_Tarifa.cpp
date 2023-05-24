/*
Program takes in ints and manipulates them (nothing crazy)
https://open.kattis.com/problems/tarifa
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int rate, timePeriod, total;

    cin >> rate >> timePeriod;

    total = (rate * (timePeriod + 1));

    return 0;
}