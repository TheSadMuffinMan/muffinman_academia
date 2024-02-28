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
    std::size_t const dataBaseArraySize = 20;

    // Declares the mainDataBase that we will be using.
    Database mainDataBase;
    mainDataBase = Database(dataBaseArraySize, dataBaseName, db_id); // Populates the mainDataBase with values.

    mainDataBase.loadData();

    // mainDataBase.addMovie(); // Working
    // mainDataBase.displayAllData(); // Working
    // mainDataBase.removeMovie(); // Working

    mainDataBase.displayAllData();

    return 0;
}