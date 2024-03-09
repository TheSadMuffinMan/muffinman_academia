#include <music.h>

// Default constructor.
musicNamespace::MusicClass::MusicClass()
{
    //
}

musicNamespace::MusicClass::~MusicClass()
{
    //
}

void musicNamespace::MusicClass::MediaClass::displayInfo()
{
    //
}


// Native Getters.
std::string musicNamespace::MusicClass::getComposer()
{
    return _composer;
}

std::size_t musicNamespace::MusicClass::getNumTracks()
{
    return _numTracks;
}

float musicNamespace::MusicClass::getTotalPlaytime()
{
    return _totalPlaytime;
}


// Native Setters.
void musicNamespace::MusicClass::setComposer(std::string inputString)
{
    _composer = inputString;
}

void musicNamespace::MusicClass::setNumTracks(int inputNum)
{
    _numTracks = inputNum;
}

// Overloaded function that accepts a string and converts it to an int.
void musicNamespace::MusicClass::setNumTracks(std::string inputString)
{
    //
}

void musicNamespace::MusicClass::setTotalPlaytime(float inputNum)
{
    _totalPlaytime = inputNum;
}

// Overloaded function that accepts a string and converts it to a float.
void musicNamespace::MusicClass::setTotalPlaytime(std::string inputString)
{
    //
}
