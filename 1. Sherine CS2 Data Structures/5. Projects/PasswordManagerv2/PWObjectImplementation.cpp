#include "PWObject.h"
#include <iostream>

// Default constructor
passwordObject::passwordObject()
{
    actualLabel = "NULL";
    actualUsername = "NULL";
    actualPassword = "NULL";
    actualComment = "NULL";
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

// Print Functions
void passwordObject::printAllInfo()
{
    std::string label, un, pw, comment;
    label = passwordObject::getLabel();
    un = passwordObject::getUserName();
    pw = passwordObject::getPassword();
    comment = passwordObject::getComment();
    std::cout << "Label: " << label << std::endl;
    std::cout << "Username: " << un << std::endl;
    std::cout << "Password: " << pw << std::endl;
    std::cout << "Comment: " << comment << std::endl;
}