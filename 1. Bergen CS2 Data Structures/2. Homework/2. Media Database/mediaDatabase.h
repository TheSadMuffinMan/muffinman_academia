// MAJOR GOOF: all data arrays start at 1, not 0. Too much work to go back and fix.
// (All arrays have nullptr at 0 index).
// WORKING ON PRIVATE DATA MEMBERS
#pragma once

#include <iomanip>
#include <string>
#include <fstream>

#include "media.h"
#include "movie.h"
#include "tvshows.h"
#include "music.h"

class Database
{
    public:
        Database(); // Complete.
        ~Database(); // Complete.

        void loadData(); // Complete.

        void addMovie();
        void addTVShow();
        void addMusic();

        void incrementNumMovies(); // All complete.
        void incrementNumTVShows();
        void incrementNumMusicObjects();

        void displayAllMedia(); // All complete.
        void displaySingleMovie(std::size_t);
        void displaySingleTVShow(std::size_t);
        void displaySingleMusic(std::size_t);

        movieNamespace::MovieClass* removeMovie(std::size_t); // All complete.
        tvShowNamespace::TVShowClass* removeTVShow(std::size_t);
        musicNamespace::MusicClass* removeMusic(std::size_t);

        void outputDatatoCSV(); // Complete.

        // 99% sure these are leaking memory, but the malloc error makes me think otherise?
        movieNamespace::MovieClass** searchMovie(std::string); // WORKING, LET'S GOOOOOOOOOOOOO.
        // void searchMovieCleanup(movieNamespace::MovieClass**, std::size_t); // Not working, malloc error?
        tvShowNamespace::TVShowClass** searchTV(std::string); // Complete, untested.
        musicNamespace::MusicClass** searchMusic(std::string); // Complete, untested.

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

        // I UNDERSTAND WHY WE HAVE PRIVATE DATA/FUNCTIONS NOW:
        // I do not want users to access these functions because they could really mess stuff up if they did have access:
        // I (as the programmer) only want the user to use addMovie() (which uses this function safely).
        void _internalAddMovie(movieNamespace::MovieClass*);
        void _internalAddTV(tvShowNamespace::TVShowClass*);
        void _internalAddMusic(musicNamespace::MusicClass*);

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
        _internalAddMovie(tempMovie);
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

        _internalAddTV(tempShow);
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
        _internalAddMusic(tempMusic);
    }
    musicStream.close(); // Music has been loaded.

    std::cout << "All data loaded." << std::endl;
}

// User function that takes in movie input and adds that input to a movieClass,
// the function then adds said movie to _movieArray.
void Database::addMovie()
{
    std::string tempString;
    movieNamespace::MovieClass* userMovie = new movieNamespace::MovieClass;

    std::cout << "\nIMBD ID: ";
    std::cin.ignore(1);
    getline(std::cin, tempString);
    userMovie->setMediaIMDBID(tempString);

    std::cout << "\nMovie Title: ";
    getline(std::cin,tempString);
    userMovie->setMediaTitle(tempString);

    std::cout << "\nMovie Year: ";
    std::cin >> tempString;
    userMovie->setMediaYear(tempString);

    std::cout << "\nMovie Genre: ";
    std::cin.ignore(1);
    getline(std::cin, tempString);
    userMovie->setMediaGenre(tempString);

    std::cout <<"\nMovie Rating (one decimal): ";
    getline(std::cin, tempString);
    userMovie->setRating(tempString);

    std::cout << "\nMovie Director: ";
    getline(std::cin, tempString);
    userMovie->setDirector(tempString);

    Database::_internalAddMovie(userMovie);
}

// User function that takes in TV Show input and adds that input to a TVShow,
// the function then adds said show to _tvShowArray.
void Database::addTVShow()
{
    std::string tempString;
    tvShowNamespace::TVShowClass* userTV = new tvShowNamespace::TVShowClass;

    std::cout << "\nIMBD ID: ";
    std::cin.ignore(1);
    getline(std::cin, tempString);
    userTV->setMediaIMDBID(tempString);

    std::cout << "\nShow Title: ";
    getline(std::cin,tempString);
    userTV->setMediaTitle(tempString);

    std::cout << "\nShow Year: ";
    std::cin >> tempString;
    userTV->setMediaYear(tempString);

    std::cout << "\nShow Genre: ";
    std::cin.ignore(1);
    getline(std::cin, tempString);
    userTV->setMediaGenre(tempString);

    std::cout <<"\nShow Rating (one decimal): ";
    getline(std::cin, tempString);
    userTV->setRating(tempString);

    std::cout << "\nNumber of Episodes: ";
    getline(std::cin, tempString);
    userTV->setNumEpisodes(tempString);

    Database::_internalAddTV(userTV);
}

