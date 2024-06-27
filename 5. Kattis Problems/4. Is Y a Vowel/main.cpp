// https://open.kattis.com/problems/isyavowel
/*
6/27/24 working on

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
    
    while (userString[positionCounter] != std::string::npos)
    {
        switch(compareChar = userString[positionCounter])
        {
            case 1:
                
            //
        }
        if ((compareChar == 'a') || (compareChar == 'e') (compareChar == 'i') || (compareChar == 'o') ||
        (compareChar == 'u'))
        {
            withoutY++;
            withY++;
        }
    }

    return 0;
}