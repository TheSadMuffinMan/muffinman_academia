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

    // Declares the mainDataBase that we will be using
    Database mainDataBase = Database(dataBaseName, db_id);

    // delete &mainDatabase; // Invalid pointer, thought I was on to something cool lol.

    return 0;
}