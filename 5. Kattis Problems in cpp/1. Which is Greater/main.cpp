// https://open.kattis.com/problems/whichisgreater
/*
COMPLETE 6/27/24
Given two positive integers, determine whether the first one is larger than the second one.

INPUT:
    The single line of input contains two positive integers, a and b(0 < a, b < 10^9)

OUTPUT:
    Output a single line with 1 if a > b, 0 otherwise.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    double a, b;
    std::cin >> a >> b;

    if ((a == b) || (a < b))
    {
        std::cout << "0";
    }
    else
    {
        std::cout << "1";
    }

    return 0;
}