#include <tvshows.h>

// Default Constructor.
tvShowNamespace::TVShowClass::TVShowClass()
{
    //
}

// Deconstructor.
tvShowNamespace::TVShowClass::~TVShowClass()
{
    //
}

// Virtual function.
void tvShowNamespace::TVShowClass::MediaClass::displayInfo()
{
    //
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
void tvShowNamespace::TVShowClass::setRating(std::string inputRating)
{
    //
}

// Regular/Non-overloaded function.
void tvShowNamespace::TVShowClass::setNumEpisodes(int inputInt)
{
    _numEpisodes = inputInt;
}

// Overloaded function that accepts a string and converts it to an int.
void tvShowNamespace::TVShowClass::setNumEpisodes(std::string inputString)
{
    //
}