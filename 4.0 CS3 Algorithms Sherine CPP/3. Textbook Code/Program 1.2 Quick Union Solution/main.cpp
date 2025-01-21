/* Program 1.2 (in textbook)
This program is fundamentally the same as Program 1.1, but does less computation for the union operation at the expense
    of more computation for the find operation.
*/

// #include <iostream>
#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
    int i, j, p, q, id[N];

    for (i = 0; i < N; i++) {id[i] = i;} // Initiallizing ea id[i] to "point" to itself.
    
    while (scanf("%d %d\n", &p, &q) == 2) // Reads in input to unionize objects.
    {        
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);

        if (i == j) {continue;}

        id[i] = j;

        printf(" %d %d\n", p, q);
    }
  
    printf("\nEnd of program.");
    return 0;
}