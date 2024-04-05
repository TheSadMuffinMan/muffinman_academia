// https://docs.google.com/document/d/17DUCqILo729jUNHhDhvC01qqfuvn05BLLQyhRC8Gy08/edit
#include "mediaDatabase.h"
#include "media.h"
#include "movie.h"
#include "tvshows.h"
#include "music.h"

#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void printMenu();
void clearScreen();

int main(int argc, char *argv[])
{
    cout << "\nProgram start." << endl;
    string advancementString = " ";

    cout << "Hello, and welcome to my second assignment I have turned in \"on time\" this semester :D" << endl;
    cout << "Input anything to continue: ";
    cin >> advancementString;

    Database mainDatabase;

    mainDatabase.loadData();

    size_t menuNavigation = 0;
    while (menuNavigation == 0) // Main program loop.
    {
        printMenu();
        cin >> menuNavigation;

        if (menuNavigation == 1) // Display media loop.
        {
            cout << "\n***DEBUG*** Inside display media loop." << endl;
            mainDatabase.displayAllMedia();
            cout << "\nInput anything to return to main menu: ";
            cin >> advancementString;
            menuNavigation = 0;
        }

        else if (menuNavigation == 2) // Add media loop.
        {
            cout << "\n***DEBUG*** Inside add media loop" << endl;
            size_t userChoice = 0;
            cout << "\nWhat type of media would you like to add? Options are..." << endl;
            cout << "1) Add Movie\n2) Add TV Show\n3) Add Music\nUser choice: ";
            cin >> userChoice;

            if (userChoice == 1) // Add movie option.
            {
                cout << "\n\tADD MOVIE" << endl;

                mainDatabase.userAddMovie();

                cout << "\nInput anything to return back to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

            else if (userChoice == 2) // Add TV option.
            {
                cout << "\n\tADD TV SHOW" << endl;
                string tempString;
                tvShowNamespace::TVShowClass* userTV;

                cout << "\nIMBD ID: ";
                getline(cin, tempString);
                userTV->setMediaIMDBID(tempString);

                cout << "\nShow Title: ";
                getline(cin,tempString);
                userTV->setMediaTitle(tempString);

                cout << "\nShow Year: ";
                cin >> tempString;
                userTV->setMediaYear(tempString);

                cout << "\nShow Genre: ";
                getline(cin, tempString);
                userTV->setMediaGenre(tempString);

                cout <<"\nShow Rating (one decimal): ";
                getline(cin, tempString);
                userTV->setRating(tempString);

                cout << "\nNumber of Episodes: ";
                getline(cin, tempString);
                userTV->setNumEpisodes(tempString);

                mainDatabase.addTVShow(userTV);

                cout << "\n\Input anything to return back to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

        }

        if (menuNavigation == 6)
        {
            break;
        }
    }

    cout << "\nProgram complete." << endl;
    return 0;
}

// Function prints out the main menu.
void printMenu()
{
    cout << "\n\t\tMEDIA DATABASE MENU :D" << endl;
    cout << "\t1) Display Media" << endl;
    cout << "\t2) Add Media" << endl;
    cout << "\t3) Remove Media" << endl;
    cout << "\t4) Search for Media" << endl;
    cout << "\t5) Output All Data to .csv file" << endl;
    cout << "\t6) Exit program" << endl;
    cout << "\nPlease input desired choice: ";
}

// Function clears the screen.
// Uses "cls" in windows and "clear" command in Mac and Linux.
void clearScreen()
{
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}