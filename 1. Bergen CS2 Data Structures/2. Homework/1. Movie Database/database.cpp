#include "database.h"
#include "movie.h"

// Default constructor, initializes values to 0.
Database::Database(std::size_t dataBaseSize)
{
    std::cout << "Default Database Constructor utilized." << std::endl;
    _name = "NULL";
    _db_id = 0;
    _objectCounter = 0;
    _movieListSize = 0;
    _movieListArray[dataBaseSize];

    for (std::size_t i = 0; i < dataBaseSize; i++)
    {
        movieNamespace::MovieClass* tempMovie = new movieNamespace::MovieClass;
        _movieListArray[i] = tempMovie;
    }
}

// Deconstructor
Database::~Database()
{
    std::cout << "Hey, you're inside ~Database() deconstructor." << std::endl;
}

void Database::databaseCleanup(std::size_t dataBaseSize)
{
    for (std::size_t i = 0; i < dataBaseSize; i++)
    {
        delete _movieListArray[i];
    }

    std::cout << "Database memory on the heap has been cleaned (I hope)." << std::endl;
}

// Main methods

// Function initializes each movieClass to nullptr.
// Creates an input stream.
// Reads data from movies.cpp.
// Breaks data apart.
// Assigns data to new class, iterates counter.
// Updates _movieListArray[] and returns the array.
void Database::loadData(std::size_t dataBaseSize)
{
    std::cout << "Inside Database::loadData()." << std::endl;
}

// Displays all movie objects inside movieListArray
void Database::displayAllMovies()
{
    std::cout << "Inside Database::displayAllMovies." << std::endl;
}

// Instantiates a new MovieClass.
// Asks for user input/data.
// Assigns user input to the new MovieClass.
// Appends new pointer to MovieClass inside _movieListArray[].
void Database::addMovie()
{
    std::cout << "Inside Database::addMovie()." << std::endl;
}

// Removies a movie
void Database::removeMovie()
{
    std::cout << "Inside Database::removieMovie()." << std::endl;    
}

// Searches for movies or genres
void Database::searchFunction()
{
    std::cout << "Inside Database::searchFunction()." << std::endl;
}

// Iterates private data member _objectCounter
void Database::objectCounterIterator()
{
    std::cout << "Inside Database::objectCounterIterator." << std::endl;
    std::size_t tempObjectCounter = 0;
    tempObjectCounter = Database::getObjectCounter();
    tempObjectCounter++;
    Database::setObjectCounter(tempObjectCounter);
    std::cout << "_objectCounter: " << Database::getObjectCounter() << std::endl;
}

// Getters
std::string Database::getName()
{
    return _name;
}

int Database::getDb_id()
{
    return _db_id;
}

std::size_t Database::getObjectCounter()
{
    return _objectCounter;
}

std::size_t Database::getMovieListSize()
{
    return _movieListSize;
}

// Function returns a pointer to _movieListArray[inputPosition].
movieNamespace::MovieClass* Database::getMovieListArrayAtPosition(std::size_t inputPosition)
{
    return _movieListArray[inputPosition];
}

// Setters
void Database::setName(std::string userInput)
{
    _name = userInput;
}

void Database::setDb_id(int userInput)
{
    _db_id = userInput;
}

void Database::setObjectCounter(std::size_t userInput)
{
    _objectCounter = userInput;
}

void Database::setMovieListSize(std::size_t userInput)
{
    _movieListSize = userInput;
}

// Method sets a pointer to a single MovieClass inside movieListArray[]
void Database::setMovieListArray(movieNamespace::MovieClass* inputMovieClass, std::size_t desiredArrayPosition)
{
    _movieListArray[desiredArrayPosition] = inputMovieClass;
}