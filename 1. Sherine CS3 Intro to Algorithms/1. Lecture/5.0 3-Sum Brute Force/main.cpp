#include <iostream>
#include <fstream>

/*
This is the Brute Force solution to the classic 3-Sum problem.
*/

int count(int a[], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
            {
            for (int k = j + 1; k < N; k++)
            {
                if (a[i] + a[j] + a[k] == 0)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    std::ifstream in(argv[1]);
    int N;
    in >> N;
    int* a = new int[N];

    for (int i = 0; i < N; i++)
    {
        in >> a[i];
    }
    
    in.close();

    std::cout << count(a, N) << std::endl;
    delete[] a;
    return 0;
}