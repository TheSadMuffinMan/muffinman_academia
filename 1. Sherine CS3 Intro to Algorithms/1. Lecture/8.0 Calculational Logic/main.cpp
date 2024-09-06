/*
KNIGHTS vs KNAVES PROBLEM
You are on an island full of natives that are composed of two groups: knights and knaves.
    Knights always tell the truth, and knaves always lie.

P1) You come across a native. They tell you "There is gold on the island" and "I am a knight". Are they
    telling the truth?
        ANSWER: We cannot definitely answer whether there is gold on the island.
        LOGIC: (A == answer), (G == presence of gold).
            A = (A = G);
            (A = A) = G;
            true = G;
        TAKEAWAY: Some questions do not have an answer.

P2) You come across two natives.
*/

/*
CALCULATIONAL LOGIC
aka Boolean Logic.
Has many properties:
    REFLEXIVE: p = p.
    SYMMETRIC: (p = q) = (q = p)
    TRANSITIVE: if (p = r) and (q = r), then (p = r).
    ASSOCIATIVE: (p = (q = r)) = ((p = q) = r).
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}