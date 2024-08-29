/* Program 1.2 (in textbook)
This program is fundamentally the same as Program 1.1, but does less computation for the union operation at the expense
    of more computation for the find operation.
*/

// #include <iostream>
#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
    int i, p, q, t, id[N];

    while (scanf("%d %d\n", &p, &q) == 2)
    {
        for (i = p; i < N; i++)
        {
            if (i != id[i])
            {
                i = id[i];
            }
        }
    }



    printf("\nEnd of program.");
    return 0;
}
/*
for (i = p, i != id[i]; i = id[i];)
{
    for (int j = q; j != id[j]; j = id[j])
    {
        if (i == j) {continue;}

        id[i] = j;
        printf(" %d %d\n", p, q);
    }
}
*/