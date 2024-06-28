// https://open.kattis.com/problems/isyavowel
/*
6/28/24 COMPLETE, first try :D

INPUT:
    The single line of input contains a string of at least one and at most lowercase letters.

OUTPUT:
    Output two space-separated integers. The first is the number of vowels assuming y is not
        a vowel, the second is the number of vowels assuming y is a vowel.
*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string userString = " ";
    std::cin >> userString;

    std::size_t withoutY = 0;
    std::size_t withY = 0;
    std::size_t positionCounter = 0;
    char compareChar = ' ';
    
    while ((positionCounter >= 0) && (positionCounter < userString.length()))
    {
        switch(compareChar = userString.at(positionCounter))
        {
            case 'a':
                    withoutY++;
                    withY++;
                    positionCounter++;
                    break;
            case 'e':
                    withoutY++;
                    withY++;
                    positionCounter++;
                    break; 
            case 'i':
                    withoutY++;
                    withY++;
                    positionCounter++;
                    break; 
            case 'o':
                    withoutY++;
                    withY++;
                    positionCounter++;
                    break; 
            case 'u':
                    withoutY++;
                    withY++;
                    positionCounter++;
                    break;
            case 'y':
                    withY++;
                    positionCounter++;
                    break;
            default: /* Need a default case because if a letter is anything else,
                    positionCounter still needs to be incremented. */
                positionCounter++;
                break;
        }
    }

    // std::cout << "\n WithoutY: " << withoutY << ", withY: " << withY << std::endl;
    std::cout << std::endl << withoutY << " " << withY << std::endl;
    return 0;
}