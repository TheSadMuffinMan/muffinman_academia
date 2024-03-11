#include <media.h>

void media::MediaClass::displayInfo()
{
    // This is a virtual function to be inheritited.
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

void media::MediaClass::setMediaGenre(std::string inputGenre)
{
    _mediaGenre = inputGenre;
}