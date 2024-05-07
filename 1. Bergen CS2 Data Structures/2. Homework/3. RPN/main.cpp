#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

double evaluateRPN(string expression)
{
    return 0.0;
}

int main(int argc, char *argv[])
{
    cout << "\nProgram start." << endl;

    Stack<string> mainStack;
    mainStack.userInput();

    mainStack.printStack();

    cout << "\nProgram completed." << endl;
    return 0;
}