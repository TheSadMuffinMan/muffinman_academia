#include <movie.h>

// Standard constructor.
movieNamespace::MovieClass::MovieClass()
{
    // Inherited class methodology.
    movieNamespace::MovieClass::MediaClass::setMediaIMDBID("MOVIE");
    movieNamespace::MovieClass::MediaClass::setMediaTitle("MOVIE");
    movieNamespace::MovieClass::MediaClass::setMediaGenre("GENRE");
    movieNamespace::MovieClass::MediaClass::setMediaYear(0000);

    _rating = 0.0;
    _director = "MOVIE DIRECTOR";
}

// Standard destructor.
movieNamespace::MovieClass::~MovieClass()
{
    //
}

void movieNamespace::MovieClass::displayInfo()
{
    media::MediaClass::displayInfo();
    std::cout << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Director: " << getDirector() << std::endl;
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