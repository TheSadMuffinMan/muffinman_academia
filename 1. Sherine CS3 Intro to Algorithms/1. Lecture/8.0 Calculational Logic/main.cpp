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

P2) You come across two natives. You ask each if the other is a knight. Do you get the same answer from both?
    ANSWER: Native1 will answer yes, and Native2 must also answer yes. Native1's answer must be the same as Native2's.
        Q = (A = B);
        (A = B) = (B = A);
        Q = (B = A); SYMMETRIC PROPERTIES.

P3) There are three natives, A, B, and C. A says "B and C are of the same type." What can we conclude about the
    number of knights present? C says A and B aare as like as two peas in a pod.
        ***NOTE**** We need to summarize the deduction to come to an accurate conclusion.
        A = (B = C); // If A is a knight, then all three are knights. The only thing we can conclude is that
            there are an ODD NUMBER OF KNIGHTS present.
        Q = (A = C);
        C = (A = B);

P4) There are three natives, A, B, and C. A says "B and C are of the same type". What questions can we ask C to
    find out if A is telling the truth?
        Q = (A = (A = B)); // "(A = (A = B))" can be simplified as "B".
.       ANSWER: So, ask B if they are a knight.
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