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
    std::cout << "***DEBUG*** Data has been loaded." << std::endl;
}

void Database::displaySingleMovie(movieNamespace::MovieClass* inputMovie)
{
    std::cout << inputMovie->getMovieTitle();
}

// Function prints out all Movie titles inside the database.
void Database::displayAllMovieTitles()
{
    std::cout << std::endl;
    for (std::size_t i = 0; i < (Database::getObjectCounter()); i++)
    {
        std::cout << (i + 1) << ": ";
        Database::displaySingleMovie(Database::getMovieListArrayAtPosition(i));
        std::cout << std::endl;
    }
}

// Displays all movie objects inside movieListArray
void Database::displayAllData()
{
    std::cout << "Inside Database::displayAllMovies." << std::endl;

    for (std::size_t i = 0; i < Database::getObjectCounter(); i++)
    {
        movieNamespace::MovieClass* tempMovie = Database::getMovieListArrayAtPosition(i);
        std::cout << "\ni: " << i << std::endl;
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
// Returns a pointer to an array of pointers to movies (movieNameSpace::MovieClass*).
movieNamespace::MovieClass** Database::searchFunction()
{
    std::cout << "Inside Database::searchFunction()." << std::endl;

    // Declares array that will hold the data we're searching for.
    movieNamespace::MovieClass** tempArray;
    tempArray = new movieNamespace::MovieClass* [20];

    // Initializes each data member to nullptr.
    for (std::size_t i = 0; i < 20; i++)
    {
        tempArray[i] = nullptr;
    }

    // Ask for genre or IMBD title
    std::size_t searchType = 0; // 0 = null | 1 = Genre | 2 = Title
    std::cout << "Searching by genre or movie title?\t1. GENRE\t2. MOVIE TITLE" << std::endl;
    std::cin >> searchType;

    if (searchType == 1) // Genre search loop
    {
        std::cout << "Inside Genre Search Loop." << std::endl;

        // Stores any pointers to movieClasses with input Genre.
        std::size_t positionCounter = 0;
        std::string inputGenre;
        std::cout << "Options are:\tAdventure\tAction\tAnimation\tComedy" << std::endl;
        std::cout << "Please input what type of genre you would like (INPUT EXACT): ";
        std::cin >> inputGenre;

        // Loop searches each _movieListArray[] position and will put the compared data into tempArray[].
        for (std::size_t i = 0; i < 20; i++)
        {
            std::string tempGenre; // String to hold data that will be compared to.
            movieNamespace::MovieClass* tempMovie = Database::getMovieListArrayAtPosition(i); // TempMovie to hold data.
            if (tempMovie == nullptr)
            {
                break;
            }
            
            tempGenre = tempMovie->getGenre();

            if ((inputGenre == "Adventure") && (tempGenre == "Adventure"))
            {
                tempArray[positionCounter] = tempMovie;
                positionCounter++;
            } else if ((inputGenre == "Action") && (tempGenre == "Action"))
            {
                tempArray[positionCounter] = tempMovie;
                positionCounter++;
            } else if ((inputGenre == "Animation") && (tempGenre == "Animation"))
            {
                tempArray[positionCounter] = tempMovie;
                positionCounter++;
            } else if ((inputGenre == "Comedy") && (tempGenre == "Comedy"))
            {
                tempArray[positionCounter] = tempMovie;
                positionCounter++;
            }
        }
    } else if (searchType == 2) // Movie title search loop
    {
        std::cout << "Inside IMBD Title Search loop." << std::endl;

        std::string inputIMBDTitle;
        std::cout << "Please input IMBD Title (INPUT EXACT): ";
        std::cin >> inputIMBDTitle;

        for (std::size_t i = 0; i < 20; i++)
        {
            std::string tempIMBDTitle = ""; // String to hold IMBD title that will be compared to.
            movieNamespace::MovieClass* tempMovie = Database::getMovieListArrayAtPosition(i); // TempMovie to hold data.
            if (tempMovie == nullptr)
            {
                break;
            }

            tempIMBDTitle = tempMovie->getIMBDTitleID();

            if (tempIMBDTitle == inputIMBDTitle)
            {
                tempArray[0] = tempMovie;
                tempArray[1] = nullptr;
                break;
            }
        }
    } else
    {
        std::cout << "Yer input broke somethin >:(" << std::endl;
    }

    // movieNamespace::MovieClass* tempMovie = tempArray[0];
    std::string tempPrintString = tempArray[0]->getMovieTitle();
    std::cout << "tempArray[0]: " << tempPrintString << std::endl;

    // Return array once loop is complete.
    return tempArray;
}

void Database::outputToCSV(movieNamespace::MovieClass* inputArray[])
{
    // Function loops through the passed array and pushes it to a .csv.
    std::cout << "Inside Database::outputToCSV() function." << std::endl;

    std::ofstream outputStream;
    outputStream.open("outputFile.csv");

    // outputStream << "Testing"; // Puts "Testing" in the first line of the csv file.

    // Temporary variables.
    movieNamespace::MovieClass* tempMovie;
    std::string tempString;
    int tempInt = 0;
    float tempFloat = 0.0;

    // Loop outputs all data to outputFile, formatted for a csv.
    for (std::size_t i = 0; i < 20; i++)
    {        
        tempMovie = inputArray[i];

        if (tempMovie == nullptr)
        {
            break;
        }

        tempString = inputArray[i]->getIMBDTitleID();
        std::cout << "tempIMBDID: " << tempString << std::endl;
        outputStream << tempString << ",";

        tempString = inputArray[i]->getMovieTitle();
        std::cout << "tempTitle: " << tempString << std::endl;
        outputStream << tempString << ",";

        tempInt = inputArray[i]->getYear();
        std::cout << "tempYear: " << tempInt << std::endl;
        outputStream << tempInt << ",";

        tempString = inputArray[i]->getGenre();
        std::cout << "tempGenre: " << tempString << std::endl;
        outputStream << tempString << ",";

        tempFloat = inputArray[i]->getRating();
        std::cout << "tempRating: " << tempFloat << std::endl;
        outputStream << tempString << ",";

        tempString = inputArray[i]->getDirector();
        std::cout << "tempDirector: " << tempString << std::endl;
        outputStream << tempString << ",";

        outputStream << "\n";
    }

    outputStream.close();
}


// Iterates private data member _objectCounter
void Database::objectCounterIterator()
{
    std::size_t tempObjectCounter = Database::getObjectCounter();
    tempObjectCounter++;
    Database::setObjectCounter(tempObjectCounter);
}