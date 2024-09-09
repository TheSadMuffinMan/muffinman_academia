/*
Recursion is just a function that calls itsself. This is advantageous for solving large problems that have
    many smaller parts that need to be solved. The function executes until it reaches its BASE CASE.

What is Recursion?
    When something is specified in terms of itself.

Why learn Recursion?
    Represents a new mode of thinking.
    Provies a powerful programming paradigm.
    Enables reasoning about correctness.
    Gives insight into the nature of computation.

Many computational artifacts are naturally self-referential.
    File systems wiht folders containing folders.
    Fractal graphical patterns.
    Divide-and-Conquer Algorithms (stay tuned :D).

One unfortunate aspect of Recursion is that to prove functionality, you often need to provide mathmatical proofs.

Recursion IS very good for algorithmic trees.
*/

/* Towers of Hanoi fun.
    Has the same exact solution as the ruler problem (below).
*/

#include <iostream>
#include <string>

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
    std::cout << "\nProgram start." << std::endl;

    int n = 0;
    std::cout << "How many blocks would you like?: ";
    std::cin >> n;

    std::cout << hanoi(n, false) << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}