#pragma once
#include "PWManager.h"
#include <string>

class passwordObject
{
public:
    passwordObject(); // Default constructor
    ~passwordObject(); // Destructor

    passwordObject(std::string, std::string, std::string, std::string); // Builds our password object

    // Getters
    std::string getLabel();
    std::string getPassword();
    std::string getUserName();
    std::string getComment();

    // Setters
    void setLabel(std::string);
    void setPassword(std::string);
    void setUserName(std::string);
    void setComment(std::string);

private:
    std::string actualLabel, actualUsername, actualPassword, actualComment;
};