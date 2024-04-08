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
void clearTerminal();

int main(int argc, char *argv[])
{
    // clearTerminal();
    cout << "\nProgram start." << endl;
    string advancementString = " ";

    cout << "Hello, and welcome to my second assignment I have turned in \"on time\" this semester :D" << endl;
    cout << "Input anything to continue: ";
    cin >> advancementString;
    cin.ignore(1);

    Database mainDatabase;

    mainDatabase.loadData();

    size_t menuNavigation = 0;
    while (menuNavigation == 0) // Main program loop.
    {
        clearTerminal();
        printMenu();
        cin >> menuNavigation;

        if (menuNavigation == 1) // Display media loop.
        {
            mainDatabase.displayAllMedia();
            cout << "\nInput anything to return to main menu: ";
            cin >> advancementString;
            menuNavigation = 0;
        }

        else if (menuNavigation == 2) // Add media loop.
        {
            // cout << "\n***DEBUG*** Inside add media loop" << endl;
            size_t userChoice = 0;
            cout << "\nWhat type of media would you like to add? Options are..." << endl;
            cout << "1) Add Movie\n2) Add TV Show\n3) Add Music\nUser choice: ";
            cin >> userChoice;

            if (userChoice == 1) // Add movie option.
            {
                cout << "\n\tADD MOVIE" << endl;

                mainDatabase.addMovie();

                cout << "\nInput anything to return back to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

            else if (userChoice == 2) // Add TV option.
            {
                cout << "\n\tADD TV SHOW" << endl;

                mainDatabase.addTVShow();

                cout << "\nInput anything to return back to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

            else if (userChoice == 3) // Add TV option.
            {
                cout << "\n\tADD MUSIC" << endl;

                mainDatabase.addMusic();

                cout << "\nInput anything to return back to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }
        }

        else if (menuNavigation == 3) // Remove media loop.
        {
            size_t userChoice = 0;
            cout << "\n\t***DEBUG Inside Remove Media Loop." << endl;
            cout << "\nWhat type of media would you like to remove? Options are..." << endl;
            cout << "1) Remove Movie\n2) Remove TV Show\n3) Remove Music\nUser choice: ";
            cin >> userChoice;

            if (userChoice == 1) // Remove movie loop.
            {
                size_t deletionIndex = 0;
                cout << "\n\tREMOVE MOVIE" << endl;
                cout << "\nPlease input the index of the movie you would like removed: ";
                cin >> deletionIndex;
                
                mainDatabase.removeMovie(deletionIndex);

                cout << "Please input anything to return to the main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

            else if (userChoice == 2) // Remove TV loop.
            {
                size_t deletionIndex = 0;
                cout << "\n\tREMOVE TV SHOW" << endl;
                cout << "\nPlease input the index of the show you would like removed: ";
                cin >> deletionIndex;
                
                mainDatabase.removeTVShow(deletionIndex);

                cout << "Please input anything to return to the main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

            else if (userChoice == 3) // Remove music loop.
            {
                size_t deletionIndex = 0;
                cout << "\n\tREMOVE MUSIC" << endl;
                cout << "\nPlease input the index of the music you would like removed: ";
                cin >> deletionIndex;
                
                mainDatabase.removeMusic(deletionIndex);

                cout << "Please input anything to return to the main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }
        }

        else if (menuNavigation == 4) // Search for media loop.
        {
            cout << "\n***DEBUG*** Inside search media loop." << endl;

            size_t userChoice = 0;
            cout << "\nWhat type of media would you like to search for? Options are..." << endl;
            cout << "1) Search Movie\n2) Search TV Shows\n3) Search Music\nUser choice: ";
            cin >> userChoice;

            if (userChoice == 1) // Search movie option.
            {
                string searchString = " ";
                cin.ignore(1);
                cout << "Please input what you would like to search for: ";
                getline(std::cin, searchString);

                movieNamespace::MovieClass** searchResult = mainDatabase.searchMovie(searchString);

                size_t loopIndex = 1;
                cout << "\n\tSEARCH RESULTS: " << endl;
                while (true)
                {
                    if (searchResult[loopIndex] == nullptr)
                    {
                        break;
                    }

                    searchResult[loopIndex]->displayInfo();
                    cout << endl;
                    loopIndex++;
                }

                cout << "\nInput anything to return to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

            if (userChoice == 2) // Search TV loop.
            {
                string searchString = " ";
                cin.ignore(1);
                cout << "Please input what you would like to search for: ";
                getline(std::cin, searchString);

                tvShowNamespace::TVShowClass** searchResult = mainDatabase.searchTV(searchString);

                size_t loopIndex = 1;
                cout << "\n\tSEARCH RESULTS: " << endl;
                while (true)
                {
                    if (searchResult[loopIndex] == nullptr)
                    {
                        break;
                    }

                    searchResult[loopIndex]->displayInfo();
                    cout << endl;
                    loopIndex++;
                }

                cout << "\nInput anything to return to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }

            if (userChoice == 3) // Search music loop.
            {
                string searchString = " ";
                cin.ignore(1);
                cout << "Please input what you would like to search for: ";
                getline(std::cin, searchString);

                musicNamespace::MusicClass** searchResult = mainDatabase.searchMusic(searchString);

                size_t loopIndex = 1;
                cout << "\n\tSEARCH RESULTS: " << endl;
                while (true)
                {
                    if (searchResult[loopIndex] == nullptr)
                    {
                        break;
                    }

                    searchResult[loopIndex]->displayInfo();
                    cout << endl;
                    loopIndex++;
                }

                cout << "\nInput anything to return to main menu: ";
                cin >> advancementString;
                menuNavigation = 0;
            }
        }

        else if (menuNavigation == 5) // Output to csv loop.
        {
            cout << "\n***DEBUG*** Inside output to csv loop." << endl;

            mainDatabase.outputDatatoCSV();

            cout << "\nAll data has been pushed to outputFile.csv" << endl;
            cout << "Please input anything to continue: ";
            cin >> advancementString;
            menuNavigation = 0;
        }

        else if (menuNavigation == 6) // Exiting the program "loop".
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
    cout << "\nMenu choice: ";
}

// Function clears the screen.
// Uses "cls" in windows and "clear" command in Mac and Linux.
void clearTerminal()
{
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}