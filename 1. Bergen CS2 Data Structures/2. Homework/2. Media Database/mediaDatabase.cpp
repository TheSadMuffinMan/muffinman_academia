#include "mediaDatabase.h"

// Default constructor, assigns _movieArray, _tvShowArray, and _musicArray's contents to nullptr.
Database::Database()
{
    _name = "Media Database";
    _db_id = 1;
    _numMovies = 0;
    _numTVShows = 0;
    _numMusicObjects = 0;

    // Loop initializes all values inside of the private arrays to nullptr.
    for (std::size_t i = 0; i < 100; i++)
    {
        _movieArray[i] = nullptr;
        _tvShowArray[i] = nullptr;
        _musicArray[i] = nullptr;
    }
}

// Default deconstructor that *should* clean up everything regardless of location.
Database::~Database()
{
    //
}


void Database::loadData(movieNamespace::MovieClass** movieArrayAddress)
{
    std::cout << "Inside loadData()." << std::endl;

    std::string tempString = "";
    std::size_t numLines = 0;
    std::ifstream is; // Creates the input file stream.

    is.open("movies.csv");
    
    while (is.peek() != EOF) // While not at the end of the file
    {
        getline(is, tempString);
        movieNamespace::MovieClass* tempMovie = new movieNamespace::MovieClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempData[6]; // Holds the 7 private data members.
        std::size_t tempCounter = 0;

        // Loop iterates through tempString and seperates the data off of commas.
        // Then places "cleaned" data into tempData[].
        while(tempString.find(',', startVariable) != std::string::npos)
        {
            endVariable = tempString.find(',', startVariable);
            tempData[tempCounter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
        }

        tempMovie->setMediaIMDBID(tempData[0]);
        tempMovie->setMediaTitle(tempData[1]);
        tempMovie->setMediaYear(tempData[2]);
        tempMovie->setMediaGenre(tempData[3]);
        tempMovie->setRating(tempData[4]);
        tempMovie->setDirector(tempData[5]);

        for (std::size_t i = 0; i < 6; i++)
        {
            std::cout << "tempData[" << i << "]: " << tempData[i] << std::endl;
        }

        // WORKING AS INTENDED TO THIS POINT.
        Database::addMovie(movieArrayAddress, numLines, tempMovie);

        numLines++;
        // Error catching
        if (numLines >= 99)
        {
            std::cout << "Database::loadData() first loop is broken" << std::endl;
            break;
        }
    }
    is.close();
}

// Function takes in the address to the head of _movieList, the desired input position, 
// and a pointer to a movie that you want added.
// Function returns the address to the head of _movieList.
movieNamespace::MovieClass** Database::addMovie(movieNamespace::MovieClass** movieArray, std::size_t position, 
    movieNamespace::MovieClass* movieToBeAdded)
{
    std::cout << "Inside Database::addMovie() function." << std::endl;
    movieArray[(position)]->setMediaIMDBID(movieToBeAdded->getMediaId());
    std::cout << "***DEBUG***" << std::endl;

    movieArray[(position)]->setMediaTitle(movieToBeAdded->getMediaTitle());
    movieArray[(position)]->setMediaYear(movieToBeAdded->getMediaYear());
    movieArray[(position)]->setMediaGenre(movieToBeAdded->getMediaGenre());
    movieArray[(position)]->setRating(movieToBeAdded->getRating());
    movieArray[(position)]->setDirector(movieToBeAdded->getDirector());

    return movieArray;
}

// Calling this function is the equivalent of _numMovies++.
void Database::incrementNumMovies()
{
    std::size_t tempNum = Database::getNumMovies();
    tempNum++;
    Database::setNumMovies(tempNum);
}



// Getters

std::size_t Database::getNumMovies()
{
    return _numMovies;
}

std::size_t Database::getNumTVShows()
{
    return _numTVShows;
}

std::size_t Database::getNumMusicObjects()
{
    return _numMusicObjects;
}

// Function returns the address of the head of _movieArray.
movieNamespace::MovieClass** Database::getMovieArrayAddress()
{
    return _movieArray;
}

// tvShowNamespace::TVShowClass* Database::getTVShowArrayHead()
// {
//     return _tvShowArray[0];
// }

// musicNamespace::MusicClass* Database::getMusicObjectArrayHead()
// {
//     return _musicArray[0];
// }


// Setters

void Database::setNumMovies(std::size_t inputNumMovies)
{
    _numMovies = inputNumMovies;
}

// void Database::setNumTVShows(std::size_t inputNumTVShows)
// {
//     _numTVShows = inputNumTVShows;
// }

// void Database::setNumMusicObjects(std::size_t inputNumMusicObjects)
// {
//     _numMusicObjects = inputNumMusicObjects;
// }

// Function takes the position to input the movie and a pointer to a movie.
void Database::setMovieArray(movieNamespace::MovieClass* inputMovie, std::size_t inputPosition)
{
    _movieArray[inputPosition] = inputMovie;
}