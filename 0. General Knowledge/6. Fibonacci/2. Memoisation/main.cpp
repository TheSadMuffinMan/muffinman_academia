/*
Program demonstrates Recursive Memoisation. 
*/

#include <iostream>

const int MAX_N = 70;
long long memoArray[MAX_N];

long long memoFib(int n) 
{
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}

    if (memoArray[n] == 0)
    {
        memoArray[n] = memoFib(n - 1) + memoFib(n - 2);
    }

    return memoArray[n];
}

int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;

    // Initialize memoisation array with 0
    for (int i = 0; i < MAX_N; i++) {memoArray[i] = 0;}

    std::cout << "Fibonacci " << MAX_N << ": " << memoFib(MAX_N) << std::endl;
    return 0;
}