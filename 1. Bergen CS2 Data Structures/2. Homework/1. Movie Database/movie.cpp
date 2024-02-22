#include "movie.h"

namespace movieNamespace
{
    // Default constructor, initializes all values to nullptr and 0 respectively.
    MovieClass::MovieClass()
    {
        MovieClass* newObject = new MovieClass;
        newObject->setIMBDTitleID(nullptr);
        newObject->setMovieTitle(nullptr);
        newObject->setYear(0);
        newObject->setGenre(nullptr);
        newObject->setRating(0.0);
        newObject->setDirector(nullptr);
    }

    MovieClass::~MovieClass()
    {
        std::cout << "MovieClass deconstructor used." << std::endl;
    }

    // Getters
    std::string MovieClass::getIMBDTitleID()
    {
        return _imbdTitleID;
    }

    std::string MovieClass::getMovieTitle()
    {
        return _movieTitle;
    }

    int MovieClass::getYear()
    {
        return _year;
    }

    std::string MovieClass::getGenre()
    {
        return _genre;
    }

    float MovieClass::getRating()
    {
        return _rating;
    }

    std::string MovieClass::getDirector()
    {
        return _director;
    }

    // Setters
    void MovieClass::setIMBDTitleID(std::string desiredTitle)
    {
        _imbdTitleID = desiredTitle;
    }

    void MovieClass::setMovieTitle(std::string desiredTitle)
    {
        _movieTitle = desiredTitle;
    }

    void MovieClass::setYear(int desiredYear)
    {
        _year = desiredYear;
    }

    void MovieClass::setGenre(std::string desiredGenre)
    {
        _genre = desiredGenre;
    }

    void MovieClass::setRating(float desiredRating)
    {
        _rating = desiredRating;
    }

    void MovieClass::setDirector(std::string desiredDirector)
    {
        _director = desiredDirector;
    }
}