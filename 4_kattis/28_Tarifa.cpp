/*
Program takes in ints and manipulates them (nothing crazy)
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int rate, timePeriod, total;

    cin >> rate >> timePeriod;

    total = (rate * (timePeriod + 1));

    return 0;
}