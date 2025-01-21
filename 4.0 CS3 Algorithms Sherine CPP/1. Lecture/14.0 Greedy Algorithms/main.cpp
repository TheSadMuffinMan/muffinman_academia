/*
    GREEDY ALGORITHMS:
Without moving forwards or backwards, algorithm selects the best option at the time.
    A simple example of a greedy algorithm is the "Change Making Algorithm", which determines the amount of each
    type of coin that needs to be given back to the customer.

    GENERAL CHARACTERISTICS:
- Start with a set of candidates which have yet to be considered for the solution.
- As we proceed, we construct two further sets:
    Candidates that have been considered and SELECTED.
    Candidates that have been considered and REJECTED.
- At each step, we see if we have reached the solution.
- At each step, we also check to see if a solution can be reached at all.
- At each step, we selected the BEST POSSIBLE CANDIDATE from the unconsidered set and move it to the selected set.
- We also move any unacceptable candidates into the rejected set.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}