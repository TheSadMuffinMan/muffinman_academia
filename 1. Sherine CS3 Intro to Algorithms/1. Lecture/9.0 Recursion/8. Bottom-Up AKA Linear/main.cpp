#include <iostream>

int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);

    long long F[n + 1];
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    
    std::cout << F[n] << std::endl;
    return 0;
}

/*
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
*/