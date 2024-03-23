#include <mediaDatabase.h>

// Default constructor for Database class.
Database::Database()
{
    //
}

Database::~Database()
{
    //
}

void Database::loadData()
{
    /* FROM MOVIE DATABASE
    std::ifstream is;
    is.open("movies.csv");

    // Temp variables to be used for parsing information
    std::string tempString;

    // Loop iterates so long as the cursor is not at the end of the file.
    // Loop populates tempMoveClass with data members from movies.csv.
    while (is.peek() != EOF) // While not at the end of the file
    {
        getline(is, tempString);
        movieNamespace::MovieClass* tempMovieClass = new movieNamespace::MovieClass();

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempData[5]; // Holds the 6 private data members.
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

        tempMovieClass->setIMBDTitleID(tempData[0]);
        tempMovieClass->setMovieTitle(tempData[1]);
        tempMovieClass->setYear(tempData[2]);
        tempMovieClass->setGenre(tempData[3]);
        tempMovieClass->setRating(tempData[4]);
        tempMovieClass->setDirector(tempData[5]);

        Database::setSingleMovieListArray(Database::getObjectCounter(), tempMovieClass);
        Database::objectCounterIterator(); // Equivalent to _objectCounter++;

        // Error catching
        if (tempCounter >= 14)
        {
            std::cout << "Database::loadData() first loop is broken" << std::endl;
            break;
        }
    }
    is.close();
    */

   std::string tempString = "";
   std::ifstream is; // Creates the input file stream.

   is.open("movies.csv");

    while (is.peek() != EOF) // While not at the end of the file
    {
        getline(is, tempString);
        movieNamespace::MovieClass* tempMovieClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempData[5]; // Holds the 6 private data members.
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

        tempMovieClass->setMediaIMDBID(tempData[0]);
        tempMovieClass->setMediaTitle(tempData[1]);
        tempMovieClass->setMediaYear(tempData[2]);
        tempMovieClass->setMediaGenre(tempData[3]);
        tempMovieClass->setRating(tempData[4]);
        tempMovieClass->setDirector(tempData[5]);

        // Database::setSingleMovieListArray(Database::getObjectCounter(), tempMovieClass);
        // Database::objectCounterIterator(); // Equivalent to _objectCounter++;

        // Error catching
        if (tempCounter >= 14)
        {
            std::cout << "Database::loadData() first loop is broken" << std::endl;
            break;
        }
    }
    is.close();

}

movieNamespace::MovieClass* addMovie(std::size_t numMovies, movieNamespace::MovieClass* movieToBeAdded, 
    movieNamespace::MovieClass* headMovieArray)
{
    return headMovieArray;
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


// Setters