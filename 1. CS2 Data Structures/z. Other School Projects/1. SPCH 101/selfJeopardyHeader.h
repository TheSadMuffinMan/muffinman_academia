#pragma once

#include <iostream>
#include <string>

void welcome();
void printMenu();
void printBoard();
int menuNavigation();

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