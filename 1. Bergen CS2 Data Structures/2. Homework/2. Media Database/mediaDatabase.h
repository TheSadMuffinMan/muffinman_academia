#pragma once

#include <string>
#include <iomanip>
#include <fstream>

#include "media.h"
#include "movie.h"
#include "tvshows.h"
#include "music.h"

class Database
{
    public:

        // Default constructors and destructors

        Database(); // Complete.
        ~Database(); // Complete.

        void loadData(); // Complete.

        void addMovie(movieNamespace::MovieClass*); // Complete.
        void addTVShow(tvShowNamespace::TVShowClass*);
        void addMusic(musicNamespace::MusicClass*);

        void incrementNumMovies(); // Complete.
        void incrementNumTVShows();
        void incrementNumMusicObjects();


        void displayAllMedia(); // Complete.
        void displaySingleMovie(std::size_t);
        void displaySingleTVShow(std::size_t);
        void displaySingleMusic(std::size_t);


        // Remove single movie.
        movieNamespace::MovieClass* removeMovie(std::size_t);

        // Remove single TV show.
        // Remove single Music.

        // Output all data to CSV.

        // Search for media.

        // Getters

        std::size_t getNumMovies();
        std::size_t getNumTVShows();
        std::size_t getNumMusicObjects();

        // movieNamespace::MovieClass* getMovieArrayAddress(); // Never need access to the "full" array.
        movieNamespace::MovieClass* getMovieArrayAddress(std::size_t);
        tvShowNamespace::TVShowClass* getTVShowAddress(std::size_t);
        musicNamespace::MusicClass* getMusicArrayAddress(std::size_t);

        // Setters

        void setNumMovies(std::size_t);
        void setNumTVShows(std::size_t);
        void setNumMusicObjects(std::size_t);

        void setMovieArray(movieNamespace::MovieClass*, std::size_t);
        void setTVArray(tvShowNamespace::TVShowClass*, std::size_t);
        void setMusicArray(musicNamespace::MusicClass*, std::size_t);

    private:
        std::string _name; // More or less garbage variable.
        int _db_id; // See above.

        std::size_t _numMovies;
        std::size_t _numTVShows;
        std::size_t _numMusicObjects;

        movieNamespace::MovieClass* _movieArray[100];
        tvShowNamespace::TVShowClass* _tvShowArray[100];
        musicNamespace::MusicClass* _musicArray[100];
};


// Default constructor, assigns all of _movieArray's, _tvShowArray's, and _musicArray's contents to nullptr.
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

// Default deconstructor that ***I think*** cleans up everything regardless of location.
Database::~Database()
{
    for (std::size_t i = 0; i < 100; i++)
    {
        _movieArray[i] = nullptr;
    }

    for (std::size_t i = 0; i < 100; i++)
    {
        _tvShowArray[i] = nullptr;
    }

    for (std::size_t i = 0; i < 100; i++)
    {
        _musicArray[i] = nullptr;
    }

    std::cout << "Memory has been cleaned up." << std::endl;
}

