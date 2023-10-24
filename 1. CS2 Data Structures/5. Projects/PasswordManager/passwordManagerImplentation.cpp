#include "passwordManager.h"

// Default constructor
passwordObject::passwordObject()
{
    actualUserName = NULL;
    actualPassword = NULL;
}

// Destructor
passwordObject::~passwordObject()
{
    std::cout << "\nDESTRUCTOR has destructed something :D" << std::endl;
}

passwordObject::passwordObject(std::string inputUserName, std::string inputUserPassword, std::string inputComment)
{
    actualUserName = inputUserName;
    actualPassword = inputUserPassword;
    actualComment = inputComment;
}

// Username getter
std::string passwordObject::getUserName()
{
    return actualUserName;
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