/*
QUESTION 2: (Question 1.22)
Modify Program 1.4 (Weighted Quick Union with Path Compression by Halving) to generate random pairs of integers
    between 0 and (N-1) instead of reading them from standard input, and to loop until N-1 union operations have
    been formed. Run your program for for N = (10^3, 10^4, 10^5, 10^6) and print out the total number of edges
    generated for each value of N.
*/

#include <iostream>
#include <random>

#define N 100

int main(int argc, char *argv[])
{
    std::cout << "\nN: " << N << std::endl;

    int i, j, p, q, id[N], size[N];
    std::default_random_engine randomNumGenerator;
    
    for (i = 0; i < N; i++) // Initializing each array.
    {
        id[i] = i;
        size[i] = 1;
    }

    // Instead of reading in input, we are looping through N-1 times and generating random values for p & q each time.
    for (int z = 0; z < (N - 1); z++)
    {
        p = (randomNumGenerator() % N); // Assigning p a random value.
        q = (randomNumGenerator() % N); // Assigning q a random value.

        for (i = p; i != id[i]; i = id[i])
            id[i] = id[id[i]]; // This is the line that halves the length of the path.
        for (j = q; j != id[j]; j = id[j])
            id[j] = id[id[j]]; // Ditto to above, but for j.

        if (i == j) {continue;}

        if (size[i] < size[j])
        {
            id[i] = j;
            size[j] += size[i];
        }
        else
        {
            id[j] = i;
            size[i] += size[j];
        }

        printf(" %d: %d %d\n", z, p, q);
    }

    printf("\nEnd of program.\n");
    return 0;
}