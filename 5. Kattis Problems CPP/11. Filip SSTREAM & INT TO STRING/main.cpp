#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
    std::string iN1, iN2;
    std::cin >> iN1 >> iN2;

    std::string rN1(iN1.rbegin(), iN1.rend()), rN2(iN2.rbegin(), iN2.rend());

    std::cout << "Num1 Reversed: " << rN1 << ", Num2 Reversed: " << rN2 << std::endl;

    
    return 0;
}

// std::istringstream(*input*);