// Function pulls data from the csv_folder and populates the database's arrays.
void Database::loadData()
{
    // std::cout << "Inside loadData()." << std::endl;

    std::string tempString = "";
    std::ifstream movieStream; // Creates the input movie file stream.

    movieStream.open("csv_files/movies.csv");
    
    while (movieStream.peek() != EOF) // While not at the end of the file
    {
        getline(movieStream, tempString);
        movieNamespace::MovieClass* tempMovie = new movieNamespace::MovieClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempMovieData[6]; // Holds the 6 private data members.
        std::size_t tempCounter = 0;

        // Loop iterates through tempString and seperates the data off of commas.
        // Then places "cleaned" data into tempData[].
        while(tempString.find(',', startVariable) != std::string::npos)
        {
            endVariable = tempString.find(',', startVariable);
            tempMovieData[tempCounter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
        }
        tempMovieData[tempCounter] = tempString.substr(startVariable, (tempString.size() - startVariable));

        tempMovie->setMediaIMDBID(tempMovieData[0]);
        tempMovie->setMediaTitle(tempMovieData[1]);
        tempMovie->setMediaYear(tempMovieData[2]);
        tempMovie->setMediaGenre(tempMovieData[3]);
        tempMovie->setRating(tempMovieData[4]);
        tempMovie->setDirector(tempMovieData[5]);

        // Loop prints out everything inside tempMovieData.
        // for (std::size_t i = 0; i < 6; i++)
        // {
        //     std::cout << "tempMovieData[" << i << "]: " << tempMovieData[i] << std::endl;
        // }

        // Function adds the tempMovie to _movieArray.
        addMovie(tempMovie);
    }
    movieStream.close(); // Movies have been loaded.

    std::ifstream tvStream; // Creates the input TV file stream.
    tempString = "";
    tvStream.open("csv_files/tvshows.csv");

    while (tvStream.peek() != EOF) // While not at the end of the file
    {
        getline(tvStream, tempString);
        tvShowNamespace::TVShowClass* tempShow = new tvShowNamespace::TVShowClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempTVData[6]; // Holds the 6 private data members.
        std::size_t tempCounter = 0;

        while(tempString.find(',', startVariable) != std::string::npos)
        {
            endVariable = tempString.find(',', startVariable);
            tempTVData[tempCounter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
        }
        tempTVData[tempCounter] = tempString.substr(startVariable, (tempString.size() - startVariable));

        tempShow->setMediaIMDBID(tempTVData[0]);
        tempShow->setMediaTitle(tempTVData[1]);
        tempShow->setMediaYear(tempTVData[2]);
        tempShow->setMediaGenre(tempTVData[3]);
        tempShow->setRating(tempTVData[4]);
        tempShow->setNumEpisodes(tempTVData[5]);

        // Function adds the tempShow to _tvShowArray.
        addTVShow(tempShow);
    }
    tvStream.close(); // TV Shows have been loaded.

    std::ifstream musicStream; // Creates the input music file stream.
    tempString = "";
    musicStream.open("csv_files/music.csv");
    while (musicStream.peek() != EOF) // While not at the end of the file
    {
        getline(musicStream, tempString);
        musicNamespace::MusicClass* tempMusic = new musicNamespace::MusicClass;

        // Temporary loop variables.
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempMusicData[7]; // Holds the 7 private data members.
        std::size_t tempCounter = 0;

        while(tempString.find(',', startVariable) != std::string::npos)
        {
            endVariable = tempString.find(',', startVariable);
            tempMusicData[tempCounter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
        }
        tempMusicData[tempCounter] = tempString.substr(startVariable, (tempString.size() - startVariable));

        tempMusic->setMediaIMDBID(tempMusicData[0]);
        tempMusic->setMediaTitle(tempMusicData[1]);
        tempMusic->setMediaYear(tempMusicData[2]);
        tempMusic->setMediaGenre(tempMusicData[3]);
        tempMusic->setComposer(tempMusicData[4]);
        tempMusic->setNumTracks(tempMusicData[5]);
        tempMusic->setTotalPlaytime(tempMusicData[6]);

        // Function adds tempMusic to _musicArray.
        addMusic(tempMusic);
    }
    musicStream.close(); // Music has been loaded.

    std::cout << "All data loaded." << std::endl;
}

// Function takes a pointer to a movie and adds it to the end of _musicArray.
// Function is basically a setter with extra steps.
void Database::addMovie(movieNamespace::MovieClass* inputMovie)
{
    Database::setMovieArray(inputMovie, (Database::getNumMovies() + 1));
    Database::incrementNumMovies();
}

void Database::addTVShow(tvShowNamespace::TVShowClass* inputTVShow)
{
    Database::setTVArray(inputTVShow, (Database::getNumTVShows() + 1));
    Database::incrementNumTVShows();
}

void Database::addMusic(musicNamespace::MusicClass* inputMusic)
{
    Database::setMusicArray(inputMusic, (Database::getNumMusicObjects() + 1));
    Database::incrementNumMusicObjects();
}


// Calling this function is the equivalent of _numMovies++.
void Database::incrementNumMovies()
{
    std::size_t tempNum = Database::getNumMovies();
    tempNum++;
    Database::setNumMovies(tempNum);
}

void Database::incrementNumTVShows()
{
    std::size_t tempNum = Database::getNumTVShows();
    tempNum++;
    Database::setNumTVShows(tempNum);
}

void Database::incrementNumMusicObjects()
{
    std::size_t tempNum = Database::getNumMusicObjects();
    tempNum++;
    Database::setNumMusicObjects(tempNum);
}


// Function either displays all media and correlated data, or only displays media titles.
void Database::displayAllMedia()
{
    std::cout << "Inside Database::displayAllMedia()." << std::endl;

    std::size_t navigationChoice = 0;
    std::cout << "Input 1 to display all info, input 2 to display only media titles. ";
    std::cin >> navigationChoice;


    if (navigationChoice == 1)
    {
        std::cout << "Printing out all data... :D" << std::endl;

        std::cout << "-----MOVIES-----" << std::endl;
        for (std::size_t i = 1; i <= Database::getNumMovies(); i++) // *****HELP***** ASK MR. BERGEN ABOUT THIS LINE.
        {
            std::cout << i << ". ";
            Database::getMovieArrayAddress(i)->displayInfo();

            std::cout << std::endl;
        }

        std::cout << "-----TV SHOWS-----" << std::endl;
        for (std::size_t i = 1; i <= Database::getNumTVShows(); i++)
        {
            std::cout << i << ". ";
            Database::getTVShowAddress(i)->displayInfo();
            std::cout << std::endl;
        }

        std::cout << "-----MUSIC-----" << std::endl;
        for (std::size_t i = 1; i <= Database::getNumMusicObjects(); i++)
        {
            std::cout << i << ". ";
            Database::getMusicArrayAddress(i)->displayInfo();
            std::cout << std::endl;
        }
    }
    else if (navigationChoice == 2)
    {
        std::cout << "Printing out media titles... :D" << std::endl;

        std::cout << "\n-----MOVIES-----" << std::endl;
        for (std::size_t i = 1; i <= Database::getNumMovies(); i++)
        {
            std::cout << i << ". ";
            std::cout << Database::getMovieArrayAddress(i)->getMediaTitle() << std::endl;
        }

        std::cout << "\n-----TV SHOWS-----" << std::endl;
        for (std::size_t i = 1; i <= Database::getNumTVShows(); i++)
        {
            std::cout << i << ". ";
            std::cout << Database::getTVShowAddress(i)->getMediaTitle() << std::endl;
        }

        std::cout << "\n-----MUSIC-----" << std::endl;
        for (std::size_t i = 1; i <= Database::getNumMusicObjects(); i++)
        {
            std::cout << i << ". ";
            std::cout << Database::getMusicArrayAddress(i)->getMediaTitle() << std::endl;
        }
    }
    else
    {
        std::cout << "Uh oh, something broke." << std::endl;
    }
}

// Function displays all movie information at requested index.
void Database::displaySingleMovie(std::size_t index)
{
    Database::getMovieArrayAddress(index)->displayInfo();
}

// Function displays all TV Show information at requested index.
void Database::displaySingleTVShow(std::size_t index)
{
    Database::getTVShowAddress(index)->displayInfo();
}

// Function displays all Music information at requested index.
void Database::displaySingleMusic(std::size_t index)
{
    Database::getMusicArrayAddress(index)->displayInfo();
}


// Function takes in which index you would like to delete.
// Function updates _movieArray and returns the updated address to _movieArray.
movieNamespace::MovieClass* Database::removeMovie(std::size_t index)
{
    // Sets the index position = nullptr.
    Database::setMovieArray(nullptr, index);

    // Loop starts at index and checks if the next object in _movieArray is nullptr.
    for (std::size_t i = index; i <= Database::getNumMovies(); i++)
    {
        movieNamespace::MovieClass* tempMovie = new movieNamespace::MovieClass;

        // If the next "member" is nullptr, break out of the loop.
        if ((Database::getMovieArrayAddress(i + 1)) == nullptr)
        {
            break;
        }

        tempMovie = Database::getMovieArrayAddress(i + 1);

        Database::setMovieArray(tempMovie, i);
    }

    // WORKING.
    // Decrements _numMovies.
    std::size_t tempNumMovies = (Database::getNumMovies() - 1);
    Database::setNumMovies(tempNumMovies);

    std::cout << "Movie has been removed." << std::endl;
    return Database::getMovieArrayAddress(0);
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
// movieNamespace::MovieClass* Database::getMovieArrayAddress()
// {
//     return *_movieArray;
// }

// Function returns the address to the requested index.
movieNamespace::MovieClass* Database::getMovieArrayAddress(std::size_t index)
{
    return _movieArray[index];
}

// tvShowNamespace::TVShowClass* Database::getTVShowAddress()
// {
//     return *_tvShowArray;
// }

// Function returns the address of the input index.
tvShowNamespace::TVShowClass* Database::getTVShowAddress(std::size_t index)
{
    return _tvShowArray[index];
}
       
// musicNamespace::MusicClass* Database::getMusicArrayAddress()
// {
//     return *_musicArray;
// }

// Function returns the address of the input index.
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