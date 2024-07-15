#include <iostream>
#include <string>

int addAlice(int, int);
int addBarbara(int, int);

int main(int argc, char *argv[])
{
    std::string inputString = "x";
    getline(std::cin, inputString);

    int aliceScore = 0;
    int barbaraScore = 0;
    std::size_t currIndex = 0;

    while (currIndex < inputString.size())
    {
        std::string dataString = inputString.substr(currIndex, 2);
        char dirtyDataScore = dataString.at(1);
        
        int cleanDataScore = (dirtyDataScore - '0'); // https://sentry.io/answers/char-to-int-in-c-and-cpp/
        
        if (dataString.at(0) == 'A')
        {
            aliceScore = addAlice(aliceScore, cleanDataScore);
        }
        else
        {
            barbaraScore = addBarbara(barbaraScore, cleanDataScore);
        }

        currIndex = (currIndex + 2);
    }

    if (aliceScore > barbaraScore) {std::cout << "A" << std::endl;}
    else {std::cout << "B" << std::endl;}
    
    return 0;
}

int addAlice(int currScore, int toBeAdded)
{
    return currScore + toBeAdded;
}

int addBarbara(int currScore, int toBeAdded)
{
    return currScore + toBeAdded;
}