/*
Program demonstrates a linear way to solve Fibonacci numbers.
See https://www.youtube.com/watch?v=KzT9I1d-LlQ&t=339s (4:00) for more in depth analysis. 
*/

#include <iostream>
#include <chrono>

typedef std::chrono::steady_clock Time; // Makes it to where we don't have to type this bs every time.

long long linearFib(int n) 
{
    long long x = 0;
    long long y = 1;
    long long next = 0;

    for (int i = n; i > 0; i--)
    {
        next = (x + y);
        x = y;
        y = next;
    }

    return x;
}

int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;

    int targetNum = 0;
    std::cout << "\nTarget Fibonacci number?: ";
    std::cin >> targetNum;

    auto timeStart = Time::now();
    std::cout << "\nFibonacci " << targetNum << ": " << std::endl << "\t"<< linearFib(targetNum) << std::endl;
    auto timeStop = Time::now();
    auto duration = (timeStop - timeStart);
    std::cout << "Compiled in " << duration.count() << " ns." << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}