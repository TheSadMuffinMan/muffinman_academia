#include "PWObject.h"

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
    // std::cout << "\nDESTRUCTOR has destructed something :D" << std::endl;
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