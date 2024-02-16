#include "database.h"

// Default constructor
Database::Database()
{
    // Cell* newCell = new Cell
    movieNamespace::MovieClass* newObject = new movieNamespace::MovieClass;
    newObject->setMovieTitle(nullptr);
}

Database::~Database()
{
    // Deconstructor
}

// Main methods
void Database::loadData()
{
    // Loads the data
}

void Database::displayAllMovies()
{
    // Displays all movie objects inside movieListArray
}

void Database::addMovie()
{
    // Adds a movie
}

void Database::removeMovie()
{
    // Removies a movie
}

void Database::searchFunction()
{
    // Searches for movies or genres
}

std::size_t Database::objectCounterIterator(std::size_t&)
{
    // Iterates private data member _objectCounter
}

// Getters
std::string* Database::getName()
{
    return _name;
}

int* Database::getDb_id()
{
    return _db_id;
}

// ***Is NOT a pointer***
std::size_t Database::getObjectCounter()
{
    return _objectCounter;
}

// Setters
void Database::setName(std::string* userInput)
{
    _name = userInput;
}

void Database::setDb_id(int* userInput)
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

void setMovieArrayList(movieNamespace::MovieClass movieListArray[], std::size_t movieListSize, movieNamespace::MovieClass inputMovieClass)
{
    // Method sets a pointer to a MovieClass inside movieListArray[]
}