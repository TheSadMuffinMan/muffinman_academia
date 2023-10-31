#include "passwordManager.h"

// Default constructor
passwordObject::passwordObject()
{
    actualLabel = "DEFAULT";
    actualUsername = "DEFAULT";
    actualPassword = "DEFAULT";
    actualComment = "DEFAULT";
}

// Destructor
passwordObject::~passwordObject()
{
    std::cout << "\nDESTRUCTOR has destructed something :D" << std::endl;
}

passwordObject::passwordObject(std::string inputLabel, std::string inputUsername, std::string inputUserPassword, std::string inputComment)
{
    actualLabel = inputLabel;
    actualUsername = inputUsername;
    actualPassword = inputUserPassword;
    actualComment = inputComment;
}

// Label getter
std::string passwordObject::getLabel()
{
    return actualLabel;
}


// Username getter
std::string passwordObject::getUserName()
{
    return actualUsername;
}

// Password getter
std::string passwordObject::getPassword()
{
    return actualPassword;
}

// Comment getter
std::string passwordObject::getComment()
{
    return actualComment;
}

// Label setter
void passwordObject::setLabel(std::string userLabel)
{
    actualLabel = userLabel;
}

// Username setter
void passwordObject::setUserName(std::string userNameInput)
{
    actualUsername = userNameInput;
}

// Password setter
void passwordObject::setPassword(std::string userPasswordInput)
{
    actualPassword = userPasswordInput;
}

// Comment setter
void passwordObject::setComment(std::string userComment)
{
    actualComment = userComment;
}

void programMenu()
{
    system("clear");
    std::cout << "\n\t\t MAIN MENU" << std::endl;
    std::cout << "\n\t1. View Passwords" << std::endl;
    std::cout << "\n\t2. Input New Password" << std::endl;
}

int menuChoiceChecker(int userInput)
{
    while (true)
    {
        std::cin >> userInput;
        if (userInput == 1)
        {
            break;
        }
        else if (userInput == 2)
        {
            break;
        }
        std::cout << "Invalid input, try again: ";
    }
    return userInput;
}

/* DO NOT DELETE, NEED FOR NEXT TUTORING SESSION.
Give a man a fish, you feed him, teach a man to fish, and he'll be fed for a lifetime
void printPasswordObject(passwordObject)
{
    std::string displayPassword;
    displayPassword = passwordObject::getPassword();
}
*/