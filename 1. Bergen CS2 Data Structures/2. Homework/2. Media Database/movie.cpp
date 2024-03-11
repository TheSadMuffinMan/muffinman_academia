#include <movie.h>

// Standard constructor.
movieNamespace::MovieClass::MovieClass()
{
    // Inherited class methodology.
    movieNamespace::MovieClass::MediaClass::setMediaIMDBID("MOVIE");
    movieNamespace::MovieClass::MediaClass::setMediaTitle("MOVIE");
    movieNamespace::MovieClass::MediaClass::setMediaGenre("GENRE");
    movieNamespace::MovieClass::MediaClass::setMediaYear(0000);

    
}

// Standard destructor.
movieNamespace::MovieClass::~MovieClass()
{
    //
}

void movieNamespace::MovieClass::MediaClass::displayInfo()
{
    //
}


// Native Getters
float movieNamespace::MovieClass::getRating()
{
    return _rating;
}

std::string movieNamespace::MovieClass::getDirector()
{
    return _director;
}


// Native Setters
void movieNamespace::MovieClass::setRating(float inputFloat)
{
    _rating = inputFloat;
}

// Overloaded special function.
void movieNamespace::MovieClass::setRating(std::string inputString)
{
    //
}

void movieNamespace::MovieClass::setDirector(std::string inputString)
{
    _director = inputString;
}