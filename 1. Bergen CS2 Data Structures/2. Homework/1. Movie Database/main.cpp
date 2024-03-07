// https://docs.google.com/document/d/17DUCqILo729jUNHhDhvC01qqfuvn05BLLQyhRC8Gy08/edit
#include "main.h"
#include "database.h"
#include "movie.h"

using namespace std;

int main(int argc, char *argv[])
{
    void welcomeFunction();

    string dataBaseName = "DataBase located in Main";
    int db_id = 1;
    std::size_t const dataBaseArraySize = 20; // This eliminates the use of "magic numbers".

    // Declares the mainDataBase that we will be using.
    Database mainDataBase = Database(dataBaseArraySize, dataBaseName, db_id); // Populates the mainDataBase with values.

    mainDataBase.loadData();

    mainDataBase.displayAllMovieTitles();

    size_t menuChoice = 0;
    cout << "\n\tMENU: ";


    // mainDataBase.addMovie(); // Working
    // mainDataBase.displayAllData(); // Working
    // mainDataBase.removeMovie(); // Working

    // movieNamespace::MovieClass** tempArray;
    // tempArray = mainDataBase.searchFunction();

    // mainDataBase.outputToCSV(tempArray);

    cout << "\nProgram complete." << endl;
    return 0;
}