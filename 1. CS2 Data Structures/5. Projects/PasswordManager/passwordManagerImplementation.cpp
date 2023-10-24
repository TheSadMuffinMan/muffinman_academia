#include "passwordManager.h"

// Default constructor
passwordObject::passwordObject()
{
    actualUsername = "DEFAULT";
    actualPassword = "DEFAULT";
}

// Destructor
passwordObject::~passwordObject()
{
    std::cout << "\nDESTRUCTOR has destructed something :D" << std::endl;
}

passwordObject::passwordObject(std::string inputUsername, std::string inputUserPassword, std::string inputComment)
{
    actualUsername = inputUsername;
    actualPassword = inputUserPassword;
    actualComment = inputComment;
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

int menuChoiceCleaner(int userInput)
{
    
    while (userInput != 1 || userInput != 2)
    {
        std::cout << "Invalid input. Please enter either 1 or 2. " << std::endl;
    }
    return userInput;
}