#include "movie.h"

namespace movieNamespace
{
    // Default constructor, initializes all values to nullptr and 0 respectively.
    MovieClass::MovieClass()
    {
        std::cout << "MovieClass() Constructor utilized." << std::endl;
    }

    MovieClass::~MovieClass()
    {
        std::cout << "~MovieClass() deconstructor used." << std::endl;
    }

    // Method sets takes all data members as strings, converts them back, and sets the values.
    MovieClass::MovieClass(std::string inputIMBDTitle, std::string inputMovieTitle, int inputYear, 
     std::string inputGenre, float inputRating, std::string inputDirector)
    {
        MovieClass::setIMBDTitleID(inputIMBDTitle);
        MovieClass::setMovieTitle(inputMovieTitle);
        MovieClass::setYear(inputYear);
        MovieClass::setGenre(inputGenre);
        MovieClass::setRating(inputRating);
        MovieClass::setMovieTitle(inputDirector);
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

    void MovieClass::setYear(std::string desiredYear)
    {
        int tempString;
        std::istringstream(desiredYear) >> tempString;
        _year = tempString;
        // See setRating(std::string) setter for another way to accomplish this.
    }

    void MovieClass::setGenre(std::string desiredGenre)
    {
        _genre = desiredGenre;
    }

    void MovieClass::setRating(float desiredRating)
    {
        _rating = desiredRating;
    }

    void MovieClass::setRating(std::string desiredRating)
    {
        float tempVar = stol(desiredRating);
        _rating = tempVar;
    }

    void MovieClass::setDirector(std::string desiredDirector)
    {
        _director = desiredDirector;
    }
}