// User function that takes in movie input and adds that input to a musicClass,
// the function then adds said music to _musicArray.
void Database::addMusic()
{
    std::string tempString;
    musicNamespace::MusicClass* userMusic = new musicNamespace::MusicClass;

    std::cout << "\nIMBD ID: ";
    std::cin.ignore(1);
    std::getline(std::cin, tempString);
    userMusic->setMediaIMDBID(tempString);

    std::cout << "\nMusic Title: ";
    getline(std::cin,tempString);
    userMusic->setMediaTitle(tempString);

    std::cout << "\nRelease Year: ";
    std::cin >> tempString;
    userMusic->setMediaYear(tempString);

    std::cout << "\nGenre: ";
    std::cin.ignore(1);
    getline(std::cin, tempString);
    userMusic->setMediaGenre(tempString);

    std::cout <<"\nComposer: ";
    getline(std::cin, tempString);
    userMusic->setComposer(tempString);

    std::cout << "\nNumber of Tracks: ";
    getline(std::cin, tempString);
    userMusic->setNumTracks(tempString);

    std::cout << "\nTotal Playtime (in seconds): ";
    std::cin >> tempString;
    userMusic->setTotalPlaytime(tempString);

    Database::_internalAddMusic(userMusic);
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
    // std::cout << "Inside Database::displayAllMedia()." << std::endl;

    std::size_t navigationChoice = 0;
    std::cout << "Input 1 to display all info, input 2 to display only media titles: ";
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
        std::cout << "Uh oh, something broke inside Database::displayAllMedia()" << std::endl;
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
        // If the "next member" is nullptr, loop breaks out.
        if ((Database::getMovieArrayAddress(i + 1)) != nullptr)
        {
            movieNamespace::MovieClass* tempMovie = new movieNamespace::MovieClass;

            tempMovie = Database::getMovieArrayAddress(i + 1);

            Database::setMovieArray(tempMovie, i);
        }
    }

    // Decrements _numMovies.
    std::size_t tempNumMovies = (Database::getNumMovies() - 1);
    Database::setNumMovies(tempNumMovies);

    std::cout << "Movie has been removed." << std::endl;
    return Database::getMovieArrayAddress(0);
}

// Function takes in which index you would like to delete.
// Function updates _tvShowArray and returns the updated address to _tvShowArray.
tvShowNamespace::TVShowClass* Database::removeTVShow(std::size_t index)
{
    // EDGE CASE (index == last data member).
    if (index == Database::getNumTVShows())
    {
        Database::setTVArray(nullptr, index);

        // Decrements _numTVShows.
        std::size_t tempNumTVShows = (Database::getNumTVShows() - 1);
        Database::setNumTVShows(tempNumTVShows);

        return Database::getTVShowAddress(0);
    }

    // Sets the index position = nullptr.
    Database::setTVArray(nullptr, index);

    // Loop starts at index and checks if the next object in _tvShowArray is nullptr.
    for (std::size_t i = index; i <= Database::getNumTVShows(); i++)
    {
        // If the "next member" is nullptr, loop will not continue.
        if ((Database::getTVShowAddress(i + 1)) != nullptr)
        {
            tvShowNamespace::TVShowClass* tempTVShow = new tvShowNamespace::TVShowClass;
            tempTVShow = Database::getTVShowAddress(i + 1);

            Database::setTVArray(tempTVShow, i);
        }
    }

    // Decrements _numTVShows.
    std::size_t tempNumTVShows = (Database::getNumTVShows() - 1);
    Database::setNumTVShows(tempNumTVShows);

    std::cout << "Show has been removed." << std::endl;
    return Database::getTVShowAddress(0);
}

