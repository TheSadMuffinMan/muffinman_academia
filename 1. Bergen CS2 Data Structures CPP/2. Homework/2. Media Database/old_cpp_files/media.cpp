#include "media.h"

// Virtual inherited function.
void media::MediaClass::displayInfo()
{
    // This is a virtual function to be inheritited.
    std::cout << "IMDB ID: " << getMediaId() << std::endl;
    std::cout << "Movie Title: " << getMediaTitle() << std::endl;
    std::cout << "Release Year: " << getMediaYear() << std::endl;
    std::cout << "Genre: " << getMediaGenre() << std::endl;
}

// Getters

std::string media::MediaClass::getMediaId()
{
    return _mediaID;
}

std::string media::MediaClass::getMediaTitle()
{
    return _mediaTitle;
}

int media::MediaClass::getMediaYear()
{
    return _mediaYear;
}

std::string media::MediaClass::getMediaGenre()
{
    return _mediaGenre;
}


// Setters

void media::MediaClass::setMediaIMDBID(std::string inputID)
{
    _mediaID = inputID;
}

void media::MediaClass::setMediaTitle(std::string inputTitle)
{
    _mediaTitle = inputTitle;
}

void media::MediaClass::setMediaYear(int inputNumber)
{
    _mediaYear = inputNumber;
}

// Overloaded function that takes in a string and converts it to an int.
void media::MediaClass::setMediaYear(std::string inputString)
{
    int tempInt = 0;
    std::istringstream(inputString) >> tempInt;
    _mediaYear = tempInt;
}

void media::MediaClass::setMediaGenre(std::string inputGenre)
{
    _mediaGenre = inputGenre;
}