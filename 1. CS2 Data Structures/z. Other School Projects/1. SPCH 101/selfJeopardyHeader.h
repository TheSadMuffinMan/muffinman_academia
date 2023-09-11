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
    SurveyObject(int, std::string, std::string, std::string);

    void setPosition(int);
    void setSurveyName(std::string);
    void setSurveyInformation(std::string);
    void setSurveyAnalysis(std::string);

private:
    int position;
    std::string surveyName, surveyInformation, surveyAnalysis;
};