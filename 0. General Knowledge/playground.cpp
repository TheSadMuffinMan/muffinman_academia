/*
Program is meant to test small things.
*/
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    std::string testSmallString = "test";
    std::string longString = (testSmallString + ".txt");
    std::cout << longString;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}