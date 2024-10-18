/*
Program is meant to test small things.
*/
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    std::string testSmallString = "test";
    std::string longString = (testSmallString + ".txt");
    std::cout << longString << std::endl;
    
    int last4pos = (longString.size() - 4);
    std::string txtTest = longString.substr(last4pos);
    std::cout << txtTest << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}