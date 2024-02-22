// https://docs.google.com/document/d/17DUCqILo729jUNHhDhvC01qqfuvn05BLLQyhRC8Gy08/edit
#include "main.h"
#include "database.h"
#include "movie.h"

using namespace std;

int main(int argc, char *argv[])
{
    void welcomeFunction();

    size_t dataBaseSize = 10;
    Database mainDatabase = Database(dataBaseSize);

    mainDatabase.databaseCleanup(dataBaseSize);
    // delete &mainDatabase; LOL this works??

    return 0;
}