/*
This recursive program is wasteful because we are wasting SO much work on recomputing the smaller values.
*/

#include <iostream>

long F(int n)
{
    if (n == 0) {return 0;}

    if (n == 1) {return 1;}

    return F(n - 1) + F(n - 2);
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cout << "\nPlease input N value: ";
    std::cin >> n;
    
    std::cout << F(n) << std::endl;
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}