#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

/// @brief The password object class, composed of a username, password, and comment
class passwordObject
{
public:
    passwordObject(); // Default constructor
    ~passwordObject(); // Destructor
    passwordObject(std::string, std::string, std::string); // Builds our password object

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

/// @brief Prints the main menu of the program
void programMenu();

/// @brief Menu Choice Checker
/// @param int
/// @return Returns the "checked" menu choice
int menuChoiceChecker(int);


/// @brief Prints out all contents of a password object
/// @param  passwordObject
void printPasswordObject(passwordObject);