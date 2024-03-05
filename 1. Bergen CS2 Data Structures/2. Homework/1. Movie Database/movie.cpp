#include "movie.h"

namespace movieNamespace
{
    // Default constructor, initializes all values to nullptr and 0 respectively.
    MovieClass::MovieClass()
    {
        // std::cout << "MovieClass() Constructor utilized." << std::endl;
        // _imbdTitleID = nullptr;
        // _movieTitle = nullptr;
        // _year = nullptr;
        // _genre = nullptr;
        // _rating = nullptr;
        // _director = nullptr;
    }

    MovieClass::~MovieClass()
    {
        // std::cout << "~MovieClass() deconstructor used." << std::endl;
    }


    // Getters
    std::string* MovieClass::getIMBDTitleID()
    {
        return _imbdTitleID;
    }

    std::string* MovieClass::getMovieTitle()
    {
        return _movieTitle;
    }

    int* MovieClass::getYear()
    {
        return _year;
    }

    std::string* MovieClass::getGenre()
    {
        return _genre;
    }

    float* MovieClass::getRating()
    {
        return _rating;
    }

    std::string* MovieClass::getDirector()
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

    void MovieClass::setYear(int* desiredYear)
    {
        _year = desiredYear;
    }

    // Function is passed in a string*
    // Function converts string* to an int*
    // Function sets int* _year.
    void MovieClass::setYear(std::string* desiredYear)
    {
        int* tempInt;
        std::istringstream(*desiredYear) >> *tempInt;
        _year = tempInt;
    }

    void MovieClass::setGenre(std::string* desiredGenre)
    {
        _genre = desiredGenre;
    }

    void MovieClass::setRating(float* desiredRating)
    {
        _rating = desiredRating;
    }

    void MovieClass::setRating(std::string* desiredRating)
    {
        float* tempFloat;
        std::istringstream(*desiredRating) >> *tempFloat;
        _rating = tempFloat;
    }

    void MovieClass::setDirector(std::string* desiredDirector)
    {
        _director = desiredDirector;
    }
}