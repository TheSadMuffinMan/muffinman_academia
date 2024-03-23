#include "mediaDatabase.h"

// Default constructor for Database class.
Database::Database()
{
    _name = "Media Database";
    _db_id = 1;
    _numMovies = 0;
    _numTVShows = 0;
    _numMusicObjects = 0;
}

Database::~Database()
{
    //
}

void Database::loadData()
{
   std::string tempString = "";
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

        Database::addMovie((Database::getNumMovies()), Database::getMovieArrayHead(), tempMovie);

        // Database::setSingleMovieListArray(Database::getObjectCounter(), tempMovieClass);
        // Database::objectCounterIterator(); // Equivalent to _objectCounter++;

        // Error catching
        if (tempCounter >= 99)
        {
            std::cout << "Database::loadData() first loop is broken" << std::endl;
            break;
        }
    }
    is.close();

}

// Function takes in numMovies, the address to the head of _movieList, and a pointer to a movie.
// Function increments _numMovies.
// The function adds a movie to the end of the data inside _movieList.
// Function returns the address to the head of _movieList.
movieNamespace::MovieClass* Database::addMovie(std::size_t numMovies, movieNamespace::MovieClass* headMovieArray, 
    movieNamespace::MovieClass* movieToBeAdded)
{
    Database::incrementNumMovies(); // Increments _numMovies.
    numMovies++; // Increments the local numMovies.

    headMovieArray[(numMovies)].setMediaIMDBID(movieToBeAdded->getMediaId());
    headMovieArray[(numMovies)].setMediaTitle(movieToBeAdded->getMediaTitle());
    headMovieArray[(numMovies)].setMediaYear(movieToBeAdded->getMediaYear());
    headMovieArray[(numMovies)].setMediaGenre(movieToBeAdded->getMediaGenre());
    headMovieArray[(numMovies)].setRating(movieToBeAdded->getRating());
    headMovieArray[(numMovies)].setDirector(movieToBeAdded->getDirector());

    return headMovieArray;
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

movieNamespace::MovieClass* Database::getMovieArrayHead()
{
    return _movieArray[0];
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
void Database::setMovieArray(std::size_t inputPosition, movieNamespace::MovieClass* inputMovie)
{
    _movieArray[inputPosition] = inputMovie;
}