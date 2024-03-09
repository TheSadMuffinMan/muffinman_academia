#include <tvshows.h>

// Default Constructor.
tvShows::TVShow::TVShow()
{
    //
}

// Deconstructor.
tvShows::TVShow::~TVShow()
{
    //
}

// Virtual function.
void tvShows::TVShow::MediaClass::displayInfo()
{
    //
}

// Native Getters.
float tvShows::TVShow::getRating()
{
    //
}

int tvShows::TVShow::getNumEpisodes()
{
    //
}


// Native Setters
void tvShows::TVShow::setRating(float inputRating)
{
    //
}

// Overloaded setRating function that accepts a string and converts it to a float.
void tvShows::TVShow::setRating(std::string inputRating)
{
    //
}

// Regular/Non-overloaded function.
void tvShows::TVShow::setNumEpisodes(int inputNumEpisodes)
{
    //
}

// Overloaded function that accepts a string and converts it to an int.
void tvShows::TVShow::setNumEpisodes(std::string inputNumEpisodes)
{

}