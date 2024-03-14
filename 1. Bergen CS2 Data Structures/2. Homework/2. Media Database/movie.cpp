#include <movie.h>

// Standard constructor.
movieNamespace::MovieClass::MovieClass()
{
    // Inherited class methodology.
    movieNamespace::MovieClass::setMediaIMDBID("MOVIE");
    movieNamespace::MovieClass::setMediaTitle("MOVIE");
    movieNamespace::MovieClass::setMediaGenre("GENRE");
    movieNamespace::MovieClass::setMediaYear(0000);

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
    float tempFloat = 0.0;
    std::istringstream(inputString) >> tempFloat;
    _rating = tempFloat;
}

void movieNamespace::MovieClass::setDirector(std::string inputString)
{
    _director = inputString;
}