// Important to remember that Tim recycles a bottle every time he reaches newSodaRate.

#include <iostream>

int main(int argc, char *argv[])
{
    int startEmptySodas = 0;
    int foundEmptySodas = 0;
    int newSodaRate = 0;

    std::cin >> startEmptySodas >> foundEmptySodas >> newSodaRate;

    int result1 = (startEmptySodas / newSodaRate);
    int result1remainder = (startEmptySodas % newSodaRate);

    int result2 = (foundEmptySodas / newSodaRate);
    int result2remainder = (foundEmptySodas % newSodaRate);

    int totalRemainder = (result1remainder + result2remainder);

    int totalDrank = (result1 + result2);
    if (totalRemainder >= newSodaRate)
    {
        totalDrank++;
    } 

    std::cout << std::endl << totalDrank;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/*
FIRST ATTEMPT:
    while (startEmptySodas >= newSodaRate)
    {
        startEmptySodas = (startEmptySodas - newSodaRate);
        totalDrank++;
    }

    foundEmptySodas = (foundEmptySodas + startEmptySodas); // Carrying over startEmptySodas remainder (if any).
    while (foundEmptySodas >= newSodaRate)
    {
        foundEmptySodas = (foundEmptySodas - newSodaRate);
        totalDrank++;
    }
*/