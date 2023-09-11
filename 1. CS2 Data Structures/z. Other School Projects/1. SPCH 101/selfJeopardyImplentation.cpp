#include "selfJeopardyHeader.h"

// Default constructor, sets everything to 0 essentially
SurveyObject::SurveyObject()
{
    position = 0;
    surveyName = "NULL";
    surveyInformation = "NULL";
    surveyAnalysis = "NULL";
}

// Constructor for user made Survey
SurveyObject::SurveyObject(int userPosition, std::string userSurveyName, std::string userSurveyInformation, std::string userSurveyAnalysis)
{
    position = userPosition;
    surveyName = userSurveyName;
    surveyInformation = userSurveyInformation;
    surveyAnalysis = userSurveyAnalysis;
}

void SurveyObject::setPosition(int userPosition)
{
    position = userPosition;
}

void SurveyObject::setSurveyName(std::string userSurveyName)
{
    surveyName = userSurveyName;
}

void SurveyObject::setSurveyInformation(std::string userSurveyInformation)
{
    surveyInformation = userSurveyInformation;
}

void SurveyObject::setSurveyAnalysis(std::string userSurveyAnalysis)
{
    surveyAnalysis = userSurveyAnalysis;
}


void printMenu()
{
    std::cout << "\n\n\t\tMAIN MENU" << std::endl;
    std::cout << "\n\t1. Play game" << std::endl;
    std::cout << "\n\t2. Quit game" << std::endl;
}

void printBoard()
{
    std::cout << "\t ___________ ____________ ___________ ___________" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|     1     |     2      |     3     |     4     |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|     5     |     6      |     7     |     8     |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|     9     |     10     |     11    |     12    |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|    13     |     14     |     15    |     16    |" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;

}