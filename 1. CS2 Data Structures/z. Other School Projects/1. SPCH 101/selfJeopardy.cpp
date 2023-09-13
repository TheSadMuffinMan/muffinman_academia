/*
Name: Anthony Streich
Date: 11 September 2023
SELF JEOPARDY
CURRENT ISSUES: Game functionality
*/

#include "selfJeopardyHeader.h"

#define clear() system("clear")

using namespace std;

int main(int argc, char *argv[])
{
    string tempVariable = "TEMPVAR";
    cout << "Program is ready to proceed. Press any ENTER to continue. . ." << endl;
    getline(cin, tempVariable);

    clear();
    welcome();

    getline(cin, tempVariable);
    clear();

    printMenu();
    int userChoice = menuNavigation();

    SurveyObject *objectAddresses[4][4]; // Creates our 4x4 array of pointers to *type* SurveyObjects


    while (userChoice == 1) // This starts the game
    {
        clear();

        printBoard();
        cout << "\nWhich tile would you like to reveal? ";
        int panelChoice;
        cin >> panelChoice;
        
        if (panelChoice == 1) // Big Five
        {
            SurveyObject surveyBigFive("\nBig Five Personality Test", "Highest: Conscientiousness\nLowest: Emotional Stability", "This test came as no surprise, and I feel it is accurate."); // Creates our first object
            objectAddresses[0][0] = &surveyBigFive; // Gives our object a home

            cout << objectAddresses[0][0]->getSurveyName() << endl;
            cout << objectAddresses[0][0]->getSurveyInformation() << endl;
            cout << objectAddresses[0][0]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 2) // Which Character
        {
            SurveyObject surveyCharacter("\n\"Which Character?\" Quiz", "87% match with Jerry Seinfeld", "Felt this one was dumb. The \"lower\" levels matched, but the upper levels were not close.");
            objectAddresses[0][1] = &surveyCharacter;

            cout << objectAddresses[0][1]->getSurveyName() << endl;
            cout << objectAddresses[0][1]->getSurveyInformation() << endl;
            cout << objectAddresses[0][1]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 3) // Firstborn
        {
            SurveyObject surveyFirstborn ("\nFirstborn Personality Scale", "Scored 60 / 100", "Average firstborn score was 53.5, so my results corroborate their findings.");
            objectAddresses[0][2] = &surveyFirstborn;

            cout << objectAddresses[0][2]->getSurveyName() << endl;
            cout << objectAddresses[0][2]->getSurveyInformation() << endl;
            cout << objectAddresses[0][2]->getSurveyAnalysis() << endl;

        }
        else if (panelChoice == 4) // Analog to Multiple Braodband Inventories (AMBI) Big ass one
        {
            SurveyObject surveyAMBI("\nAnalog to Multiple Broadband Inventories (AMBI)", "Lots of data, see Speaking Book", "Life is pain, Jerry.");
            objectAddresses[0][3] = &surveyAMBI;

            cout << objectAddresses[0][3]->getSurveyName() << endl;
            cout << objectAddresses[0][3]->getSurveyInformation() << endl;
            cout << objectAddresses[0][3]->getSurveyAnalysis() << endl;

        }
        else if (panelChoice == 5) // Jungian Personality Types
        {
            SurveyObject surveyJungian("\nOpen extended Jungian Type Scales", "Personality Type: ESTJ", "Extrovert > Introvert\nSensing>Intuition\nThinking>Feeling\nJudging>Perceiving");
            objectAddresses[1][0] = &surveyJungian;

            cout << objectAddresses[1][0]->getSurveyName() << endl;
            cout << objectAddresses[1][0]->getSurveyInformation() << endl;
            cout << objectAddresses[1][0]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 6) // Open Enneagram
        {
            SurveyObject surveyEnneagram("\nOpen Ennegram of Personality Scales", "Type 8 was the highest", "I spent the least amount of time on this one. T5 was second, and T3/T1 were tied for third.");
            objectAddresses[1][1] = &surveyEnneagram;

            cout << objectAddresses[1][1]->getSurveyName() << endl;
            cout << objectAddresses[1][1]->getSurveyInformation() << endl;
            cout << objectAddresses[1][1]->getSurveyAnalysis() << endl;

        }
        else if (panelChoice == 7) // Zodiac
        {
            SurveyObject surveyZodiac("\nZodiac-Sign Associated Personality Scales", "***I am a Cancer***", "It predicted I am a Virgo. Capricorn second, Cancer/Aquarius tied for third.");
            objectAddresses[1][2] = &surveyZodiac;

            cout << objectAddresses[1][2]->getSurveyName() << endl;
            cout << objectAddresses[1][2]->getSurveyInformation() << endl;
            cout << objectAddresses[1][2]->getSurveyAnalysis() << endl;

        }
        else if (panelChoice == 8) // Woodworth
        {
            SurveyObject surveyWoodworth("\nWoodworth Psychoneurotic Inventory", "Scored 19/116", "This is fairly average of modern times. I would have been labelled \"unstable\" in the 1900's :D");
            objectAddresses[1][3] = &surveyWoodworth;

            cout << objectAddresses[1][3]->getSurveyName() << endl;
            cout << objectAddresses[1][3]->getSurveyInformation() << endl;
            cout << objectAddresses[1][3]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 9) // Short Dark Triad
        {
            SurveyObject surveyTriad("\nShort Dark Triad", "Machiavellianism: 3.9/5.... Yikes\nNarcissism: 2.8/5 Yikes...\nPsychopthy: 1.8/5", "At least Psychopathy is low lol");
            objectAddresses[2][0] = &surveyTriad;

            cout << objectAddresses[2][0]->getSurveyName() << endl;
            cout << objectAddresses[2][0]->getSurveyInformation() << endl;
            cout << objectAddresses[2][0]->getSurveyAnalysis() << endl;

        }
        else if (panelChoice == 10) // Nerd Test
        {
            SurveyObject surveyNerd("\nNerd Test", "What do you think I scored?", "58/70, was a little surprised at how low it was because I am definitely a nerd");
            objectAddresses[2][1] = &surveyNerd;

            cout << objectAddresses[2][1]->getSurveyName() << endl;
            cout << objectAddresses[2][1]->getSurveyInformation() << endl;
            cout << objectAddresses[2][1]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 11) // DISC Assessment
        {
            SurveyObject surveyDISC("\nDISC Assessment Type", "Highest score was type \"I\"", "This was the first test that I completely disagreed with. See Speaking Journal for more.");
            objectAddresses[2][2] = &surveyDISC;

            cout << objectAddresses[2][2]->getSurveyName() << endl;
            cout << objectAddresses[2][2]->getSurveyInformation() << endl;
            cout << objectAddresses[2][2]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 12) // Cattell's
        {
            SurveyObject surveyCattell("\nCattell's 16 Personality Factors Test", "Lowest score: Emotional Stability\nHighest Score: Vigilance??", "The second highest was a tie between Reasoning and Openness-to-Change.");
            objectAddresses[2][3] = &surveyCattell;

            cout << objectAddresses[2][3]->getSurveyName() << endl;
            cout << objectAddresses[2][3]->getSurveyInformation() << endl;
            cout << objectAddresses[2][3]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 13) // Nature
        {
            SurveyObject surveyNature("\nNature Relatedness Scale", "3.17 / 5", "Ever so slightly below average");
            objectAddresses[3][0] = &surveyNature;

            cout << objectAddresses[3][0]->getSurveyName() << endl;
            cout << objectAddresses[3][0]->getSurveyInformation() << endl;
            cout << objectAddresses[3][0]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 14)
        {
            cout << "\nThis panel is blank, nerd." << endl;
        }
        else if (panelChoice == 15)
        {
            cout << "\nAHHHHHHHHHH I DON'T HAVE THE RANDOM FEATURE CODED YET" << endl;
        }
        else if (panelChoice == 16)
        {
            clear();
            cout << "Are you sure you're ready for panel 16?";
            cin >> tempVariable;

            clear();
            cout << "You asked for it. . ." << endl;
            cin >> tempVariable;

            cout << "\n\t /\\_/\\" << endl;
            cout << "\t(='_' )" << endl;
            cout << "\t(,(\")(\")" << endl;
        }
        else
        {
            cout << "***** Program has goofed in panelChoice area D: *****" << endl;
        }

        cout << "\nEnter \"1\" if you would like to keep playing, and \"2\" to exit. ";
        cin >> userChoice;
    }

    if (userChoice == 2) // If the user wishes to exit the game
    {
        clear();
        cout << "\nThank you for playing! The game will now exit. \n" << endl;
        getline(cin, tempVariable);
        exit(0);
    }

    return 0;
}