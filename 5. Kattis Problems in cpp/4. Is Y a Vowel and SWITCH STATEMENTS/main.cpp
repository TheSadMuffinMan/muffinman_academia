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