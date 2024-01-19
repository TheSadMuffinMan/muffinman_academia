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
std::string passwordObject::getUsername()
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

// Setters
// All info setter
void passwordObject::setAllInfo(std::string inputLabel, std::string inputUsername, std::string inputPassword, std::string inputComment)
{
    actualLabel = inputLabel;
    actualUsername = inputUsername;
    actualPassword = inputPassword;
    actualComment = inputComment;
}

// Label setter
void passwordObject::setLabel(std::string userLabel)
{
    actualLabel = userLabel;
}

void passwordObject::setUsername(std::string usernameInput)
{
    actualUsername = usernameInput;
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
// All info printer
void passwordObject::printAllInfo()
{
    std::string label, un, pw, comment;
    label = passwordObject::getLabel();
    un = passwordObject::getUsername();
    pw = passwordObject::getPassword();
    comment = passwordObject::getComment();
    std::cout << "Label: " << label << std::endl;
    std::cout << "Username: " << un << std::endl;
    std::cout << "Password: " << pw << std::endl;
    std::cout << "Comment: " << comment << std::endl;
}

// Label printer
void passwordObject::printLabel()
{
    std::string label;
    label = passwordObject::getLabel();
    std::cout << label << std::endl;
}

// "Editor" Functions
// Edit label function
void passwordObject::editLabel(std::string updatedString)
{
    std::string temp = "NULL";
    passwordObject::setLabel(updatedString);
    temp = passwordObject::getLabel();
    std::cout << "Updated Label: " << temp << std::endl;
}

// Edit username function
void passwordObject::editUsername(std::string updatedString)
{
    std::string temp = "NULL";
    passwordObject::setUsername(updatedString);
    temp = passwordObject::getUsername();
    std::cout << "Updated Username: " << temp << std::endl;
}

// Edit password function
void passwordObject::editPassword(std::string updatedString)
{
    std::string temp = "NULL";
    passwordObject::setPassword(updatedString);
    temp = passwordObject::getPassword();
    std::cout << "Updated Password: " << temp << std::endl;
}

// Edit comment function
void passwordObject::editComment(std::string updatedString)
{
    std::string temp = "NULL";
    passwordObject::setComment(updatedString);
    temp = passwordObject::getComment();
    std::cout << "Updated Comment: " << temp << std::endl;
}