/*
First use of modulus
Input contains three ints
Divisible by x = Fizz
Divisible by y = Buzz
X Y N
Prints out every int from 0 to N
For every int, check for Fizz or Buzz, then print results
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int x, y, n_length;
    cin >> x >> y >> n_length;

    for (int i = 1; i < (n_length + 1); i++) {
        if (((i % x) == 0) && ((i % y) != 0)) {
            cout << "Fizz\n";
        } else if (((i % x) != 0) && ((i % y) == 0)) {
            cout << "Buzz\n";
        } else if (((i % x) == 0) && ((i % y) == 0)) {
            cout << "FizzBuzz\n";
        } else {
            cout << i << endl;
        }
    }

    return 0;
}