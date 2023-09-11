#pragma once

#include <iostream>
#include <string>

void welcome(); // Prints the ASCII art
void printMenu(); // Prints the menu
void printBoard(); // Prints the game board
int menuNavigation(); // Returns the user's navigation choice for the menu

class SurveyObject
{
public:
    SurveyObject();
    SurveyObject(std::string, std::string, std::string);
    ~SurveyObject();

    void printObject();

    // Getters
    std::string getSurveyName();
    std::string getSurveyInformation();
    std::string getSurveyAnalysis();

    // Setters
    // void setPosition(int); // I don't think I need this one
    void setSurveyName(std::string);
    void setSurveyInformation(std::string);
    void setSurveyAnalysis(std::string);

private:
    std::string surveyName, surveyInformation, surveyAnalysis;
};