// Function takes in which index you would like to delete.
// Function updates _musicArray and returns the updated address to _musicArray.
musicNamespace::MusicClass* Database::removeMusic(std::size_t index)
{
    // Sets the index position = nullptr.
    Database::setMusicArray(nullptr, index);

    // Loop starts at index and checks if the next object in _musicArray is nullptr.
    for (std::size_t i = index; i <= Database::getNumMusicObjects(); i++)
    {
        musicNamespace::MusicClass* tempMusic = new musicNamespace::MusicClass;

        // If the next "member" is nullptr, break out of the loop.
        if ((Database::getMusicArrayAddress(i + 1)) == nullptr)
        {
            break;
        }

        tempMusic = Database::getMusicArrayAddress(i + 1);

        Database::setMusicArray(tempMusic, i);
    }

    // Decrements _numMusicObjects.
    std::size_t tempNumMusicObjects = (Database::getNumMusicObjects() - 1);
    Database::setNumMusicObjects(tempNumMusicObjects);

    std::cout << "Music has been removed." << std::endl;
    return Database::getMusicArrayAddress(0);
}

// Function outputs all data to outputFile.csv.
void Database::outputDatatoCSV()
{
    std::ofstream outputStream;
    outputStream.open("csv_files/outputFile.csv");

    // outputStream << "Testing"; // Puts "Testing" in the first line of the csv file.

    // Outputs movie data to outputFile.csv.    
    for (std::size_t i = 1; i <= Database::getNumMovies(); i++)
    {
        outputStream << Database::getMovieArrayAddress(i)->getMediaId() << ",";
        outputStream << Database::getMovieArrayAddress(i)->getMediaTitle() << ",";
        outputStream << Database::getMovieArrayAddress(i)->getMediaYear() << ",";
        outputStream << Database::getMovieArrayAddress(i)->getMediaGenre() << ",";
        outputStream << Database::getMovieArrayAddress(i)->getRating() << ",";
        outputStream << Database::getMovieArrayAddress(i)->getDirector() << "\n";
    }

    // Output TV shows loop.
    for (std::size_t i = 1; i <= Database::getNumTVShows(); i++)
    {
        outputStream << Database::getTVShowAddress(i)->getMediaId() << ",";
        outputStream << Database::getTVShowAddress(i)->getMediaTitle() << ",";
        outputStream << Database::getTVShowAddress(i)->getMediaYear() << ",";
        outputStream << Database::getTVShowAddress(i)->getMediaGenre() << ",";
        outputStream << Database::getTVShowAddress(i)->getRating() << ",";
        outputStream << Database::getTVShowAddress(i)->getNumEpisodes() << "\n";
    }

    // Output music objects loop.
    for (std::size_t i = 1; i <= Database::getNumMusicObjects(); i++)
    {
        outputStream << Database::getMusicArrayAddress(i)->getMediaId() << ",";
        outputStream << Database::getMusicArrayAddress(i)->getMediaTitle() << ",";
        outputStream << Database::getMusicArrayAddress(i)->getMediaYear() << ",";
        outputStream << Database::getMusicArrayAddress(i)->getMediaGenre() << ",";
        outputStream << Database::getMusicArrayAddress(i)->getComposer() << ",";
        outputStream << Database::getMusicArrayAddress(i)->getNumTracks() << ",";
        outputStream << Database::getMusicArrayAddress(i)->getTotalPlaytime() << "\n";
    }
    outputStream.close();
}

