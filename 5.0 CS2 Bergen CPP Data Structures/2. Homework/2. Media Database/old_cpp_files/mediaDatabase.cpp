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
    }

    for (std::size_t j = 0; j < 100; j++)
    {
        _tvShowArray[j] = nullptr;
    }

    for (std::size_t k = 0; k < 100; k++)
    {
        _musicArray[k] = nullptr;
    }

}

// Default deconstructor that *should* clean up everything regardless of location.
Database::~Database()
{
    //
}

// Function pulls data from the csv_folder and populates the database's arrays.
// All array locations are instantiatied to nullptr unless there is an object there.
void Database::loadData()
{
    std::cout << "Inside loadData()." << std::endl;

    std::string tempString = "";
    std::size_t numLines = 0; // Used for error catching.
    std::ifstream movieStream; // Creates the input movie file stream.

    movieStream.open("csv_files/movies.csv");
    
    while (movieStream.peek() != EOF) // While not at the end of the file
    {
        getline(movieStream, tempString);
        movieNamespace::MovieClass* tempMovie = new movieNamespace::MovieClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempData[5]; // Holds the 6 private data members.
        std::size_t tempCounter = 0;

        // Loop iterates through tempString and seperates the data off of commas.
        // Then places "cleaned" data into tempData[].
        // ***NEED TO FIX SO THAT LOOP PULLS LAST DATA MEMBER***
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

        // Loop prints out everything inside tempData.
        // for (std::size_t i = 0; i < 6; i++)
        // {
        //     std::cout << "tempData[" << i << "]: " << tempData[i] << std::endl;
        // }

        // Function adds the tempMovie to _musicArray
        addMovie(tempMovie);

        numLines++;
        // Error catching
        if (numLines > 99)
        {
            std::cout << "Database::loadData() movie loop is broken." << std::endl;
            break;
        }
    }
    movieStream.close(); // Movies have been loaded.

    std::ifstream tvStream; // Creates the input TV file stream.
    tempString = "";
    numLines = 0;
    tvStream.open("csv_files/tvshows.csv");

    while (tvStream.peek() != EOF) // While not at the end of the file
    {
        getline(tvStream, tempString);
        tvShowNamespace::TVShowClass* tempShow = new tvShowNamespace::TVShowClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempData[5]; // Holds the 6 private data members.
        std::size_t tempCounter = 0;

        // Loop iterates through tempString and seperates the data off of commas.
        // Then places "cleaned" data into tempData[].
        // ***NEED TO FIX SO THAT LOOP PULLS LAST DATA MEMBER***
        while(tempString.find(',', startVariable) != std::string::npos)
        {
            endVariable = tempString.find(',', startVariable);
            tempData[tempCounter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
        }

        tempShow->setMediaIMDBID(tempData[0]);
        tempShow->setMediaTitle(tempData[1]);
        tempShow->setMediaYear(tempData[2]);
        tempShow->setMediaGenre(tempData[3]);
        tempShow->setRating(tempData[4]);
        tempShow->setNumEpisodes(tempData[5]);

        // Function adds the tempShow to _tvShowArray.
        addTVShow(tempShow);

        numLines++;
        // Error catching
        if (numLines > 99)
        {
            std::cout << "Database::loadData() TV Loop is broken." << std::endl;
            break;
        }
    }
    tvStream.close(); // TV Shows have been loaded.

    std::ifstream musicStream; // Creates the input music file stream.
    tempString = "";
    numLines = 0;
    musicStream.open("csv_files/music.csv");
    while (musicStream.peek() != EOF) // While not at the end of the file
    {
        getline(musicStream, tempString);
        musicNamespace::MusicClass* tempMusic = new musicNamespace::MusicClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempData[6]; // Holds the 7 private data members.
        std::size_t tempCounter = 0;

        // Loop iterates through tempString and seperates the data off of commas.
        // Then places "cleaned" data into tempData[].
        // ***NEED TO FIX SO THAT LOOP PULLS LAST DATA MEMBER***
        while(tempString.find(',', startVariable) != std::string::npos)
        {
            endVariable = tempString.find(',', startVariable);
            tempData[tempCounter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
        }

        tempMusic->setMediaIMDBID(tempData[0]);
        tempMusic->setMediaTitle(tempData[1]);
        tempMusic->setMediaYear(tempData[2]);
        tempMusic->setMediaGenre(tempData[3]);
        tempMusic->setComposer(tempData[4]);
        tempMusic->setNumTracks(tempData[5]);
        tempMusic->setTotalPlaytime(tempData[6]);

        // Function adds tempMusic to _musicArray.
        addMusic(tempMusic);

        numLines++;
        // Error catching
        if (numLines > 99)
        {
            std::cout << "Database::loadData() Music loop is broken." << std::endl;
            break;
        }
    }
    musicStream.close(); // Music has been loaded.
}

// Function takes a pointer to a movie and adds it to the end of _musicArray.
// Function is basically a setter with extra steps.
void Database::addMovie(movieNamespace::MovieClass* inputMovie)
{
    Database::setMovieArray(inputMovie, (Database::getNumMovies() + 1));
    Database::incrementNumMovies();
}

// Calling this function is the equivalent of _numMovies++.
void Database::incrementNumMovies()
{
    std::size_t tempNum = Database::getNumMovies();
    tempNum++;
    Database::setNumMovies(tempNum);
}

void Database::addTVShow(tvShowNamespace::TVShowClass* inputTVShow)
{
    Database::setTVArray(inputTVShow, (Database::getNumTVShows() + 1));
    Database::incrementNumTVShows();
}

void Database::incrementNumTVShows()
{
    std::size_t tempNum = Database::getNumTVShows();
    tempNum++;
    Database::setNumTVShows(tempNum);
}

void Database::addMusic(musicNamespace::MusicClass* inputMusic)
{
    Database::setMusicArray(inputMusic, (Database::getNumMusicObjects() + 1));
    Database::incrementNumMusicObjects();
}

void Database::incrementNumMusicObjects()
{
    std::size_t tempNum = Database::getNumTVShows();
    tempNum++;
    Database::setNumTVShows(tempNum);
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

// Function returns a pointer to _movieArray.
movieNamespace::MovieClass* Database::getMovieArrayAddress()
{
    return *_movieArray;
}

// Overloaded function that returns the address to the requested index.
movieNamespace::MovieClass* Database::getMovieArrayAddress(std::size_t index)
{
    return _movieArray[index];
}

tvShowNamespace::TVShowClass* Database::getTVShowAddress()
{
    return *_tvShowArray;
}

// Overloaded function that returns the address of the input index.
tvShowNamespace::TVShowClass* Database::getTVShowAddress(std::size_t index)
{
    return _tvShowArray[index];
}
       
musicNamespace::MusicClass* Database::getMusicArrayAddress()
{
    return *_musicArray;
}

// Overloaded function that returns the address of the input index.
musicNamespace::MusicClass* Database::getMusicArrayAddress(std::size_t index)
{
    return _musicArray[index];
}


// Setters

void Database::setNumMovies(std::size_t inputNumMovies)
{
    _numMovies = inputNumMovies;
}

void Database::setNumTVShows(std::size_t inputNumTVShows)
{
    _numTVShows = inputNumTVShows;
}

void Database::setNumMusicObjects(std::size_t inputNumMusicObjects)
{
    _numMusicObjects = inputNumMusicObjects;
}

// Function takes a pointer to a movie and what index you want to place it in.
void Database::setMovieArray(movieNamespace::MovieClass* inputMovie, std::size_t inputPosition)
{
    _movieArray[inputPosition] = inputMovie;
}

// Function takes a pointer to a TV Show and what index you want to place it in.
void Database::setTVArray(tvShowNamespace::TVShowClass* inputTVShow, std::size_t inputPosition)
{
    _tvShowArray[inputPosition] = inputTVShow;
}

// Function takes a pointer to a Music Object and what index you want to place it in.
void Database::setMusicArray(musicNamespace::MusicClass* inputMusicObject, std::size_t inputPosition)
{
    _musicArray[inputPosition] = inputMusicObject;
}