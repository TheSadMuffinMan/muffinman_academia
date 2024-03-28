// https://docs.google.com/document/d/17DUCqILo729jUNHhDhvC01qqfuvn05BLLQyhRC8Gy08/edit
// See mediaDatabase.h for the "TO-DO List".
#include "main.h"
#include "mediaDatabase.h"
#include "media.h"
#include "movie.h"
#include "tvshows.h"
#include "music.h"

using namespace std;

int main(int argc, char *argv[])
{
    welcomeFunction();

    Database mainDatabase;

    mainDatabase.loadData();

    mainDatabase.removeMovie(2);
    cout << "\n***DEBUG*** Movie should be removed." << endl;

    mainDatabase.displayAllMedia();

    cout << "\nProgram complete." << endl;
    return 0;
}