// Function returns a pointer to an array of pointers to movies.
// If nothing is found, function returns an array of nullptrs.
movieNamespace::MovieClass** Database::searchMovie(std::string inputString)
{
    movieNamespace::MovieClass** tempMovieArray = new movieNamespace::MovieClass*[(Database::getNumMovies() + 1)];
    // The above array needs a +1 because of the zero index on arrays. (_numMovies is too large)
    std::size_t tempIndex = 1; // Used for indexing the above array.

    // Populating temp array with all pointers pointing to nullptr.
    for (std::size_t i = 1; i <= Database::getNumMovies(); i++)
    {
        tempMovieArray[i] = nullptr;
    }

    // Loop searches through each Movie Class.
    // Loop converts _year and _rating to strings to be compared to.
    // If a match is found, it is dropped into tempMovieArray.
    for (std::size_t i = 1; i <= Database::getNumMovies(); i++)
    {
        // Converts the two non-string data types to strings so that they can be easily compared to.
        std::string convertedMovieYearInt = std::to_string(Database::getMovieArrayAddress(i)->getMediaYear());
        std::string convertedMovieRatingFloat = std::to_string(Database::getMovieArrayAddress(i)->getRating());

        // Below is required because std::to_string() returns a float that has more than 3 chars in it.
        convertedMovieRatingFloat = convertedMovieRatingFloat.substr(0,3);

        if (inputString == Database::getMovieArrayAddress(i)->getMediaId())
        {
            tempMovieArray[tempIndex] = Database::getMovieArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == Database::getMovieArrayAddress(i)->getMediaTitle())
        {
            tempMovieArray[tempIndex] = Database::getMovieArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedMovieYearInt)
        {
            tempMovieArray[tempIndex] = Database::getMovieArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == Database::getMovieArrayAddress(i)->getMediaGenre())
        {
            tempMovieArray[tempIndex] = Database::getMovieArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedMovieRatingFloat)
        {
            tempMovieArray[tempIndex] = Database::getMovieArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == Database::getMovieArrayAddress(i)->getDirector())
        {
            tempMovieArray[tempIndex] = Database::getMovieArrayAddress(i);
            tempIndex++;
        }
    }

    if (tempMovieArray[1] == nullptr)
    {
        std::cout << "NO RESULTS FOUND." << std::endl;
    }
    
    return tempMovieArray;
}

/*
// NOT WORKING. Malloc error?
void Database::searchMovieCleanup(movieNamespace::MovieClass** inputDoublePointer, std::size_t sizeOfArray)
{
    std::cout << "***DEBUG*** inside searchMovieCleanup." << std::endl;

    // Function starts at the tail of the array and works its way back, deleting each movieClass.
    for (std::size_t i = sizeOfArray; i >= 0; i--)
    {
        delete inputDoublePointer[i];
    }

    std::cout << "***DEBUG*** searchMovie() cleaned up." << std::endl;
}
*/

// I have a strange feeling that all of this copying and pasting is solved through templating.... But I'm a newb.

// Function returns a pointer to an array of pointers to TV Shows.
// If nothing is found, function returns an array of nullptrs.
tvShowNamespace::TVShowClass** Database::searchTV(std::string inputString)
{
    // Temp variables.
    tvShowNamespace::TVShowClass** tempTVArray = new tvShowNamespace::TVShowClass*[(Database::getNumTVShows() + 1)];
    // The above array needs a +1 because I'm a goof and this program isn't 0 indexed.
    std::size_t tempIndex = 1; // Used for indexing the above array.
    // Populating temp array with all pointers pointing to nullptr.
    for (std::size_t i = 1; i <= Database::getNumTVShows(); i++)
    {
        tempTVArray[i] = nullptr;
    }

    // Loop searches through each TV Class.
    // Loop converts _year, _rating, and _numEpisodes to strings to be easily compared to.
    // If a match is found, it is dropped into tempTVArray.
    for (std::size_t i = 1; i <= Database::getNumTVShows(); i++)
    {
        // Converts the three non-string data types to strings so that they can be easily compared to.
        std::string convertedTVYearInt = std::to_string(Database::getTVShowAddress(i)->getMediaYear());
        std::string convertedTVRatingFloat = std::to_string(Database::getTVShowAddress(i)->getRating());
        std::string convertedTVNumEpisodesInt = std::to_string(Database::getTVShowAddress(i)->getNumEpisodes());

        // Below is required because std::to_string() returns a float that has more than 3 chars in it.
        convertedTVRatingFloat = convertedTVRatingFloat.substr(0,3);

        if (inputString == Database::getTVShowAddress(i)->getMediaId())
        {
            tempTVArray[tempIndex] = Database::getTVShowAddress(i);
            tempIndex++;
        }
        else if (inputString == Database::getTVShowAddress(i)->getMediaTitle())
        {
            tempTVArray[tempIndex] = Database::getTVShowAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedTVYearInt)
        {
            tempTVArray[tempIndex] = Database::getTVShowAddress(i);
            tempIndex++;
        }
        else if (inputString == Database::getTVShowAddress(i)->getMediaGenre())
        {
            tempTVArray[tempIndex] = Database::getTVShowAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedTVRatingFloat)
        {
            tempTVArray[tempIndex] = Database::getTVShowAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedTVNumEpisodesInt)
        {
            tempTVArray[tempIndex] = Database::getTVShowAddress(i);
            tempIndex++;
        }
    }

    if (tempTVArray[1] == nullptr)
    {
        std::cout << "NO RESULTS FOUND." << std::endl;
    }
    
    return tempTVArray;
}

