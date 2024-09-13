/*
Program demonstrates Recursive Memoisation. 
*/

#include <iostream>
#include <chrono>

typedef std::chrono::steady_clock Time; // Makes it to where we don't have to type this bs every time.

const int MAX_N = 80; // <-- Target Fibonacci number.
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

    auto timeStart = Time::now();
    std::cout << "\nFibonacci " << MAX_N << ": " << std::endl << "\t" << memoFib(MAX_N) << std::endl;
    auto timeStop = Time::now();
    auto duration = (timeStop - timeStart);
    std::cout << "Compiled in " << duration.count() << " ns." << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}