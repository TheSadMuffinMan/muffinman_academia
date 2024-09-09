#include <iostream>
#include <cmath>

std::string hanoi(int n, bool left)
{
    if (n == 0) {return " ";} // BASE CASE.

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

    int numMoves = 0;
    std::cout << hanoi(n, false) << std::endl;
    
    numMoves = (pow(2,n) - 1);
    std::cout << "Number of (optimal) moves: " << numMoves << "." << std::endl;

    std::cout << "\nEnd of program." << std::endl;
}