/*
The Modulus Operator "%" divides a by b, and then returns the remainder.
    Examples:
        int a = 5;
        int b = 2;
        int c = a % b;
        cout << "c = " << c << endl; (Will print "c = 1")

        int d = 13;
        int e = 5;
        int f = e % f;
        cout << "f = " << f << endl; (Will print "f = 3")
*/
// **Program does NOT use standard namespace.**

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Program start" << std::endl;

    int a = 5; std::cout << "\na = 5" << std::endl;
    int b = 2; std::cout << "b = 2" << std::endl;
    int c = a % b; std::cout << "c = a % b" << std::endl;
    std::cout << "c = " << c << std::endl << std::endl; // c = 1

    int d = 13; std::cout << "d = 13" << std::endl;
    int e = 5; std::cout << "e = 5" << std::endl;
    int f = d % e; std::cout << "f = d % e" << std::endl;
    std::cout << "f = " << f << std::endl; // f = 3

    int x,y;
    std::cout << "\n\nYour turn. Input will take the form x % y." << std::endl;
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;

    int z = x % y;
    std::cout << std::endl << x << " % " << y << " = " << z << std::endl;

    std::cout << "\nProgram complete." << std::endl;
    return 0;
}