// Function returns a pointer to an array of pointers to Music objects.
// If nothing is found, function returns an array of nullptrs.
musicNamespace::MusicClass** Database::searchMusic(std::string inputString)
{
    // Temp variables.
    musicNamespace::MusicClass** tempMusicArray = new musicNamespace::MusicClass*[(Database::getNumMusicObjects() + 1)];
    std::size_t tempIndex = 1; // Used for indexing the above array.
    // Populating temp array with all pointers pointing to nullptr.
    for (std::size_t i = 1; i <= Database::getNumMusicObjects(); i++)
    {
        tempMusicArray[i] = nullptr;
    }

    // Loop searches through each Music Object.
    // Loop converts _year, _numTracks, and _totalPlaytime to strings to be easily compared to.
    // If a match is found, it is dropped into tempMusicArray.
    for (std::size_t i = 1; i <= Database::getNumMusicObjects(); i++)
    {
        // Converts the three non-string data types to strings so that they can be easily compared to.
        std::string convertedMusicYearInt = std::to_string(Database::getMusicArrayAddress(i)->getMediaYear());
        std::string convertedMusicNumTracksInt = std::to_string(Database::getMusicArrayAddress(i)->getNumTracks());
        std::string convertedMusicTotalPlaytimeFloat = std::to_string(Database::getMusicArrayAddress(i)->getTotalPlaytime());

        // Below is required because std::to_string() returns a float that has more than 3 chars in it.
        convertedMusicTotalPlaytimeFloat = convertedMusicTotalPlaytimeFloat.substr(0,3);

        if (inputString == Database::getMusicArrayAddress(i)->getMediaId())
        {
            tempMusicArray[tempIndex] = Database::getMusicArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == Database::getMusicArrayAddress(i)->getMediaTitle())
        {
            tempMusicArray[tempIndex] = Database::getMusicArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedMusicYearInt)
        {
            tempMusicArray[tempIndex] = Database::getMusicArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == Database::getMusicArrayAddress(i)->getMediaGenre())
        {
            tempMusicArray[tempIndex] = Database::getMusicArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedMusicNumTracksInt)
        {
            tempMusicArray[tempIndex] = Database::getMusicArrayAddress(i);
            tempIndex++;
        }
        else if (inputString == convertedMusicTotalPlaytimeFloat)
        {
            tempMusicArray[tempIndex] = Database::getMusicArrayAddress(i);
            tempIndex++;
        }
    }

    if (tempMusicArray[1] == nullptr)
    {
        std::cout << "NO RESULTS FOUND." << std::endl;
    }
    
    return tempMusicArray;
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


// Function returns the address to the requested index.
// Function can also be used the same as Database::getMovieArrayAddress() by returning the 0 index.
movieNamespace::MovieClass* Database::getMovieArrayAddress(std::size_t index)
{
    return _movieArray[index];
}

// Function returns the address of the input index.
tvShowNamespace::TVShowClass* Database::getTVShowAddress(std::size_t index)
{
    return _tvShowArray[index];
}

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


// Private Functions

// Function takes a pointer to a movie and adds it to the end of _movieArray.
// This is the function mediaDatabase uses internally to populate _movieArray.
// The user does not have access to this function.
void Database::_internalAddMovie(movieNamespace::MovieClass* inputMovie)
{
    Database::setMovieArray(inputMovie, (Database::getNumMovies() + 1));
    Database::incrementNumMovies(); // <----- THIS IS THE TROUBLEMAKER (line is not needed).
}

void Database::_internalAddTV(tvShowNamespace::TVShowClass* inputTV)
{
    Database::setTVArray(inputTV, (Database::getNumTVShows() + 1));
    Database::incrementNumTVShows();
}

void Database::_internalAddMusic(musicNamespace::MusicClass* inputMusic)
{
    Database::setMusicArray(inputMusic, (Database::getNumMusicObjects() + 1));
    Database::incrementNumMusicObjects();
}
