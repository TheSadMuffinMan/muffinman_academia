#include <iostream>

int main(int argc, char *argv[])
{
    double a, b;
    std::cin >> a >> b;

    if ((a == b) || (a < b))
    {
        std::cout << "0";
    }
    else
    {
        std::cout << "1";
    }

    return 0;
}