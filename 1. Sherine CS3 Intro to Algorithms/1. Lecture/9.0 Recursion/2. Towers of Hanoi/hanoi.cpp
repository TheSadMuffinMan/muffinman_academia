#include <iostream>

std::string hanoi(int n, bool left)
{
    if (n == 0) {return " ";}

    std::string move;
    if (left)
    {
        move = std::to_string(n) + "L";
    } else {
        move = std::to_string(n) + "R";
    }

    return hanoi(n-1, !left) + move + hanoi(n-1, !left);
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram Start." << std::endl;

    int n = 0;
    std::cout << "How many \"blocks\" would you like there to be?: ";
    std::cin >> n;

    std::cout << hanoi(n, false) << std::endl;

    std::cout << "\nEnd of program." << std::endl;
}