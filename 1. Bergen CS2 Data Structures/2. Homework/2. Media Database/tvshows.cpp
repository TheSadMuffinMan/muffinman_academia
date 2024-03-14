#include <tvshows.h>

// Default Constructor.
tvShowNamespace::TVShowClass::TVShowClass()
{
    // Inherited class methodology.
    tvShowNamespace::TVShowClass::setMediaIMDBID("TV_SHOW");
    tvShowNamespace::TVShowClass::setMediaTitle("TV_SHOW");
    tvShowNamespace::TVShowClass::setMediaGenre("TV_GENRE");
    tvShowNamespace::TVShowClass::setMediaYear(0000);

    _rating = 0.0;
    _numEpisodes = 0;
}

// Deconstructor.
tvShowNamespace::TVShowClass::~TVShowClass()
{
    //
}

// Virtual inherited function.
void tvShowNamespace::TVShowClass::displayInfo()
{
    media::MediaClass::displayInfo();
    std::cout << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Number of Episodes: " << getNumEpisodes() << std::endl;
}


// Native Getters.

float tvShowNamespace::TVShowClass::getRating()
{
    return _rating;
}

int tvShowNamespace::TVShowClass::getNumEpisodes()
{
    return _numEpisodes;
}


// Native Setters

void tvShowNamespace::TVShowClass::setRating(float inputFloat)
{
    _rating = inputFloat;
}

// Overloaded setRating function that accepts a string and converts it to a float.
void tvShowNamespace::TVShowClass::setRating(std::string inputString)
{
    float tempFloat = 0.0;
    std::istringstream(inputString) >> tempFloat;
    _rating = tempFloat;
}

// Regular/Non-overloaded function.
void tvShowNamespace::TVShowClass::setNumEpisodes(int inputInt)
{
    _numEpisodes = inputInt;
}

// Overloaded function that accepts a string and converts it to an int.
void tvShowNamespace::TVShowClass::setNumEpisodes(std::string inputString)
{
    int tempInt = 0;
    std::istringstream(inputString) >> tempInt;
    _numEpisodes = tempInt;
}