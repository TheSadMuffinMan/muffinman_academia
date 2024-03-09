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
    //
}

int tvShowNamespace::TVShowClass::getNumEpisodes()
{
    //
}


// Native Setters
void tvShowNamespace::TVShowClass::setRating(float inputRating)
{
    //
}

// Overloaded setRating function that accepts a string and converts it to a float.
void tvShowNamespace::TVShowClass::setRating(std::string inputRating)
{
    //
}

// Regular/Non-overloaded function.
void tvShowNamespace::TVShowClass::setNumEpisodes(int inputNumEpisodes)
{
    //
}

// Overloaded function that accepts a string and converts it to an int.
void tvShowNamespace::TVShowClass::setNumEpisodes(std::string inputNumEpisodes)
{
    //
}