// https://docs.google.com/document/d/17DUCqILo729jUNHhDhvC01qqfuvn05BLLQyhRC8Gy08/edit
#include "main.h"
#include "database.h"
#include "movie.h"

using namespace std;

int main(int argc, char *argv[])
{
    welcomeFunction();

    string dataBaseName = "DataBase located in Main";
    int db_id = 1;
    std::size_t const dataBaseArraySize = 20; // This eliminates the use of "magic numbers".

    // Declares the mainDataBase that we will be using.
    Database mainDataBase = Database(dataBaseArraySize, dataBaseName, db_id); // Populates the mainDataBase with values.

    mainDataBase.loadData();


    std::string garbVariable = "";
    size_t menuChoice = 0;

    while (menuChoice == 0) // Main menu loop.
    {
        mainDataBase.displayAllMovieTitles();
        
        std::cout << "\n\tMENU: " << std::endl;
        std::cout << "1. Display all information\t2. Add Movie" << std::endl;
        std::cout << "3. Remove Movie\t4. Search for Movie" << std::endl;
        std::cout << "5. Output to .csv\t6. Exit Program" << std::endl;
        std::cout << "Menu Choice: ";
        std::cin >> menuChoice;

        while (menuChoice == 1) // Display all info loop.
            {
                clearScreen();
                mainDataBase.displayAllData();
                std::cout << "Press Enter to continue.";
                getline(std::cin, garbVariable);
                std::cin.ignore();
                menuChoice = 0;
            }

        while (menuChoice == 2) // Add movie loop.
            {
                clearScreen();
                mainDataBase.addMovie();
                std::cout << "Press enter to continue.";
                getline(std::cin, garbVariable);
                std::cin.ignore();
                menuChoice = 0;
            }

        while (menuChoice == 3) // Remove movie loop.
            {
                clearScreen();
                mainDataBase.removeMovie();
                std::cout << "Press enter to continue.";
                getline(std::cin, garbVariable);
                std::cin.ignore();
                menuChoice = 0;
            }

        while (menuChoice == 4) // Search for movie loop.
            {
                clearScreen();
                mainDataBase.searchFunction();
                std::cout << "Press enter to continue.";
                getline(std::cin, garbVariable);
                std::cin.ignore();
                menuChoice = 0;
            }

        while (menuChoice == 5) // Output to CSV loop.
            {
                clearScreen();
                std::cout << "Not coded yet lol" << std::endl;
                getline(std::cin, garbVariable);
                std::cin.ignore();
                menuChoice = 0;
            }

        if ((menuChoice < 0) || (menuChoice > 6))
            {
                menuChoice = 0;
            }
    }

    cout << "\nProgram complete." << endl;
    return 0;
}