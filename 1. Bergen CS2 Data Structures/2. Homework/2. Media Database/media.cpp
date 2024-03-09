#include <media.h>

void media::MediaClass::displayAllInfo()
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

std::string media::MediaClass::getGenre()
{
    return _mediaGenre;
}


// Setters
void media::MediaClass::setMediaID(std::string inputID)
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

void media::MediaClass::setGenre(std::string inputGenre)
{
    _mediaGenre = inputGenre;
}