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

    // size_t searchOption = 0;
    // cout << "\nWhat would you like to search for? Options are...\n1.Movies\n2.TV Shows\n3.Music" << endl;
    // cin >> searchOption;
    movieNamespace::MovieClass** searchItem;
    searchItem = mainDatabase.searchMovie("7.7");

    cout << "***DEBUG*** searchItem[1]:";
    searchItem[1]->displayInfo();
    cout << endl;

    cout << "***DEBUG*** searchItem[2]:";
    searchItem[2]->displayInfo();
    cout << endl;

    // mainDatabase.searchMovieCleanup(searchItem, mainDatabase.getNumMovies());

    cout << "\nProgram complete." << endl;
    return 0;
}