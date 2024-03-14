#include <music.h>

// Default constructor.
musicNamespace::MusicClass::MusicClass()
{
    // Inherited class methodology.
    musicNamespace::MusicClass::setMediaIMDBID("MUSIC");
    musicNamespace::MusicClass::setMediaTitle("MUSIC_TITLE");
    musicNamespace::MusicClass::setMediaGenre("MUSIC_GENRE");
    musicNamespace::MusicClass::setMediaYear(0000);

    _composer = "MUSIC_COMPOSER";
    _numTracks = 0;
    _totalPlaytime = 0.0;
}

musicNamespace::MusicClass::~MusicClass()
{
    //
}

void musicNamespace::MusicClass::displayInfo()
{
    media::MediaClass::displayInfo();
    std::cout << std::endl;
    std::cout << "Composer: " << getComposer() << std::endl;
    std::cout << "Number of Tracks: " << getNumTracks() << std::endl;
    std::cout << "Total Playtime: " << getTotalPlaytime() << std::endl;
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
