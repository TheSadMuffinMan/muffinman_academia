/* COMPUTATIONAL THEORY:

Fundamental Questions:
    - What can a computer do?
    - What can a computer do with limited resources?

General Approach:
    - Don't talk about specific machines or problems.
    - Consider minimal abstract machines.
    - Consider general classes of problems.

Key Terms:
    - Abstract machine: defined by specific rules for transforming input to output.
    - Deterministic Finite Automata (DFAs): a computer.
    - Regular Expression (RE): the basic system used to quantify a string.

Use Cases:
    - Pattern matching (Ex: amino acid searching, genomics, scrubbing valid email address input, etc).
*/

/* REGULAR EXPRESSION (RE):
===============================================================================
    OPERATION     | EXAMPLE RE  | Matches (in the set) |    Does NOT match    |
===============================================================================
   concatenation  |   aabaab    |       aabaab         | *every other string* |
===============================================================================
     wildcard     |  .u.u.u.    |   cumulus, jugulum   | succubus, tumultuous |
===============================================================================
      union       |  aa | baab  |      aa, baab        | *every other string* |
===============================================================================
     closure      |    ab*a     |      aa, abbba       |     ab, ababa        |
===============================================================================
    parenthesis   |  a(a|b)aab  |    aaaab, abaab      | *every other string* |
    parenthesis   |   (ab)*a    |    a, ababababa      |     aa, abbba        |
===============================================================================

    Examples:
===========================================================================
 Regular Expression (RE)  |        Matches        |    Does not match     |
===========================================================================
        .*spb.*           | raspberry, crispbread |  subspace, subspecies |
===========================================================================
   a* | (a*ba*ba*ba*)*    | bbb, aaa, bbbaababbaa |    b, bb, baabbaa     |
===========================================================================
       .*0....            |   1000234, 98701234   | 111111111, 403982772  |
===========================================================================
                          |     ...gcgctg...      |         gcgcgg        |
   .*gcg(cgg|agg)*ctg.*   |    ...gcgcggctg...    |      cggcggcggctg     |
                          |   ...gcgcggaggctg...  |       gcgcaggctg      |
===========================================================================
*/

/*
- A DFA and RE represent the same thing: they are just two different ways of representing strings.
    - A DFA is the visualization, and the RE is the text representation.
- 
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}