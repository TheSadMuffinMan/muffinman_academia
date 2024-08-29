/* Program 1.1 (in textbook)
This program reads a sequence of pairs of nonnegative integers less than N from standard input (interpreting
    the pair p q to mean “connect object p to object q”) and prints out pairs representing objects that are not
    yet connected. It maintains an array id that has an entry for each object, with the property that id[p] and
    id[q] are equal if and only if p and q are connected. For simplicity, we define N as a compile-time constant.
    Alternatively, we could take it from the input and allocate the id array dynamically.
*/

// #include <iostream>
#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
    // id[N] maintains an entry for every other object.
    int i, p, q, t, id[N];

    for (i = 0; i < N; i++)
    {
        while (scanf("%d %d\n", &p, &q) == 2)
        {
            if (id[p] == id[q]) {continue;}

            for (i = 0; i < N; i++)
            {
                t = id[p];

                if (id[i] == t)
                {
                    id[i] = id[q];
                    printf(" %d %d\n", p, q);
                }
            }
        }
    }    
    printf("\nEnd of program.");
    return 0;
}