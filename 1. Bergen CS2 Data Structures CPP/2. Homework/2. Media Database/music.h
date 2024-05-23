#pragma once

#include "media.h"
#include "iostream"
#include "sstream"

namespace musicNamespace
{
    class MusicClass: public media::MediaClass
    {
        public:
            MusicClass();
            ~MusicClass();

            // Virtual inherited function.
            void displayInfo();


            // Native Getters

            std::string getComposer();
            std::size_t getNumTracks();
            float getTotalPlaytime();


            // Native Setters

            void setComposer(std::string);
            void setNumTracks(int);
            void setNumTracks(std::string); // Special overloaded function.
            void setTotalPlaytime(float);
            void setTotalPlaytime(std::string); // Special overloaded function.

        private:
            std::string _composer;
            int _numTracks;
            float _totalPlaytime; // In seconds.
    };
}


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
    int tempInt = 0;
    std::istringstream(inputString) >> tempInt;
    _numTracks = tempInt;
}

void musicNamespace::MusicClass::setTotalPlaytime(float inputNum)
{
    _totalPlaytime = inputNum;
}

// Overloaded function that accepts a string and converts it to a float.
void musicNamespace::MusicClass::setTotalPlaytime(std::string inputString)
{
    float tempFloat = 0.0;
    std::istringstream(inputString) >> tempFloat;
    _totalPlaytime = tempFloat;
}