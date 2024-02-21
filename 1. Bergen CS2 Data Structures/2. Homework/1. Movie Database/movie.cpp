#include "movie.h"

namespace movieNamespace
{
    std::string* MovieClass::getIMBDTitleIDPointer()
    {
        return _imbdTitleID;
    }

    std::string* MovieClass::getMovieTitlePointer()
    {
        return _movieTitle;
    }

    int* MovieClass::getYearPointer()
    {
        return _year;
    }

    std::string* MovieClass::getGenrePointer()
    {
        return _genre;
    }

    int* MovieClass::getRatingPointer()
    {
        return _rating;
    }

    std::string* MovieClass::getDirectorPointer()
    {
        return _director;
    }

    // Setters
    void MovieClass::setIMBDTitleID(std::string* desiredTitle)
    {
        _imbdTitleID = desiredTitle;
    }

    void MovieClass::setMovieTitle(std::string* desiredTitle)
    {
        _movieTitle = desiredTitle;
    }

    void MovieClass::setYear(int *desiredYear)
    {
        _year = desiredYear;
    }

    void MovieClass::setGenre(std::string* desiredGenre)
    {
        _genre = desiredGenre;
    }

    void MovieClass::setRating(int *desiredRating)
    {
        _rating = desiredRating;
    }

    void MovieClass::setDirector(std::string* desiredDirector)
    {
        _director = desiredDirector;
    }
}