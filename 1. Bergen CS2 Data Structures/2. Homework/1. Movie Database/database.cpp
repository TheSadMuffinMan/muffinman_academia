#include "database.h"

// Default constructor
Database::Database()
{
    // Cell* newCell = new Cell
    movieNamespace::MovieClass* newObject = new movieNamespace::MovieClass;
    newObject->setMovieTitle(nullptr);
}

// Deconstructor
Database::~Database()
{
    std::cout << "Hey, you're inside ~Database() deconstructor." << std::endl;
}

// Main methods

// Function initializes each movieClass to NULLPTR.
// Creates an input stream.
// Reads data from movies.cpp.
// Breaks data apart.
// Assigns data to new class, iterates counter.
// Updates _movieListArray[] and returns the array.
void Database::loadData()
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
std::size_t Database::objectCounterIterator(std::size_t&)
{
    //
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

std::size_t Database::getMovieListSize()
{
    return _movieListSize;
}

// Function returns the entire _movieListArray[]
movieNamespace::MovieClass* Database::getMovieListArray()
{
    std::size_t tempSize = 0;
    tempSize = Database::getMovieListSize();
    return _movieListArray[tempSize];
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

// Method sets a pointer to a single MovieClass inside *movieListArray[]
void Database::setSingleMovieInArrayList(movieNamespace::MovieClass* movieListArray[], movieNamespace::MovieClass* inputMovieClassPointer)
{
    std::size_t arraySize;
    arraySize = getMovieListSize();

    _movieListArray[arraySize] = inputMovieClassPointer;
}