#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <random>

class passwordObject
{
public:
    passwordObject(); // Default constructor
    passwordObject(std::string); // Builds our password object
    ~passwordObject();

    // Getters
    std::string getPasswordName();

    // Setters
    void setPasswordName(std::string);

private:
    std::string actualPassword, actualUserName;
};