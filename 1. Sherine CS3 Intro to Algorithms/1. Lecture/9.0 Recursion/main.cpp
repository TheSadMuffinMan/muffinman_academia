/*
This is just a basic representation of what recursive code can be.
*/

/*
Recursion is just a function that calls itsself. This is advantageous for solving large problems that have
    many smaller parts that need to be solved. The function executes until it reaches its BASE CASE.

What is Recursion? (Textbook Definition)
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

#include <iostream>
#include "binaryConversion.h" // Class converts an int to it's binary representation.

std::string ruler(int n)
{
    if (n == 1)
    {
        return "1";
    }

    std::string ruler_n_minus_1 = ruler(n - 1);
    return ruler_n_minus_1 + " " + std::to_string(n) + " " + ruler_n_minus_1;
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    int n = std::stoi(argv[1]);
    std::cout << ruler(n) << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}