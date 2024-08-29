#include <iostream>
#include <random>

using namespace std;

/*
QUESTION 1: (Question 1.15)
Give a sequence of input pairs that causes the weighted Q-U algorithm with path compression by halving
    (Program 1.4) to produce a path of length 4.
FULL SEQUENCE:
    1   2   3   4   5   6   7   8
Union Operations:
    union(1,2); 1-2, 3, 4, 5, 6, 7, 8.
    union(3,4); 1-2, 3-4, 5, 6, 7, 8.
    union(5,6); 1-2, 3-4, 5-6, 7, 8.
    union(7,8); 1-2, 3-4, 5-6, 7-8.
    union(2,3); 1-2-3-4, 5-6, 7-8.
    union(6,7); 1-2-3-4, 5-6-7-8.
    union(1,5); 1-2-3-4-5-6-7-8.

QUESTION 2: (Question 1.22)
Modify the program to generate random pairs of integers between 0 and (N-1) instead of reading them from standard input,
    and to loop until N-1 union operations have been formed. Run your program for for N = (10^3, 10^4, 10^5, 10^6) and
    print out the total number of edges generated for each value of N.

QUESTION 3: (Question 1.21)
Show that Property 1.3 holds for the algorithm described in Exercise 1.20.
*/
int main(int argc, char *argv[])
{
    std::cout << "\nThis is Program 1.4: Path Compression by Halving." << std::endl;

    
    return 0;
}