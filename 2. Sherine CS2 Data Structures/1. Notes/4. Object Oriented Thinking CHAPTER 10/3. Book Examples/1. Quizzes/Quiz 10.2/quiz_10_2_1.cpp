/* ***QUESTION 1***
Assume that an int variable pos, as well as the strings line and clause, have already been declared.
Write a sequence of statements that finds the first comma in line, and assigns to clause the portion
of line up to, but not including the comma.
*/
// Accepted first try!

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int pos;
    string line, clause;

    line = "Hello, World";

    pos = line.find(',');
    clause = line.substr(0, pos);

    cout << "clause: " << clause << endl;

    return 0;
}