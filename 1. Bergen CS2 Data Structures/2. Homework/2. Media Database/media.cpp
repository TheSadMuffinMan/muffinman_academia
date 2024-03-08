#include <media.h>

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