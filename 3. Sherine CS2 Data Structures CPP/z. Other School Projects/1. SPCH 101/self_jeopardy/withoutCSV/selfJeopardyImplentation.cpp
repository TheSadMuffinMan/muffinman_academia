#include "selfJeopardyHeader.h"

// Default constructor, sets everything to "NULL"
SurveyObject::SurveyObject()
{
    surveyName = "NULL";
    surveyInformation = "NULL";
    surveyAnalysis = "NULL";
}

// Constructor for user made Survey
SurveyObject::SurveyObject(std::string userSurveyName, std::string userSurveyInformation, std::string userSurveyAnalysis)
{
    surveyName = userSurveyName;
    surveyInformation = userSurveyInformation;
    surveyAnalysis = userSurveyAnalysis;
}

SurveyObject::~SurveyObject()
{
    std::cout << "\n***Ignore this line*** DESTRUCTOR has done something" << std::endl;
}

// Getters
std::string SurveyObject::getSurveyName()
{
    return surveyName;
}

std::string SurveyObject::getSurveyInformation()
{
    return surveyInformation;
}

std::string SurveyObject::getSurveyAnalysis()
{
    return surveyAnalysis;
}


// Setters
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


void welcome()
{
    std::cout << "Welcome to. . ." << std::endl;
    std::cout << " _____ _____ _     ______     ___ _____ ___________  ___  ______________   __" << std::endl;
    std::cout << "/  ___|  ___| |    |  ___|   |_  |  ___|  _  | ___ \\/ _ \\ | ___ \\  _  \\ \\ / /" << std::endl;
    std::cout << "\\ `--.| |__ | |    | |_        | | |__ | | | | |_/ / /_\\ \\| |_/ / | | |\\ V / "<< std::endl;
    std::cout << " `--. \\  __|| |    |  _|       | |  __|| | | |  __/|  _  ||    /| | | | \\ /" << std::endl;
    std::cout << "/\\__/ / |___| |____| |     /\\__/ / |___\\ \\_/ / |   | | | || |\\ \\| |/ /  | |  " << std::endl;
    std::cout << "\\____/\\____/\\_____/\\_|     \\____/\\____/ \\___/\\_|   \\_| |_/\\_| \\_|___/   \\_/" << std::endl;
    std::cout << "\nPress ENTER to continue. . .";

}

void printMenu()
{
    std::cout << "\n\n\t\tMAIN MENU" << std::endl;
    std::cout << "\n\t1. Play game" << std::endl;
    std::cout << "\n\t2. Quit game" << std::endl;
    // std::cout << "\n\n\tPlease enter your selection: " << std::endl;
}

int menuNavigation()
{
    int navigationChoice;
    std::cout << "\n\tPlease enter your choice: ";
    std::cin >> navigationChoice;
    return navigationChoice;
}

void printBoard()
{
    std::cout << "\t ___________ ____________ ___________ ___________" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|     1     |      2     |     3     |     4     |" << std::endl;
    std::cout << "\t|    Big    |    Which   |  First-   |   AMBI    |" << std::endl;
    std::cout << "\t|    Five   |  Character |   Born    | (Big one) |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|     5     |     6      |     7     |     8     |" << std::endl;
    std::cout << "\t|Personality| Enneagram  |  Zodiac   | Woodworth |" << std::endl;
    std::cout << "\t|   Type    |   Scale    |   Sign    |  Psycho   |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|     9     |     10     |     11    |     12    |" << std::endl;
    std::cout << "\t|Short Dark |    Nerd    |    DISC   | Cattell's |" << std::endl;
    std::cout << "\t|   Triad   |    Test    | Assess..  |  Factors  |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;
    std::cout << "\t|           |            |           |           |" << std::endl;
    std::cout << "\t|    13     |     14     |    15     |     16    |" << std::endl;
    std::cout << "\t|  Nature   |   BLANK    |   BLANK   |  OPEN FOR |" << std::endl;
    std::cout << "\t|Relatedness|            |           |  SURPRISE |" << std::endl;
    std::cout << "\t|___________|____________|___________|___________|" << std::endl;
}