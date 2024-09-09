#include <iostream>
#include <string>

class Binary
{
    public:
        static std::string convert(int N)
        {
            if (N == 1) {return "1";}

            return convert(N / 2) + std::to_string(N % 2);
        }
};

int main(int argc, char *argv[])
{
    int n = 0;
    std::cout << "\nEnter an integer: ";
    std::cin >> n;

    std::cout << "\nBinary representation of " << n << ": ";
    std::cout << Binary::convert(n) << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}