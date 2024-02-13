#include "movie.h"

namespace movieNamespace
{
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

    int MovieClass::getRating()
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

    void MovieClass::getMovieTitle(std::string desiredTitle)
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

    void MovieClass::setRating(int desiredRating)
    {
        _rating = desiredRating;
    }

    void MovieClass::setDirector(std::string desiredDirector)
    {
        _director = desiredDirector;
    }
}