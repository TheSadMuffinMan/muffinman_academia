#include "database.h"
#include "movie.h"

// Default constructor, creates a default database class.
Database::Database()
{
    setName("NULL");
    setDb_id(0);
    setObjectCounter(0);

    for (std::size_t i = 0; i < 20; i++)
    {
        Database::setSingleMovieListArray(i, nullptr);
    }

    // std::cout << "Database(size_t) Constructor used." << std::endl;
}

// Non-default constructor class.
Database::Database(std::size_t dataBaseArraySize, std::string inputName, int inputDb_id)
{
    _name = inputName;
    _db_id = inputDb_id;
    _objectCounter = 0;

    for (std::size_t i = 0; i < dataBaseArraySize; i++)
    {
        Database::setSingleMovieListArray(i, nullptr);
    }

    // std::cout << "Non-default Database constructor class used." << std::endl;
}

// Deconstructor
Database::~Database()
{
    // std::cout << "~Database() deconstructor used." << std::endl;
}

// Getters
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

// Method sets a pointer to a single MovieClass inside movieListArray[].
void Database::setSingleMovieListArray(std::size_t desiredArrayPosition, movieNamespace::MovieClass* inputMovieClass)
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
}

void Database::displaySingleMovie(movieNamespace::MovieClass* inputMovie)
{
    std::cout << "Movie: " << inputMovie->getMovieTitle() << std::endl;
}

// Displays all movie objects inside movieListArray
void Database::displayAllData()
{
    std::cout << "Inside Database::displayAllMovies." << std::endl;

    for (std::size_t i = 0; i < Database::getObjectCounter(); i++)
    {
        movieNamespace::MovieClass* tempMovie = Database::getMovieListArrayAtPosition(i);
        std::cout << "i: " << i << std::endl;
        std::cout << "IMBD Title ID: " << tempMovie->getIMBDTitleID() << std::endl;
        std::cout << "Movie Title: " << tempMovie->getMovieTitle() << std::endl;
        std::cout << "Release Year: " << tempMovie->getYear() << std::endl;
        std::cout << "Genre: " << tempMovie->getGenre() << std::endl;
        std::cout << "Rating: " << tempMovie->getRating() << std::endl;
        std::cout << "Director: " << tempMovie->getDirector() << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }
}

// Asks for user input/data.
// Assigns user input to a new MovieClass.
// Creates a second Database with one additional spot in _movieListArray[].
void Database::addMovie()
{
    // Temp data members to hold input.
    std::string inputMovieIMBDTitle, inputMovieTitle, inputMovieYear, inputMovieGenre, inputMovieRating, inputMovieDirector;

    std::cout << "\n***MUST INPUT VALUES FOR EACH OR ELSE SHIT WILL BREAK***\n" << std::endl;

    std::cout << "Input IMBD Title: ";
    getline(std::cin, inputMovieIMBDTitle);

    std::cout << "Input Movie Title: ";
    // std::cin.ignore();
    getline(std::cin, inputMovieTitle);

    std::cout << "Input Year: ";
    getline(std::cin, inputMovieYear);
    // Converts input to an int.
    int cleanInputMovieYear;
    std::istringstream(inputMovieYear) >> cleanInputMovieYear;

    std::cout << "Input Genre: ";
    // std::cin.ignore();
    getline(std::cin, inputMovieGenre);

    std::cout << "Input Rating: ";
    getline(std::cin, inputMovieRating);
    // Converts to a float.
    float cleanInputMovieRating;
    std::istringstream(inputMovieRating) >> cleanInputMovieRating;

    std::cout << "Input Director: ";
    // std::cin.ignore();
    getline(std::cin, inputMovieDirector);

    // Populates a new movieClass.
    movieNamespace::MovieClass* newMovie = new movieNamespace::MovieClass;
    objectCounterIterator(); // Same as _objectCounter++, working.
    newMovie->setIMBDTitleID(inputMovieIMBDTitle);
    newMovie->setMovieTitle(inputMovieTitle);
    newMovie->setYear(cleanInputMovieYear);
    newMovie->setGenre(inputMovieGenre);
    newMovie->setRating(cleanInputMovieRating);
    newMovie->setDirector(inputMovieDirector);

    // Updates _movieListArray[].
    // Not sure why it has a -1 error but w/e lol.
    Database::setSingleMovieListArray((Database::getObjectCounter() - 1), newMovie);
}

// Removes a movie
void Database::removeMovie()
{
    std::cout << "Inside Database::removeMovie()." << std::endl;

    std::size_t deletionPosition = -1;
    std::cout << "Input which movie you would like to delete: ";
    std::cin >> deletionPosition;

    Database::setSingleMovieListArray(deletionPosition, nullptr);

    std::size_t tempCounter = deletionPosition;
    movieNamespace::MovieClass* tempMovie = new movieNamespace::MovieClass;
    while (Database::getMovieListArrayAtPosition(tempCounter + 1) != nullptr)
    {
        tempMovie = Database::getMovieListArrayAtPosition((tempCounter) + 1);
        Database::setSingleMovieListArray(tempCounter, tempMovie);
        tempCounter++;
    }
}

// Searches for movies or genres
void Database::searchFunction()
{
    std::cout << "Inside Database::searchFunction()." << std::endl;
}

// Iterates private data member _objectCounter
void Database::objectCounterIterator()
{
    std::size_t tempObjectCounter = Database::getObjectCounter();
    tempObjectCounter++;
    Database::setObjectCounter(tempObjectCounter);
}