#pragma once
#include <string>

class passwordObject
{
public:
    passwordObject(); // Default constructor
    ~passwordObject(); // Destructor

    passwordObject(std::string, std::string, std::string, std::string); // Builds our password object

    // Getters
    std::string getLabel();
    std::string getUsername();
    std::string getPassword();
    std::string getComment();

    // Setters
    void setAllInfo(std::string, std::string, std::string, std::string);
    void setLabel(std::string);
    void setUsername(std::string);
    void setPassword(std::string);
    void setComment(std::string);

    // Prints all information inside object
    void printAllInfo();
    void printLabel();

    // "Editors"
    void editLabel(std::string);
    void editUsername(std::string);
    void editPassword(std::string);
    void editComment(std::string);

private:
    std::string actualLabel, actualUsername, actualPassword, actualComment;
};