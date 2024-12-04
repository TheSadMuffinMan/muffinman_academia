#include <iostream>
#include "muffinScrubber.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    MuffinTXTscrubber txtScrubber;

    txtScrubber.debugFunction();

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
