// https://open.kattis.com/problems/reversebinary
/*
6/28/24 working on. This one is difficult.

TASK:
    Your task will be to write a program for reversing numbers in binary. For instance, the binary
        representation of 13 is 1101, and reversing it gives 1011, which corresponds to number 11.

INPUT:
    The input contains a single line with an integer N(1 <= N <= 1,000,000,000).

OUTPUT:
    Output one line with one integer, the number we get by reversing the binary representation of N.
*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int inputInt;
    std::cin >> inputInt;

    int arr[64];
    int i = 0;
    int r;

    while (inputInt != 0)
    {
        r = inputInt % 2;
        arr[i++] = r;
        inputInt /= 2;
    }

    return 0;
}