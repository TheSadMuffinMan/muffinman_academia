#include "database.h"
#include "movie.h"

// Default constructor, creates a default database class.
Database::Database()
{
    setName("NULL");
    setDb_id(0);
    setObjectCounter(0);

    std::cout << "Database(size_t) Constructor used." << std::endl;
}

// Non-default constructor class.
Database::Database(std::size_t dataBaseArraySize, std::string inputName, int inputDb_id)
{
    _name = inputName;
    _db_id = inputDb_id;
    _objectCounter = 0;

    // std::cout << "Non-default Database constructor class used." << std::endl;
}

// Deconstructor
Database::~Database()
{
    std::cout << "~Database() deconstructor used." << std::endl;
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

// Method sets a pointer to a single MovieClass inside movieListArray[]
void Database::setMovieListArray(movieNamespace::MovieClass* inputMovieClass, std::size_t desiredArrayPosition)
{
    _movieListArray[desiredArrayPosition] = inputMovieClass;
}


// Main methods

// Creates an input stream.
// Reads data from movies.cpp.
// Breaks data apart.
// Assigns data to new class, iterates counter.
// Updates _movieListArray[].
void Database::loadData()
{
    std::cout << "Inside Database::loadData()." << std::endl;

    std::ifstream is;
    is.open("movies.csv");

    // Temp variables to be used for parsing information
    std::string tempString;
    movieNamespace::MovieClass* tempMovieClass = new movieNamespace::MovieClass();

    // Loop iterates so long as the cursor is not at the end of the file
    while (is.peek() != EOF) // While not at the end of the file
    {
        getline(is, tempString);
        // std::cout << "tempString: " << tempString << std::endl;
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempData[6];
        std::size_t tempCounter = 0;

        // Loop iterates through tempString and seperates the data off of commas
        // Then places "cleaned" data into tempData[6]
        while(tempString.find(',', startVariable) != std::string::npos)
        {
            endVariable = tempString.find(',', startVariable);
            tempData[tempCounter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
        }


    }

    is.close();
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

// Removes a movie
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