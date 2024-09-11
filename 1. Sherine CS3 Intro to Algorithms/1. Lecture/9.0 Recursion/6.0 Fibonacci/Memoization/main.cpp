#include <iostream>

const int MAX_N = 100;
long long memo[MAX_N];

long long F(int n) 
{
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}

    if (memo[n] == 0)
    {
        memo[n] = F(n - 1) + F(n - 2);
    }

    return memo[n];
}

int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);

    // Initialize memoization array with 0
    for (int i = 0; i < MAX_N; i++) {memo[i] = 0;}

    std::cout << F(n) << std::endl;
    return 0;
}