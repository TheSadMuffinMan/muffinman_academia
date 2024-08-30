/*
Question 1.21:
    Show that Property 1.3 holds for the algorithm described in Exercise 1.20.

    Property 1.3:
        The weighted quick-union algorithm uses AT MOST a constant times M lg N instructions to process M edges
            on N objects. The alternative (quick-find and sometimes quick-union) uses AT LEAST (M*N)/2 instructions.
            This guarentees that we can solve huge practical problems in a reasonable amount of time.

    Exercise 1.20:
        Modify Program 1.3 (Weighted Quick Union) to use the height of the trees (longest path from any node to the
            root), instead of the weight, to decide whether to set id[i] = j or id[j] = i. Run empirical studies to
            compare this variant with Program 1.3 (Unmodified Weighted Quick Union).
*/

#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::steady_clock Time;// Makes is to where we don't have to type entire library every time.

#define N 1000

int main(int argc, char *argv[])
{
    int i, j, p, q, id[N], size[N];
    std::default_random_engine randomObject;
    
    for (i = 0; i < N; i++) // Initializing each array.
    {
        id[i] = i;
        size[i] = 1;
    }

    // Is the same as: auto timeStart = std::chrono::high_resolution_clock::now();
    auto timeStart = Time::now();

    for (int x = 0; x < N; x++)
    {
        p = (randomObject() % N);
        q = (randomObject() % N);

        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);

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

        // printf(" %d %d\n", p, q);
    }
    auto timeStop = Time::now();
    auto duration = Time::duration(timeStop - timeStart);

    // One nanosecond == 0.000,000,0001 seconds (one-billionth of a second).
    // One microsecond == 0.000,0001 seconds (one-millionth of a second).
    // One millisecond == 0.001 (one-thousandth of a second).
    std::cout << "\nRun Time: " << duration.count() << " nanoseconds." << std::endl;

    printf("\nEnd of program.\n");
    return 0;
}